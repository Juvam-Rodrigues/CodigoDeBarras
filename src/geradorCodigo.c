#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/tabela.h"
#include "../include/codigo.h"
#include "../include/arquivo.h"

int verificarSobrescrever(Arquivo arq)
{
    FILE *arquivo = fopen(strcat(arq.nome, ".txt"), "r");

    if (arquivo != NULL)
    {
        // O arquivo existe
        fclose(arquivo);
        char resposta;

        printf("O arquivo \"%s\" já existe. Deseja sobrescrevê-lo? (s/n): ", arq.nome);
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S')
        {
            return 1; // Permitir sobrescrever
        }
        else
        {
            printf("Erro: arquivo resultante já existe.\n");
            return 0; // Não sobrescrever
        }
    }
    else
    {
        // O arquivo não existe
        return 1; // Permitir criar o arquivo
    }
}

int main()
{
    Codigo codigoBarra;
    codigoBarra.altura = 50;            // Altura padrão
    codigoBarra.espacamentoLateral = 2; // Largura padrão
    codigoBarra.area = 1;               // Área padrão

    int digitoVerificadorCalculado, digitoVerificadorDigitado;

    printf("Digite o código:\n");
    fgets(codigoBarra.identificador, 9, stdin); // Entrada

    if (strlen(codigoBarra.identificador) != 8 || codigoBarra.identificador[7] == '\n')
    {
        printf("Erro! Não possui 8 dígitos.\n");
        return 1; // para
    }

    // Verifica se todos os caracteres são numéricos
    for (int i = 0; i < 8; i++)
    {
        if (!isdigit(codigoBarra.identificador[i]))
        {
            printf("Erro! O identificador contém caracteres não numéricos.\n");
            return 1; // para
        }
    }

    digitoVerificadorCalculado = calcularDigitoVerificador(&codigoBarra);
    digitoVerificadorDigitado = codigoBarra.identificador[7] - '0'; // Converte para número

    if (digitoVerificadorCalculado != digitoVerificadorDigitado)
    {
        printf("Erro! O dígito verificador é inválido.\n");
        return 1;
    }

    // Deu tudo certo nas verificações, logo, gera o binário
    gerarCodigoDeBarras(&codigoBarra); // Mandando o objeto para ser gerado o binário

    // Geração de arquivo
    Arquivo arquivo;
    strcpy(arquivo.nome, "codigodebarra"); //Nome padrão

    printf("Digite o nome do arquivo:\n");
    scanf("%s", arquivo.nome);

    int respostaSobrescrita = verificarSobrescrever(arquivo);

    if (respostaSobrescrita == 1)
    {
        FILE *arquivoGerado = fopen(strcat(arquivo.nome, ".pbm"), "w"); // Abre um novo arquivo para escrita
        for (int i = 0; i < strlen(codigoBarra.codigo); i++)
        {
            fprintf(arquivoGerado, "%c", codigoBarra.codigo[i]);
        }
        fclose(arquivoGerado);
    }
    else
    {
        return 1;
    }
}