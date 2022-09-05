// 06. Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário e retornar as três letras. 
// A função main deve imprimir essas três letras.
#include <stdio.h>
void ler3Letras(char letras[]);

int main()
{
    char letras[4];
    
    ler3Letras(letras);
    
    printf("O 1º caracter é: %c\nO 2º caracter é: %c\nO 3º caracter é: %c", letras[0], letras[1], letras[2]);
}

void ler3Letras(char letras[])
{
  for(int i = 0; i < 3; i++){
    printf("Digite o %dº caracter: ", i+1);
    scanf("%c", &letras[i]);
    getchar();
  }
}
