#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tabela.h"
#include "codigo.h"

int main()
{
    Codigo codigoBarra;
    codigoBarra.altura = 50; // Altura padrão
    codigoBarra.largura = 2; // Largura padrão

    int digitoVerificadorCalculado, digitoVerificadorDigitado;

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
    }
}