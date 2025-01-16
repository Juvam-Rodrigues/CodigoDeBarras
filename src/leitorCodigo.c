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
            strcpy(leitor.nome, argv[i]);
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

    fscanf(arquivo, "%d %d", &largura, &altura);

    char **matrizLeitor = malloc(sizeof(char *) * altura);
    for(int i = 0; i < altura; i++){
      matrizLeitor[i] = malloc(sizeof(char) * largura);
    }
    
    //Ler matriz da .PBM para a imagem
    for(int i = 0; i < altura; i++){
      for(int j = 0; j < largura; j++){
        do {
          fscanf(arquivo, "%c", &matrizLeitor[i][j]);
          } while (matrizLeitor[i][j] != '0' && matrizLeitor[i][j] != '1' && j < largura);
      }
    }

    /*for(int i = 0; i < altura; i++){ // teste
      for(int j = 0; j < largura; j++){
        printf("%c", matrizLeitor[i][j]);
      }
      printf("\n");
    }*/

    fclose(arquivo);

    // Encontrar o marcador inicial
    int linhaInicial = -1, colunaInicial = -1, contadorArea = 0;

    for(int i = 0; i < altura; i++){
      for(int j = 0; j < largura; j++){
        if(matrizLeitor[i][j] == '1'){
          linhaInicial = i;
          colunaInicial = j;
          break;
        }
        if(linhaInicial != -1) break;
      }
      if(linhaInicial != -1) break;
    }
    //printf("\n%d %d\n", linhaInicial, colunaInicial);
    for(int i = colunaInicial; i< largura; i++){ // Encontrando área
      if(matrizLeitor[linhaInicial][i] == '1'){
        contadorArea++;
      }
      else{
        break;
      }
    }
    //printf("%d\n", contadorArea);
    
    Codigo codidoLeitor;
    int contador = 0;
    for(int j = colunaInicial; contador<67; j= j + contadorArea){ // Encontrando área
        codidoLeitor.codigo[contador] = matrizLeitor[linhaInicial][j];
        contador++;
    }
    
    decodificarCodigoBinario(&codidoLeitor);

    //printf opicioanl teste
    /*for(int j = 0; j < 67; j++){ // Encontrando área
        printf("%c", codidoLeitor.codigo[j]);
    }*/


    //printf("\n%s", leitor.nome);
}