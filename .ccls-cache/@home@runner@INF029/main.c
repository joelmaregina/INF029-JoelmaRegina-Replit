#include <stdio.h>

//07. Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do usuário e retornar as três palavras. A função main deve imprimir essas três palavras.
#define PALAVRAS 3

char ler3Palavras(char palavras[PALAVRAS][]);

void main()
{
    char palavras[PALAVRAS][];
    
    ler3Palavras(palavras);
    
}

char ler3Palavras(char palavras[])
{
    printf("Digite a 1º palavra: ");
    scanf("%c", &palavras[0]);
    getchar();
    printf("Digite a 2º palavra: ");
    scanf("%c", &palavras[1]);
    getchar();
    printf("Digite a 3º palavra: ");
    scanf("%c", &palavras[2]);
}