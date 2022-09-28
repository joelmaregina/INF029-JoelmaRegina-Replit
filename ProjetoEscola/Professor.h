#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41
#define TAMCPF 15
#define TAM 50

typedef struct professor{
  int matricula;
  char nome[TAMNOME];
  char sexo;
  Data nascimento;
  char cpf[TAMCPF];
} Professor;

int mainProfessor(Professor listaProfessor[], int qtdAluno);
int cadastrarProfessor(Professor professor[], int qtd);
void listaProfessores(Professor lista[], int qtd);
int menuAtualizarProfessor();
int atualizarProfessor (Professor professor[], int qtd);
int excluirProfessor(Professor professor[], int qtd);
int menuGerarRelatoriosP();
void exibirRelatoriosP(Professor lista[], int qtd);
int listarPorSexoP(Professor lista[] ,int qtd);
int getProximaMatriculaP();
