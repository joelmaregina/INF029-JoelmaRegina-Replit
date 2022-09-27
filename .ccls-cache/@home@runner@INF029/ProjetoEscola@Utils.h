#ifndef UTILS_H  // header guard
#define UTILS_H

#define VALIDO 1
#define INVALIDO 0
#define SIM 1
#define NAO -1

typedef struct nasc
{
    int dia;
    int mes;
    int ano;
} Data;

int validarSexo(char sexo);
int validarNascimento(int dia, int mes, int ano);
int validarCPF(char cpf[]);
int validarMes(int mes);
int validarProfessorDisciplina (int codigoProfessor);
int bissexto();

#endif