#ifndef DISCIPLINA_H  // header guard
#define DISCIPLINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "Professor.h"
#include "Aluno.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41

typedef struct
{
    int codigoDisciplina;
    char nome[TAMNOME];
    int semestre;
    int vagas;
    char nomeProfessor[TAMNOME];
    int matriculaProfessor;
    int alunos[TAM];
} Disciplina;

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor, Aluno listaAluno[], int qtdAlun);
int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor );
void listaDisciplinas(Disciplina lista[], int qtd);
int menuAtualizarDisciplina();
int atualizarDisciplina(Disciplina disciplina[], int qtd, Professor listaProfessor[], int qtdProfessor);
int excluirDisciplina(Disciplina disciplina[], int qtd);
int menuGerarRelatoriosD();
void exibirRelatoriosD(Disciplina lista[], int qtd);
int listarMaisQue40vagas(Disciplina lista[],int  qtd);
int listarDetalhesDisciplina(Disciplina lista[],int  qtd);
int getCodigoDisciplina();

#endif