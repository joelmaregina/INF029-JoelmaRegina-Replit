// 01. Crie um programa que defina variáveis do tipo int, char, string [10 posições], float, double.
// Deve ser definido também uma variável ponteiro para cada um dos tipos acima.
// Faça leituras (scanf) e escrita (printf) das variáveis primitivas e depois faça o mesmo utilizando ponteiros
#include <stdio.h>

int main()
{
  int inteiro;
  char caracter;
  char string[10];
  float decimal;
  double decimalDouble;

  int *intPonteiro;
  char *charPonteiro;
  char *stringPonteiro;
  float *floatPonteiro;
  double *doublePonteiro;

  printf("Digite um inteiro: ");
  scanf("%d", &inteiro);
  printf("Print: %d \n\n", inteiro);
  getchar();

  printf("Digite um caracter: ");
  scanf("%c", &caracter);
  printf("Print: %c \n\n", caracter);

  printf("Digite uma string: ");
  scanf("%s", string);
  printf("Print: %s \n\n", string);

  printf("Digite um decimal: ");
  scanf("%f", &decimal);
  printf("Print: %f \n\n", decimal);

  printf("Digite um decimal double: ");
  scanf("%lf", &decimalDouble);
  printf("Print: %lf \n\n\n", decimalDouble);

  intPonteiro = &inteiro;
  charPonteiro = &caracter;
  stringPonteiro = string;
  floatPonteiro =  &decimal;
  doublePonteiro = &decimalDouble;


  printf("Print ponteiro: %d \n\n", *intPonteiro); //Imprime o conteudo
    printf("Print ponteiro: %p \n\n", intPonteiro); // Imprime o endereço
  
  printf("Print ponteiro: %c \n\n", *charPonteiro);
  
  printf("Print ponteiro string: %s \n\n", stringPonteiro); // Imprime a string
  printf("Print ponteiro endereço: %p \n\n", stringPonteiro); // Imprime o endereço
  
  printf("Print ponteiro: %f \n\n", *floatPonteiro);
  printf("Print ponteiro: %lf \n\n", *doublePonteiro);
}
