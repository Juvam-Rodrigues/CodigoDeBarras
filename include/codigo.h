#ifndef CODIGO_H
#define CODIGO_H

typedef struct codigo
{
    char identificador[9]; // Identificador original (8 dígitos + caractere nulo)
    char codigo[100];      // Sequência binária gerada para o código de barras
    int espacamentoLateral;  //Em pixels
    int altura;            // Altura do código de barras (em pixels)
    int area; //Quanto cada barra vai ocupar
} Codigo;

void gerarCodigoDeBarras(Codigo *codigoBarra);
int decodificarCodigoBinario(Codigo *codigoBarra);

int calcularDigitoVerificador(Codigo *codigo);

#endif