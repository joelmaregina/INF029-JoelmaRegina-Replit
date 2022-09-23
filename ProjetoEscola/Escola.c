#include "Aluno.h"
#include <stdio.h>
// #include "Professores.h"
// #include "Disciplinas.h"

#define TAM 3

int imprimeMenu();

int imprimeMenu() {
  int opcao;
  printf("\n ======================================= \n");
  printf("Seja bem vindo ao sistema da Escola Saber.\n");
  printf("Digite a opção desejada:\n");
  printf(" 1 - Área do Alunos\n 2 - Área do Professor\n 3 - Central das "
         "disciplina\n 4 - Listar relatórios\n 0 - Sair do programa\n");
  scanf("%d", &opcao);
  return opcao;
}

int main(void) {
  Aluno listaAluno[TAM];
  int qtdAluno = 0;
  int qtdProfessor = 0;
  int qtdDisciplina = 0;

  int opcao = 1;

    while (opcao = !0) {
    opcao = imprimeMenu();
    
    switch (opcao) {
      case 1: {
        qtdAluno = mainAluno(listaAluno, qtdAluno);
        break;
      }
      case 2: {
        //qtdProfessor = mainAluno(listaProfessor, qtdProfessor);
        break;
      }
      case 3: {
        //qtdDisciplina = mainAluno(listaDisciplina, qtdDisciplina);
        break;
      }
      case 4: {
        // Relatórios
        break;
      }
      default: printf("Opção Inválida. Digite um número entre 0 e 4.");
    }
  }

  return 0;
}
