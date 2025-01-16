#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/tabela.h"
#include "../include/codigo.h"
#include "../include/arquivo.h"

int main(int argc, char **argv){
  Arquivo leitor;
  for(int i = 1; i < argc; i++){
      switch (i)
      {
      case 1:
          strcpy(leitor.nome, argv[1]);
        break;
      default:
        break;
      }
  }
  printf("%s", leitor.nome);

}