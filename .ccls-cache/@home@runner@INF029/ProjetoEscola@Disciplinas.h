#include "Professores.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41
#define TAMMATRICULA 12
#define TAMCODDISC 8

typedef struct
{
    char nome[TAMNOME];
    int codigoDisciplina[TAMCODDISC];
    char semestre;
    Professor nomeProfessor;
} Disciplina;

Disciplina cadastrarDisciplina();
