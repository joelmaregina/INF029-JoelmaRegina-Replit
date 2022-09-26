#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41
#define TAMCPF 15

typedef struct aluno{
  int matricula;
  char nome[TAMNOME];
  char sexo;
  Data nascimento;
  char cpf[TAMCPF];
} Aluno;

int mainAluno(Aluno listaAluno[], int qtdAluno);
int cadastrarAluno(Aluno aluno[], int qtd);
void listaAlunos(Aluno lista[], int qtd);
int menuAtualizarAluno();
int atualizarAluno (Aluno aluno[], int qtd);
int excluirAluno(Aluno lista[], int qtd);
int getProximaMatriculaA();

