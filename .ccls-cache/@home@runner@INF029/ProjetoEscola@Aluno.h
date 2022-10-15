#ifndef ALUNO_H  // header guard
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41
#define TAMCPF 15
#define TAMMATERIAS 8
#define TAM 50

typedef struct aluno{
  int matricula;
  char nome[TAMNOME];
  char sexo;
  Data nascimento;
  char cpf[TAMCPF];
  int disciplinas[TAMMATERIAS];
  int numDisciplinas;
  int dataInt;
} Aluno;

int mainAluno(Aluno listaAluno[], int qtdAluno);
int cadastrarAluno(Aluno aluno[], int qtd);
int getProximaMatriculaA();
void listaAlunos(Aluno lista[], int qtd);
int menuAtualizarAluno();
int atualizarAluno (Aluno aluno[], int qtd);
int excluirAluno(Aluno lista[], int qtd);
int menuGerarRelatoriosA();
void exibirRelatoriosA(Aluno lista[], int qtd);
int listarPorSexoA(Aluno lista[] ,int qtd);
void listarInscritosMais3Disc(Aluno lista[], int qtd);
void listarPorNomeA(Aluno lista[], int qtd);
void listarPorDataDeNascimentoA(Aluno lista[], int qtd); // Não está funcionando 100% 

#endif
