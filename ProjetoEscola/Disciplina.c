#include "Disciplina.h"


int menuDisciplina() {
  int opcao;
  printf("\n========== ÁREA DAS DISCIPLINAS ========== \n");
  printf("Digite a sua opção:\n1 - Cadastrar Disciplina \n2 - Listar Disciplinas \n3 - Excluir Disciplinas \n0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina)
{
  
  int opcao = 1;

  while(opcao !=0){
    opcao = menuDisciplina();

    switch(opcao){
      case 0:{
        printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
        break;
      } 
      case 1: {
        qtdDisciplina = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
        break;
      }
      case 2 : {
        listaDisciplinas(listaDisciplina, qtdDisciplina);
        break;
      }
      case 3: {
        
        break;
      }
      default: printf("Opção Inválida. Digite um número entre 0 e 4.");
    }
  } 
  return qtdDisciplina;
}

int cadastrarDisciplina(Disciplina disciplina[], int qtd){
  char nome[TAMNOME];
  int matriculaProfessor;
  int vagas;
  int semestre;
  
  printf("======== CADASTRO DE DISCIPLINAS ======== \n");

  disciplina[qtd].codigoDisciplina = getCodigoDisciplina();
  getchar();
  
  printf("Digite o nome da disciplina: \n");
  fgets(nome, TAMNOME, stdin);
  getchar();
  strcpy(disciplina[qtd].nome, nome);
  
  printf("Digite o nome do Professor da Disciplina: \n");
  fgets(disciplina[qtd].nomeProfessor, TAMNOME, stdin);
  getchar();
  
  printf("Digite o número do semestre da disciplina. Digite 0 para disciplinas optativas: \n");
  scanf("%d", &semestre);
  disciplina[qtd].semestre = semestre;
  getchar();

  printf("Digite o número de vagas a serem ofertadas: \n");
  scanf("%d", &vagas); 
  disciplina[qtd].vagas = vagas;
  
  // printf("Digite o número de matrícula do Professor da Disciplina: \n");
  // scanf("%d", &matriculaProfessor);
  // disciplina[qtd].nomeProfessor = ;
  // getchar();

  // if ( validarProfessorDisciplina(matriculaProfessor) == VALIDO ){
  //   printf("=== Disciplina cadastrada com sucesso! === \n");
  //   printf("\n========================================== \n");
  //   disciplina[qtd].codigoDisciplina = getCodigoDisciplina();
  //   strcpy(disciplina[qtd].nome, nome);
  //   disciplina[qtd].semestre = semestre;
  //   disciplina[qtd].nomeProfessor = ;
  //   qtd++;
  // } else {
  //   if (validarProfessorDisciplina(matriculaProfessor) == INVALIDO) printf("Disciplina não cadastrada: Professor não cadastrado! \n");
  // }
  qtd++;
  return qtd;
}

void listaDisciplinas(Disciplina lista[], int qtd){
  printf("\n ============ LISTA DE DISCIPLINAS ============\n");
  for (int i = 0; i < qtd; i++){
    printf("Código da Disciplina: %d\nNome: %s\nProfessor: %s\nSemestre: %d;\nVagas: %d\n", lista[i].codigoDisciplina, lista[i].nome, lista[qtd].nomeProfessor, lista[i].semestre, lista[i].vagas);
  printf("\n---------------------------------------------\n");
  }  
}

int getCodigoDisciplina(){
  static int codigoAtualDisciplina = 700000;
  codigoAtualDisciplina++;
  return codigoAtualDisciplina;
}

// gcc Escola.c Aluno.c Utils.c Disciplina.c Professor.c -o apd