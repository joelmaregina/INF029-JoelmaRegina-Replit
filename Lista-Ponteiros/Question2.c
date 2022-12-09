// 02. Faça um programa que tenha uma função troca que recebe dois parâmetros inteiros e troque o valor das variáveis um pelo outro.
// A função main deve ler do usuário os dois valores, chamar a função troca, e depois imprimir os valores trocados
#include <stdio.h>

int troca(int *pontA, int *pontB);

int main()
{
  int a, b;
  int *pontA = &a; 
  int *pontB = &b;
  
  printf("Digite o primeiro inteiro: ");
  scanf("%d", &a);
  printf("Digite o segundo inteiro: ");
  scanf("%d", &b);

  troca(pontA, pontB);

  printf("Inteiro 'a': %d \nInteiro 'b' : %d", *pontA, *pontB);
}

int troca(int *pontA, int *pontB){
  int *aux;
  aux = pontA;
  pontA = pontB;
  pontB = aux;
}