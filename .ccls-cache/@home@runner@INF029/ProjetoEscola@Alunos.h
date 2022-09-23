#include "Utils.h"

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41
#define TAMCPF 15
#define TAMMATRICULA 12

typedef struct
{
    int matricula[TAMMATRICULA];
    char nome[TAMNOME];
    char sexo;
    Data nascimento;
    char cpf[TAMCPF];
}Aluno;

Aluno cadastrarAluno(Aluno listaAluno[], int qtdAluno);
int validarSexo(char sexo);
int validarNascimento(int dia, int mes, int ano);
int validarCPF(char cpf[]);
