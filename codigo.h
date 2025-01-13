#ifndef CODIGO_H
#define CODIGO_H

typedef struct codigo
{
    char identificador[9]; // Identificador original (8 dígitos + caractere nulo)
    char codigo[100];      // Sequência binária gerada para o código de barras
    int largura;           // Largura de cada barra (em pixels)
    int altura;            // Altura do código de barras (em pixels)
} Codigo;

void gerarCodigoDeBarras(Codigo *codigoBarra);

#endif