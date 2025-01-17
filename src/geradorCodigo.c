#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/tabela.h"
#include "../include/codigo.h"
#include "../include/arquivo.h"

int verificarSobrescrever(Arquivo arq)
{
    FILE *arquivo = fopen(strcat(arq.nome, ".pbm"), "r");

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

int main(int argc, char *argv[])
{
    Codigo codigoBarra;
    codigoBarra.altura = 50;            // Altura padrão
    codigoBarra.espacamentoLateral = 2; // Largura padrão
    codigoBarra.area = 1;               // Área padrão

    // Geração de arquivo
    Arquivo arquivo;
    strcpy(arquivo.nome, "codigodebarra");

    int digitoVerificadorCalculado, digitoVerificadorDigitado;

    // Entrada com argc e v
    for (int i = 1; i < argc; i++)
    {
        int n = atoi(argv[i]);
        switch (i)
        {
        case 1:
            strcpy(codigoBarra.identificador, argv[i]);
            break;
        case 2:
            if (n != 0)
            {
                codigoBarra.espacamentoLateral = n;
            }
            break;
        case 3:
            if (n != 0)
            {
                codigoBarra.area = n;
            }
            break;
        case 4:
            if (n != 0)
            {
                codigoBarra.altura = n;
            }
            break;
        case 5:
            strcpy(arquivo.nome, argv[5]);
            break;
        default:
            break;
        }
    }

    // Verifica se possui os 8 dígitos
    if (strlen(codigoBarra.identificador) != 8 || codigoBarra.identificador[7] == '\n')
    {
        printf("Erro! Não possui 8 dígitos.\n");
        return 1; // Para
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

    // Verifica se o dígito final atende ao cálculo
    digitoVerificadorCalculado = calcularDigitoVerificador(&codigoBarra);
    digitoVerificadorDigitado = codigoBarra.identificador[7] - '0'; // Converte para número
    if (digitoVerificadorCalculado != digitoVerificadorDigitado)
    {
        printf("Erro! O dígito verificador é inválido.\n");
        return 1;
    }

    // Deu tudo certo nas verificações, logo, gera o binário
    gerarCodigoDeBarras(&codigoBarra); // Mandando o objeto para ser gerado o binário

    // Criar matriz
    int **codBarra;

    int alturaTotal = codigoBarra.altura + 2 * codigoBarra.espacamentoLateral;
    int larguraTotal = (67 * codigoBarra.area) + 2 * (codigoBarra.espacamentoLateral);

    codBarra = malloc(sizeof(int *) * alturaTotal); // Criação da matriz
    for (int i = 0; i < alturaTotal; i++)
    {
        codBarra[i] = malloc(sizeof(int) * larguraTotal);
    }

    for (int i = 0; i < alturaTotal; i++)
    { // Preenche tudo com 0
        for (int j = 0; j < larguraTotal; j++)
        {
            codBarra[i][j] = 0;
        }
    }

    // Preencher matriz com código
    int espacamentoProlongado = codigoBarra.espacamentoLateral;
    int larguraInterna = larguraTotal - espacamentoProlongado;

    int alturaInterna = alturaTotal - espacamentoProlongado;

    int contador = 0;

    for (int i = espacamentoProlongado; i < alturaInterna; i++)
    {

        for (int j = espacamentoProlongado;
             j < larguraInterna; j += codigoBarra.area)
        {
            for (int k = 0; k < codigoBarra.area; k++)
            {
                codBarra[i][j + k] = codigoBarra.codigo[contador] - '0';
            }
            contador++;
        }
        contador = 0;
    }

    // Verifica se o arquivo já existe
    int respostaSobrescrita = verificarSobrescrever(arquivo);

    // Caso deseja sobrescrever ou não exista
    if (respostaSobrescrita == 1)
    {
        FILE *arquivoGerado = fopen(strcat(arquivo.nome, ".pbm"), "w"); // Abre um novo arquivo para escrita
        fprintf(arquivoGerado, "P1\n%d %d\n", larguraTotal, alturaTotal);
        for (int i = 0; i < alturaTotal; i++)
        {
            for (int j = 0; j < larguraTotal; j++)
            {
                fprintf(arquivoGerado, "%d", codBarra[i][j]);
            }
            fprintf(arquivoGerado, "\n");
        }

        // Liberação adequada de memória

        for (int i = 0; i < alturaTotal; i++)
        {
            free(codBarra[i]);
        }
        free(codBarra);

        //Fecha o arquivo
        fclose(arquivoGerado);
    }
    else
    {
        return 1;
    }
}