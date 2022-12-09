#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *x;
  int tamVetor;

  printf("Digite o tamanho do vetor que você quer criar: ");
  scanf("%d", &tamVetor);
  
  x = (int*) malloc(sizeof(int) * tamVetor);
}