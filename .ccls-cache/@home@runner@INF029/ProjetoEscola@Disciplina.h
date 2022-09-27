#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

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
} Disciplina;

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int cadastrarDisciplina(Disciplina disciplina[], int qtd);
void listaDisciplinas(Disciplina lista[], int qtd);
int menuAtualizarDisciplina();
int atualizarDisciplina(Disciplina disciplina[], int qtd);
int excluirDisciplina(Disciplina disciplina[], int qtd);
int getCodigoDisciplina();