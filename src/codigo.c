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