#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

#define TAM 50

int imprimeMenu();
int menuRelatoriosPrincipal();
void exibirRelatoriosPrincipal(Aluno listaA[], int qtdA, Professor listaP[], int qtdP, Disciplina listaD[], int qtdD);
int listarAniversariantes(Aluno listaA[], int qtdA, Professor listaP[], int qtdP);
int buscarPessoas(Aluno listaA[], int qtdA, Professor listaP[], int qtdP);