#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tabela.h"

int main()
{
    char idenficadores[9] = {0}; // Inclui o caractere nulo no fim
    int digitoVerificadorCalculado, digitoVerificadorDigitado;
    fgets(idenficadores, 9, stdin);

    if (strlen(idenficadores) != 8)
    {
        printf("Erro! Não possui 8 dígitos.\n");
        return 1; // para
    }

    // Verifica se todos os caracteres são numéricos
    for (int i = 0; i < 8; i++)
    {
        if (!isdigit(idenficadores[i]))
        {
            printf("Erro! O identificador contém caracteres não numéricos.\n");
            return 1; // para
        }
    }

    digitoVerificadorCalculado = calcularDigitoVerificador(idenficadores);
    digitoVerificadorDigitado = idenficadores[7] - '0'; // Converte para número
    
    printf("%d\n", digitoVerificadorCalculado);
    printf("%d\n", digitoVerificadorDigitado);

}