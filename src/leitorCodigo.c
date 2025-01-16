#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/tabela.h"
#include "../include/codigo.h"
#include "../include/arquivo.h"

int main(int argc, char **argv)
{
    Arquivo leitor;
    for (int i = 1; i < argc; i++)
    {
        switch (i)
        {
        case 1:
            strcpy(leitor.nome, argv[1]);
            break;
        default:
            break;
        }
    }

    FILE *arquivo = fopen(strcat(leitor.nome, ".pbm"), "r");
    if (arquivo == NULL)
    {
        printf("Arquivo não existe.");
        return 1;
    }

    char formato[3];
    fscanf(arquivo, "%2s", formato);

    if (formato[0] != 'P' || formato[1] != '1')
    {
        printf("O arquivo não está no formato PBM.");
        return 1;
    }

    int largura, altura;
    char **imagem;

    fscanf(arquivo, "%d %d", largura, altura);
    *imagem = (int *)malloc((largura) * (altura) * sizeof(int));
    if (!*imagem)
    {
        perror("Erro ao alocar memória para a imagem");
        fclose(arquivo);
        exit(1);
    }

    printf("%s", leitor.nome);
}