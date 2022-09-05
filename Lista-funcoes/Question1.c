//  01. Crie um programa que tenha uma função soma e a função main. 
//  A função main deve ler dois valores, enviar para a função soma.
//  A função soma deve realizar a soma e retornar o valor. 
//  A Função main deve imprimir o resultado da soma.
#include <stdio.h>
int soma(int a, int b);
int main()
{
    int a, b;
    int resultado;
    printf("Digite os valores a serem somados: ");
    scanf("%d", &a);
    scanf("%d", &b);
    resultado = soma(a,b);
  
    printf("%d", resultado);
}

int soma(int a, int b)
{
    return a + b;
}