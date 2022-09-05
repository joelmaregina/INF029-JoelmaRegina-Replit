//07. Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do usuário e retornar as três palavras.
// A função main deve imprimir essas três palavras.
#include <stdio.h>

char ler3Palavras(char palavra1[], char palavra2[], char palavra3[]){
    printf("Digite a 1º palavra: ");
    fgets(palavra1, 21, stdin);
    getchar();
    printf("Digite a 2º palavra: ");
    fgets(palavra2, 21, stdin);
    getchar();
    printf("Digite a 3º palavra: ");
    fgets(palavra3, 21, stdin);
    getchar();
}

int main (){
    char palavra1[21];
    char palavra2[21];
    char palavra3[21];
    
    ler3Palavras(palavra1, palavra2, palavra3);

    printf("Primeira palavra: " );
    puts(palavra1);
    printf("Segunda palavra: " );
    puts(palavra2);
    printf("Terceira palavra: " );
    puts(palavra3);
}