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