#include "Utils.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41
#define TAMCPF 15
#define TAMMATRICULA 12
#define TAMCODDISC 8


typedef struct
{
    int matricula[TAMMATRICULA];
    char nome[TAMNOME];
    char sexo;
    Data nascimento;
    char cpf[TAMCPF];
} Professor;

Professor cadastrarProfessor();