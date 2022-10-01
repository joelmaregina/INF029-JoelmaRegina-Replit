#include "Disciplina.h"


int menuDisciplina() {
  int opcao;
  printf("\n========== ÁREA DAS DISCIPLINAS ========== \n");
  printf("Digite a sua opção:\n  1 - Cadastrar Disciplina \n  2 - Listar Disciplinas \n  3 - Atualizar Disciplina\n  4 - Excluir Disciplina\n  5 - Listar relatórios de disciplinas \n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor, Aluno listaAluno[], int qtdAluno)
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
        qtdDisciplina = cadastrarDisciplina(listaDisciplina, qtdDisciplina, listaProfessor, qtdProfessor);
        break;
      }
      case 2 : {
        listaDisciplinas(listaDisciplina, qtdDisciplina);
        break;
      }
      case 3: {
        atualizarDisciplina(listaDisciplina, qtdDisciplina, listaProfessor, qtdProfessor);
        break;
      }
      case 4: {
        qtdDisciplina = excluirDisciplina(listaDisciplina, qtdDisciplina);
        break;
      }
      case 5: {
        exibirRelatoriosD(listaDisciplina, qtdDisciplina, listaAluno, qtdAluno);
        break;
      }
      default: 
        printf("Opção Inválida. Digite um número entre 0 e 5.");
    }
  } 
  return qtdDisciplina;
}

int cadastrarDisciplina(Disciplina disciplina[], int qtd, Professor listaProfessor[], int qtdProfessor){
  char nome[TAMNOME];
  int matriculaProfessor;
  int indexP;
  int vagas;
  int semestre;
  
  printf("======== CADASTRO DE DISCIPLINAS ======== \n");

  printf("Digite a matricula do professor da disciplina: \n");
  scanf("%d", &matriculaProfessor);
  indexP = validaProfessor(matriculaProfessor, listaProfessor, qtdProfessor);
  if(indexP != -1){
      strcpy(disciplina[qtd].nomeProfessor, listaProfessor[indexP].nome);
      disciplina[qtd].matriculaProfessor = listaProfessor[indexP].matricula;
      printf("\n Professor encontrado e atribuído á matéria\n\n");
  } else {
    printf("\n Professor não encontrado!\n");
     return qtd;
  }
  
  disciplina[qtd].codigoDisciplina = getCodigoDisciplina();
  getchar();
  listaProfessor[indexP].materias[listaProfessor[indexP].numMat] = disciplina[qtd].codigoDisciplina;
  listaProfessor[indexP].numMat++;

  printf("Digite o nome da disciplina: \n");
  fgets(nome, TAMNOME, stdin);
  getchar();
  strcpy(disciplina[qtd].nome, nome);
  
  printf("Digite o número do semestre da disciplina.\n  --Digite 0 para disciplinas optativas: \n");
  scanf("%d", &semestre);
  disciplina[qtd].semestre = semestre;
  getchar();

  printf("Digite o número de vagas a serem ofertadas: \n");
  scanf("%d", &vagas); 
  disciplina[qtd].vagas = vagas;

  printf("\n ===== Disciplina cadastrada com sucesso! ===== \n");
  
  qtd++;
  return qtd;
}

void listaDisciplinas(Disciplina lista[], int qtd){
  printf("\n *********** LISTA DE DISCIPLINAS ***********\n");
  for (int i = 0; i < qtd; i++){
    printf(" Código da Disciplina: %d\n Nome da disciplina: %s\n Professor: %s  =>(Matricula do professor: %d)\n Semestre: %d;\n Vagas: %d\n", lista[i].codigoDisciplina, lista[i].nome, lista[i].nomeProfessor, lista[i].matriculaProfessor, lista[i].semestre, lista[i].vagas);
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

int atualizarDisciplina (Disciplina disciplina[], int qtd, Professor listaProfessor[], int qtdProfessor){
  int numMateria;
  int matriculaNovoProfessor;
  int professor = INVALIDO;
  
  printf("Digite o código da disciplina que você quer Atualizar: ");
  scanf("%d", &numMateria);
  int opcao = 1;
  int indexP;

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
            printf("Digite a matricula do(a) novo(a) professor(a) da disciplina: \n");
            scanf("%d", &matriculaNovoProfessor);
            indexP = validaProfessor(matriculaNovoProfessor, listaProfessor, qtdProfessor);
            if(indexP != -1){
                listaProfessor[i].numMat--;
                strcpy(disciplina[i].nomeProfessor, listaProfessor[indexP].nome);
                disciplina[i].matriculaProfessor = listaProfessor[indexP].matricula;
                listaProfessor[indexP].materias[listaProfessor[i].numMat] = disciplina[i].codigoDisciplina;
                  listaProfessor[indexP].numMat++;
                printf("\n Professor encontrado e atribuído á matéria\n\n");
            } else {
              printf("\n Professor não encontrado!\n");
               return qtd;
            }
            break;
          }
          case 3: {
            printf("Digite o novo semestre da Disciplina : \n");
            scanf("%d", &disciplina[i].semestre);
            printf("\n -- Semestre da Disciplina atualizado com sucesso! -- \n");
            break;
          }
          case 4: {
            printf("Digite o novo número de vagas a serem ofertadas: \n");
            scanf("%d", &disciplina[i].vagas);
            printf("\n --- Número de vagas da Disciplina atualizado com sucesso! --- \n");
            break;
          }
          default: 
            printf("Opção Inválida. Digite um número entre 0 e 4.");
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
        disciplina[j] = disciplina[j+1];
      }
      printf("\n ------ Disciplina excluída com sucesso! ------ \n ");
      qtd--;
      return qtd;
    }
  }
  printf("\n ----- Código de disciplina não encontrado! ----- \n");
  return qtd;
}

int menuGerarRelatoriosD(){
   int opcao;
  printf("\n\n |||||||||||| GERAR RELATÓRIOS |||||||||||| \n\n");
  printf("Digite a sua opção:\n  1 - Listar disciplinas com mais de 40 vagas \n  2 - Listar detalhes de uma disciplina\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao; 
}

void exibirRelatoriosD(Disciplina listaD[], int qtdD, Aluno listaA[], int qtdA) {
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuGerarRelatoriosD();

    switch (opcao) {
      case 0:{
        printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
        break;
      } 
      case 1: {
        listarMaisQue40vagas(listaD, qtdD);
        break;
      }
      case 2: {
        listarDetalhesDisciplina(listaD, qtdD, listaA, qtdA);
        break;
      }
      default: printf("Opção Inválida. Digite um número entre 0 e .");
    }
  }
}

int listarMaisQue40vagas(Disciplina lista[],int  qtd){
  int maximo = 40;
  printf("\n ||||| Disciplinas com mais de 40 vagas: |||||");
  
  for(int i = 0; i < qtd; i++){
    if (lista[i].vagas > maximo){
      printf("\n ________________________________________ \n\n Nome da Disciplina: %s\n Nome do Professor: %s(Matrícula: %d) \n Número de vagas: %d", lista[i].nome, lista[i].nomeProfessor, lista[i].matriculaProfessor ,lista[i].vagas);
    }
  }
}

int listarDetalhesDisciplina(Disciplina listaD[], int qtdD, Aluno listaA[], int qtdA){
  int codDisciplina;
  int indexD;
  printf("Digite o código da disciplina que você deseja imprimir em detalhes: ");
  scanf("%d", &codDisciplina);
  indexD = validarDisciplinaD(listaD, qtdD, codDisciplina);
  if(indexD == -1){
    printf("\n   Disciplina não encontrada! \n\n");
    return 0;
  } else{
    printf("\n *********** DETALHES DE DISCIPLINA: ***********\n");
    printf(" Código da Disciplina: %d\n Nome da disciplina: %s\n Professor: %s  =>(Matricula do professor: %d)\n Semestre: %d;\n Vagas: %d\n", listaD[indexD].codigoDisciplina, listaD[indexD].nome, listaD[indexD].nomeProfessor, listaD[indexD].matriculaProfessor, listaD[indexD].semestre, listaD[indexD].vagas);
    if(listaD[indexD].numAlunos == 0){
      printf("\n Ainda não existem aluno matriculados nesta matéria! \n\n");
    } else {
      printf("\n Alunos inscritos: \n");
      for(int i = 0; i <= listaD[indexD].numAlunos; i++){
        int matriculaAluno = listaD[indexD].alunos[i];
        for(int j = 0; j < qtdA; j++){
          if(matriculaAluno == listaA[j].matricula) printf(" [0%d] Aluno(%d): %s \n", j+1,listaA[j].matricula, listaA[j].nome);
        }
      }
      printf("\n---------------------------------------------\n");
    }
  }
}

int validaProfessor(int matriculaProf, Professor listaProfessor[], int qtdProfessor){
  for(int i = 0; i < qtdProfessor; i++){
    if(matriculaProf == listaProfessor[i].matricula){
      return i;
    }
  }
  return -1;
}

int validarDisciplinaD(Disciplina listaD[], int qtdD, int codDisc){
  for(int i = 0; i < qtdD; i++){
    if(codDisc == listaD[i].codigoDisciplina){
      return i;
    }
  }
  return -1;
}