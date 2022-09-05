//  04. Crie um programa que tenha uma função ler 3Numeros. Essa função deve ler três números do usuário e retornar os três números. 
//  A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.
#include <stdio.h>
#define TAM 3

void ler3Numeros(int array[])
{
    int i, valor;

    for(i = 0; i < TAM; i++){
        printf("Digite o %d° número: ", i+1);
        scanf("%d", &valor);
        array[i] = valor;
    }
}

int main()
{
    int resultado[TAM];
    
    ler3Numeros(resultado);
    
    for(int i = 0; i < TAM; i++){
        printf("%d\n", resultado[i]);
    }
}