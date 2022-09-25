#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
// #include "Professor.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41

typedef struct
{
    char nome[TAMNOME];
    int codigoDisciplina;
    int semestre;
    int vagas;
    char nomeProfessor[TAMNOME];
} Disciplina;

int menuDisciplina();
int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int cadastrarDisciplina(Disciplina disciplina[], int qtd);
void listaDisciplinas(Disciplina lista[], int qtd);
int getCodigoDisciplina();