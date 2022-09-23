#include <stdio.h>
#include "Aluno.h"
#include <stdlib.h>
#include <string.h>

int cadastrarAluno(Aluno aluno[], int qtd);
void listaAlunos(Aluno lista[], int qtd);
int getProximaMatricula();
Aluno validarDados();

int menuAluno() {
  int opcao;
  printf("\n============ ÁREA DO ALUNO ============ \n");
  printf("Digite a sua opção:\n1 - Cadastrar Aluno \n2 - Listar Alunos \n3 - Excluir aluno \n0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainAluno(Aluno listaAluno[], int qtdAluno)
{
  
  int opcao = 1;

  while(opcao !=0){
    opcao = menuAluno();

    switch(opcao){
      case 1: {
        qtdAluno = cadastrarAluno(listaAluno, qtdAluno);
        break;
      }
      case 2 : {
        listaAlunos(listaAluno, qtdAluno);
        break;
      }
      case 3: {
        
        break;
      }
      default: printf("Opção Inválida. Digite um número entre 0 e 4.");
    }
  } 
  return qtdAluno;
}

// Aluno validarDados (Aluno aluno[], int qtdAluno){
//   Aluno alunoAtual;
  
//   printf("============ CADASTRO DE ALUNOS ============ \n");
  
//   printf("Digite o seu nome: \n");
//   fgets(alunoAtual.nome, TAMNOME, stdin);
//   getchar();
  
//   printf("Digite sua data de nascimento DD MM AAAA : \n");
//   scanf("%d %d %d", &alunoAtual.nascimento.dia, &alunoAtual.nascimento.mes, &alunoAtual.nascimento.ano);
//   getchar();
  
//   printf("Digite seu CPF: \n");
//   fgets(alunoAtual.cpf, TAMCPF, stdin);
//   getchar();
  
//   printf("Digite seu sexo: \n");
//   scanf(" %c", &alunoAtual.sexo);
//   getchar();
  
//   if (validarNascimento(alunoAtual.nascimento.dia, alunoAtual.nascimento.mes, alunoAtual.nascimento.ano) == VALIDO && validarCPF(alunoAtual.cpf) == VALIDO && validarSexo(alunoAtual.sexo) == VALIDO ){
//     printf("========= Aluno cadastrado com sucesso! ========= \n");
//     printf("\n======================================= \n");
//     cadastrarAluno(aluno, qtdAluno);
//     return alunoAtual;
//   } else {
//     if (validarNascimento(alunoAtual.nascimento.dia, alunoAtual.nascimento.mes, alunoAtual.nascimento.ano) == INVALIDO) printf("Aluno não cadastrado: Data de nascimento inválida! \n");
//     if (validarCPF(alunoAtual.cpf)  == INVALIDO) printf("Aluno não cadastrado: CPF inválido! \n");
//     if (validarSexo(alunoAtual.sexo) == INVALIDO) printf("Aluno não cadastrado: Sexo inválido! \n");
//   }
// }

int cadastrarAluno(Aluno aluno[], int qtd){
  // Aluno dadosAluno = validarDados();
  char nome[TAMNOME];
  int dia, mes, ano;
  char cpf[TAMCPF];
  char sexo;
  
  printf("============ CADASTRO DE ALUNOS ============ \n");
  
  aluno[qtd].matricula = getProximaMatricula();
  getchar();

  printf("Digite o seu nome: \n");
  fgets(nome, TAMNOME, stdin);
  getchar();
  
  printf("Digite sua data de nascimento DD MM AAAA : \n");
  scanf("%d %d %d", &dia, &mes, &ano);
  getchar();
  
  printf("Digite seu CPF: \n");
  fgets(cpf, TAMCPF, stdin);
  getchar();
  
  printf("Digite seu sexo: \n");
  scanf(" %c", &sexo);
  getchar();

  if (validarNascimento(dia, mes, ano) == VALIDO && validarCPF(cpf) == VALIDO && validarSexo(sexo) == VALIDO ){
    printf("========= Aluno cadastrado com sucesso! ========= \n");
    printf("\n======================================= \n");
    strcpy(aluno[qtd].nome, nome);
    aluno[qtd].nascimento.dia = dia;
    aluno[qtd].nascimento.mes = mes;
    aluno[qtd].nascimento.ano = ano;
    strcpy(aluno[qtd].cpf, cpf);
    aluno[qtd].sexo = sexo;
    qtd++;
  } else {
    if (validarNascimento(dia, mes, ano) == INVALIDO) printf("Aluno não cadastrado: Data de nascimento inválida! \n");
    if (validarCPF(cpf)  == INVALIDO) printf("Aluno não cadastrado: CPF inválido! \n");
    if (validarSexo(sexo) == INVALIDO) printf("Aluno não cadastrado: Sexo inválido! \n");
  }

  return qtd;
}

void listaAlunos(Aluno lista[], int qtd){
  printf("\n ============ LISTA DE ALUNOS ============\n");
  for (int i = 0; i < qtd; i++){
    printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s \nSEXO: %c\n", lista[i].nome, lista[i].matricula, lista[i].nascimento.dia, lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].cpf, lista[i].sexo);
  printf("\n------------------------------------\n");
  }  
}

int getProximaMatricula(){
  static int matriculaAtualAluno = 100;
  matriculaAtualAluno++;
  return matriculaAtualAluno;
}

   // gcc Escola.c Aluno.c -o  esc