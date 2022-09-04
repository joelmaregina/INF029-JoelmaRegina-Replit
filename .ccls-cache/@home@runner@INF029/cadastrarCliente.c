#include <stdio.h>

/* 08. Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente. */

char cadastrarCliente (char nome[], char dataNascimento[], char cpf[], char sexo){
  printf("============ CADASTRO CLIENTES ============");
  printf("Digite o seu nome: \n");
  fgets(nome, 31, stdin);
  printf("Digite sua data de nascimento: \n");
  fgets(dataNascimento, 11, stdin);
  printf("Digite seu CPF: \n");
  fgets(cpf, 16, stdin);
  printf("Digite seu sexo: \n");
  scanf("%c", &sexo);
  
}

void main (){
  char nome[31];
  char dataNascimento[11];
  char cpf[16];
  char sexo;

  cadastrarCliente(nome, dataNascimento, cpf, sexo);

  printf("NOME: ");
  puts(nome);
  printf("DATA DE NASCIMENTO: ");
  puts(dataNascimento);
  printf("CPF: ");
  puts(cpf);
  printf("SEXO: ");
  printf("%d", sexo);
}