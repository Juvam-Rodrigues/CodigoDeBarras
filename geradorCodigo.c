#include <stdio.h>
#include <string.h>

int main()
{
    char idenficadores[9] = {0}; // Inclui o caractere nulo no fim

    fgets(idenficadores, 9, stdin);

    if (strlen(idenficadores) != 8)
    {
        printf("Erro! Não possui 8 dígitos.\n");
    }

    printf("%d\n", strlen(idenficadores));

    for (int i = 0; i < 8; i++)
    {
        printf("%c\n", idenficadores[i]);
    }
}