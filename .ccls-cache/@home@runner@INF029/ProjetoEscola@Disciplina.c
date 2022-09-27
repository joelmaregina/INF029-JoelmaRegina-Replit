#include "Disciplina.h"


int menuDisciplina() {
  int opcao;
  printf("\n========== ÁREA DAS DISCIPLINAS ========== \n");
  printf("Digite a sua opção:\n  1 - Cadastrar Disciplina \n  2 - Listar Disciplinas \n  3 - Atualizar Disciplina\n  4 - Excluir Disciplina \n  0 - Retornar ao menu anterior\n");
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
        atualizarDisciplina(listaDisciplina, qtdDisciplina);
        break;
      }
      case 4: {
        qtdDisciplina = excluirDisciplina(listaDisciplina, qtdDisciplina);
        break;
      }
      case 5: {
        //exibirRelatoriosD(listaDisciplina, qtdDisciplina);
        break;
      }
      default: printf("Opção Inválida. Digite um número entre 0 e 5.");
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

  qtd++;
  return qtd;
}

void listaDisciplinas(Disciplina lista[], int qtd){
  printf("\n *********** LISTA DE DISCIPLINAS ***********\n");
  for (int i = 0; i < qtd; i++){
    printf(" Código da Disciplina: %d\n Nome: %s\n Professor: %s\n Semestre: %d;\n Vagas: %d\n", lista[i].codigoDisciplina, lista[i].nome, lista[i].nomeProfessor, lista[i].semestre, lista[i].vagas);
  printf("\n---------------------------------------------\n");
  }  
}

int getCodigoDisciplina(){
  static int codigoAtualDisciplina = 700000;
  codigoAtualDisciplina++;
  return codigoAtualDisciplina;
}

int menuAtualizarDisciplina() {
  int opcao;
  printf("\n++++++++++ ATUALIZAR DISCIPLINA ++++++++++ \n");
  printf("Digite a sua opção:\n  1 - Alterar nome da Disciplina \n  2 - Alterar professor da disciplina\n  3 - Alterar Semestre\n  4 - Alterar número de vagas\n");
  scanf("%d", &opcao);
  return opcao;
}

int atualizarDisciplina (Disciplina disciplina[], int qtd){
  int numMateria;
  
  printf("Digite o código da disciplina que você quer Atualizar: ");
  scanf("%d", &numMateria);
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuAtualizarDisciplina();

    for (int i = 0; i < qtd; i++) {
      if (disciplina[i].codigoDisciplina == numMateria){
        switch (opcao) {
          case 0:{
            printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
            break;
          } 
          case 1: {
            getchar();
            printf("Digite o novo nome da disciplina: ");
            fgets(disciplina[i].nome, TAMNOME, stdin);
            printf("\n ---- Nome atualizado com sucesso! ---- \n");
            break;
          }
          case 2: {
            getchar();
            printf("Digite o nome do novo professor da Disciplina : \n");
            fgets(disciplina[i].nomeProfessor, TAMNOME, stdin);
            printf("\n --- Nome do Professor atualizado com sucesso! --- \n");
            break;
          }
          case 3: {
            printf("Digite o novo semestre da Disciplina : \n");
            scanf("%d", &disciplina[i].semestre);
            printf("\n --- Semestre da Disciplina atualizado com sucesso! --- \n");
            break;
          }
          case 4: {
            printf("Digite o novo número de vagas a serem ofertadas: \n");
            scanf("%d", &disciplina[i].vagas);
            printf("\n --- Número de vagas da Disciplina atualizado com sucesso! --- \n");
            break;
          }
          default: printf("Opção Inválida. Digite um número entre 0 e 4.");
        }
      return 0;
      }
    }
    printf(" \n ------ Código de disciplina não encontrado! ----- \n");
    opcao = 0;  
  }
}

int excluirDisciplina(Disciplina disciplina[], int qtd){
  int codMateria;
  
  printf("\n--------- EXCLUIR DISCIPLINA --------- \n");
  printf("Digite o código da disciplina que você quer excluir: ");
  scanf("%d", &codMateria);

  for (int i = 0; i < qtd; i++) {
    if (disciplina[i].codigoDisciplina == codMateria){
      for (int j = i ; j < qtd-1; j++){
        strcpy(disciplina[j].nome, disciplina[j+1].nome);
        strcpy(disciplina[j].nomeProfessor, disciplina[j+1].nomeProfessor);
        disciplina[j].semestre = disciplina[j+1].semestre;
        disciplina[j].vagas = disciplina[j+1].vagas;
      }
      printf("\n ------ Disciplina excluída com sucesso! ------ \n ");
      qtd--;
      return qtd;
    }
  }
  printf("\n ----- Código de disciplina não encontrado! ----- \n");
  return qtd;
}
