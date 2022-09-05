//  03. Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. 
//  Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar
//  para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, 
//  ou se não é possível calcular o fatorial.
#include <stdio.h>

int fatorial(int valor)
{
    int fatorial = 1;
    for(int i = 1; i <= valor; i++){
  
        fatorial = fatorial * i;
    }
    return fatorial;
}

int main()
{
    int i;
    int valor;
    int resultado;
    
    printf("Digite o número de entrada: \n");
    scanf("%d", &valor);
    
    if (valor < 0){
        printf("Não é possível fazer fatorial de um número negativo");
    }else{
        resultado = fatorial(valor);
        
        printf("%d", resultado);
        
    } 
}