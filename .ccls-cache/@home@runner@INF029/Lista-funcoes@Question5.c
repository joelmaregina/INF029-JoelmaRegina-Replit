// 05. Crie um programa que tenha uma função ler4Numeros.
// Essa função deve ler quatro números do usuário e retornar os quatro números.
// A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.
#include <stdio.h>
#define TAM 4

typedef struct numero{
    int numeros[TAM];
}Numeros;

Numeros ler4Numeros()
{
    int i;
    Numeros numero1;
    
    for(i = 0; i < TAM; i++){
        printf("Digite o %d° número: ", i+1);
        scanf("%d", &numero1.numeros[i]);
        
    }
    return numero1;
    
}

int main()
{
    Numeros resultado = ler4Numeros();
    
    for(int i = 0; i < TAM; i++){
        printf("%d\n", resultado.numeros[i]);
    }
}