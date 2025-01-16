#include "../include/codigo.h"
#include "../include/tabela.h"
#include <stdio.h>
#include <string.h>

int calcularDigitoVerificador(Codigo *codigo)
{
    int soma = 0;
    int tamanho = strlen(codigo->identificador);
    for (int i = 0; i < tamanho - 1; i++) // pega até o sétimo digito
    {

        int digito = codigo->identificador[i] - '0'; // Converte o caractere para número

        if (i % 2 == 0)
        { // Vai pegar os números na posição impar
            soma += digito * 3;
        }
        else
        { // Posição pares
            soma += digito;
        }
    }
    int digitoVerificador = (10 - (soma % 10)) % 10; // Garante múltiplo de 10
    return digitoVerificador;
}

void gerarCodigoDeBarras(Codigo *cb)
{
    char binario[100] = {0};    // String para armazenar a sequência binária
    strcat(binario, inicio[0]); // Adiciona o padrão de início

    // Codifica os primeiros 4 dígitos usando a tabela leftCode
    for (int i = 0; i < 4; i++)
    {
        int digito = cb->identificador[i] - '0'; // Converte o caractere para número
        strcat(binario, leftCode[digito]);
    }

    strcat(binario, centro[0]); // Adiciona o padrão de meio

    // Codifica os últimos 4 dígitos usando a tabela rightCode
    for (int i = 4; i < 8; i++)
    {
        int digito = cb->identificador[i] - '0'; // Converte o caractere para número
        strcat(binario, rightCode[digito]);
    }

    strcat(binario, final[0]); // Adiciona o padrão de fim

    // Copia a sequência binária gerada para o struct
    strcpy(cb->codigo, binario);
}

void decodificarCodigoBinario(Codigo *cb)
{
    char *binario = cb->codigo;
    char identificador[9] = {0};

    // Avança o ponteiro após o padrão de início
    binario += strlen(inicio[0]);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++) // Procura no leftCode
        {
            if (strncmp(binario, leftCode[j], strlen(leftCode[j])) == 0)
            {
                identificador[i] = j + '0';     // Adiciona o dígito encontrado
                binario += strlen(leftCode[j]); // Move o ponteiro na sequência binária
                break;
            }
        }
    }

    // Avança o ponteiro após o padrão de meio
    binario += strlen(centro[0]);

    // Decodifica os últimos 4 dígitos usando a tabela rightCode
    for (int i = 4; i < 8; i++)
    {
        for (int j = 0; j < 10; j++) // Procura no rightCode
        {
            if (strncmp(binario, rightCode[j], strlen(rightCode[j])) == 0)
            {
                identificador[i] = j + '0';      // Adiciona o dígito encontrado
                binario += strlen(rightCode[j]); // Move o ponteiro na sequência binária
                break;
            }
        }
    }

    strcpy(cb->identificador, identificador);
    
    //Impressão do código identificador
    for(int i = 0; i < strlen(cb->identificador); i++){
        printf("%c", cb->identificador[i]);
    }
}