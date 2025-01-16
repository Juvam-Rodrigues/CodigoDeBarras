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
    for (int i = 0; i < argc; i++)
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
    int **matrizLeitor;

    fscanf(arquivo, "%d %d", &largura, &altura);
    matrizLeitor = malloc(sizeof(int*) * altura);
    for(int i = 0; i < altura; i++){
      matrizLeitor[i] = malloc(sizeof(int)*largura);
    }

    //Ler matriz da .PBM para a imagem
    for(int i = 0; i < altura; i++){
      for(int j = 0; j < largura; j++){
        fscanf(arquivo, "%d", &matrizLeitor[i][j]);
      }
    }

    fclose(arquivo);

    // Encontrar o marcador inicial
    int linhaInicial, colunaInicial, contadorArea = 0;

    for(int i = altura/2; i < altura; i++){
      for(int j = 0; j < largura; j++){
        if(matrizLeitor[i][j] == 1){
          linhaInicial = i;
          colunaInicial = j;
          break;
        }
      }
    }

    for(int i = colunaInicial; i< largura; i++){ // Encontrando área
      if(matrizLeitor[linhaInicial][i] == 1){
        contadorArea++;
      }
      else{
        break;
      }
    }
    Codigo codidoLeitor;
    int contador = 0;
    for(int j = colunaInicial; contador<67; j+= contadorArea){ // Encontrando área
        codidoLeitor.codigo[contador] = matrizLeitor[linhaInicial][j] + '0';
        contador++;
    }
    
    //printf opicioanl teste
    for(int j = 0; j < 67; j++){ // Encontrando área
        printf("%c", codidoLeitor.codigo[j]);
    }


    printf("%s", leitor.nome);
}