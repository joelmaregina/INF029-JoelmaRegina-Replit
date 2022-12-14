#include "Professor.h"

int menuProfessor() {
  int opcao;
  printf("\n========== ÁREA DO PROFESSOR ========== \n");
  printf("Digite a sua opção:\n  1 - Cadastrar Professor\n  2 - Listar Professores\n  3 - Atualizar Professor\n  4 - Excluir Professor\n  5 - Listar relatórios de Professores \n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainProfessor(Professor listaProfessor[], int qtdProfessor)
{
  
  int opcao = 1;

  while(opcao !=0){
    opcao = menuProfessor();

    switch(opcao){
      case 0:{
        printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
        break;
      } 
      case 1: {
        qtdProfessor = cadastrarProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 2 : {
        listaProfessores(listaProfessor, qtdProfessor);
        break;
      }
      case 3: {
        atualizarProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 4: {
        qtdProfessor = excluirProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 5: {
        exibirRelatoriosP(listaProfessor, qtdProfessor);
        break;
      }
      default: 
        printf("\n Opção Inválida. Digite um número entre 0 e 5. \n");
    }
  } 
  return qtdProfessor;
}

int cadastrarProfessor(Professor professor[], int qtd){
  char nome[TAMNOME];
  int dia, mes, ano;
  char cpf[TAMCPF];
  char sexo;
  
  printf("======== CADASTRO DE PROFESSORES ======== \n");
  
  getchar();
  printf("Digite o seu nome: \n");
  fgets(nome, TAMNOME, stdin);
  getchar();
  
  printf("Digite sua data de nascimento DD MM AAAA : \n");
  scanf("%d %d %d", &dia, &mes, &ano);
  getchar();
  
  printf("Digite seu CPF: \n");
  fgets(cpf, TAMCPF, stdin);
  getchar();
  
  printf("Digite seu sexo: \n");
  scanf(" %c", &sexo);
  getchar();

  if (validarNascimento(dia, mes, ano) == VALIDO && validarCPF(cpf) == VALIDO && validarSexo(sexo) == VALIDO ){
    printf("=== Professor cadastrado com sucesso! === \n");
    printf("\n========================================== \n");
    professor[qtd].matricula = getProximaMatriculaP();
    strcpy(professor[qtd].nome, nome);
    professor[qtd].nascimento.dia = dia;
    professor[qtd].nascimento.mes = mes;
    professor[qtd].nascimento.ano = ano;
    strcpy(professor[qtd].cpf, cpf);
    professor[qtd].sexo = sexo;
    qtd++;
  } else {
    if (validarNascimento(dia, mes, ano) == INVALIDO) printf("Professor não cadastrado: Data de nascimento inválida! \n");
    if (validarCPF(cpf)  == INVALIDO) printf("Professor não cadastrado: CPF inválido! \n");
    if (validarSexo(sexo) == INVALIDO) printf("Professor não cadastrado: Sexo inválido! \n");
  }

  return qtd;
}

void listaProfessores(Professor lista[], int qtd){
  printf("\n *********** LISTA DE PROFESSORES *********** \n");
  for (int i = 0; i < qtd; i++){
    printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s \nSEXO: %c\nNº de turmas: %d", lista[i].nome, lista[i].matricula, lista[i].nascimento.dia, lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].cpf, lista[i].sexo, lista[i].numMat);
  printf("\n------------------------------------\n");
  }  
}

int getProximaMatriculaP(){
  static int matriculaAtualProfessor = 100;
  matriculaAtualProfessor++;
  return matriculaAtualProfessor;
}

int menuAtualizarProfessor() {
  int opcao;
  printf("\n++++++++++ ATUALIZAR PROFESSOR ++++++++++ \n");
  printf("Digite a sua opção:\n  1 - Alterar nome \n  2 - Corrigir data de nascimento\n  3 - Alterar sexo\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int atualizarProfessor (Professor professor[], int qtd){
  int numMatricula;
  int dia, mes, ano;
  char sexo;
  
  printf("Digite a matrícula do professor que você quer Atualizar: ");
  scanf("%d", &numMatricula);
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuAtualizarProfessor();

    for (int i = 0; i < qtd; i++) {
      if (professor[i].matricula == numMatricula){
        switch (opcao) {
          case 0:{
            printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
            break;
          } 
          case 1: {
            getchar();
            printf("Digite o novo nome do professor: ");
            fgets(professor[i].nome, TAMNOME, stdin);
            printf("\n ---- Nome atualizado com sucesso! --- \n");
            break;
          }
          case 2: {
            printf("Digite a data de nascimento corrigida DD MM AAAA : \n");
            scanf("%d %d %d", &dia, &mes, &ano);
            if(validarNascimento(dia, mes, ano) == VALIDO){
              professor[i].nascimento.dia = dia;
              professor[i].nascimento.mes = mes;
              professor[i].nascimento.ano = ano;
              printf("\n ---- Data de nascimento corrigida com sucesso! --- \n");
            } else {
              printf("\n ---- Data de nascimento inválida --- \n");
            }
            break;
          }
          case 3: {
            getchar();
            printf("Atualize o seu sexo: \n");
            scanf("%c", &sexo);
            if(validarSexo(sexo)== VALIDO){
              professor[i].sexo = sexo;
                printf("\n ---- Sexo atualizado com sucesso! --- \n");
            } else {
              printf("\n ---- Sexo inválido! --- \n");
            }
            break;
          }
          default: 
            printf("Opção Inválida. Digite um número entre 0 e 3.");
        }
      return 0;
      }
    }
    printf(" \n ------ Número de matricula não encontrado! ----- \n");
    opcao = 0;  
  }
}

int excluirProfessor(Professor professor[], int qtd){
  int numMatricula;
  
  printf("\n--------- EXCLUIR PROFESSOR --------- \n");
  printf("Digite a matrícula do professor que você quer excluir: ");
  scanf("%d", &numMatricula);

  for (int i = 0; i < qtd; i++) {
    if (professor[i].matricula == numMatricula){
      for (int j = i ; j < qtd-1; j++){
        professor[j] = professor[j+1];
      }
      printf("\n ------ Professor excluído com sucesso! ------ \n ");
      qtd--;
      return qtd;
    }
  }
  printf("\n ----- Número de matricula não encontrado! ----- \n");
  return qtd;
}

int menuGerarRelatoriosP(){
  int opcao;
  printf("\n\n |||||||||||| GERAR RELATÓRIOS |||||||||||| \n\n");
  printf("Digite a sua opção:\n  1 - Listar professores por Sexo \n  2 - Listar professores ordenados por nome crescente \n  3 - Listar professores ordenados por data de nascimento\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

void exibirRelatoriosP(Professor lista[], int qtd){
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuGerarRelatoriosP();

    switch (opcao) {
      case 0:{
        printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
        break;
      } 
      case 1: {
        listarPorSexoP(lista, qtd);
        break;
      }
      case 2: {
        listarPorNomeP(lista, qtd);
        break;
      }
      case 3: {
        listarPorDataDeNascimentoP(lista, qtd);
        break;
      }
      default: 
        printf("Opção Inválida. Digite um número entre 0 e 3.");
    }
  }
}

int listarPorSexoP(Professor lista[], int qtd){
  char sexo;
  char sexo2;

  getchar();
  printf("Digite o sexo dos alunos que deseja buscar: ");
  scanf("%c", &sexo);
  if(validarSexo(sexo) == INVALIDO){
    printf("\n ------ O sexo digitado é inválido ----- \n");
    return 0;
  } 

  if(sexo == 'F') sexo2 = 'f';
  if(sexo == 'f') sexo2 = 'F';
  if(sexo == 'M') sexo2 = 'm';
  if(sexo == 'm') sexo2 = 'M';
  if(sexo == 'O') sexo2 = 'o';
  if(sexo == 'o') sexo2 = 'O';

  for(int i = 0; i < qtd; i++){
    if (lista[i].sexo == sexo || lista[i].sexo == sexo2){
      printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s "
       "\nSEXO: %c\nNº de turmas: %d",
       lista[i].nome, lista[i].matricula, lista[i].nascimento.dia,
       lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].cpf,
       lista[i].sexo, lista[i].numMat);
      printf("\n------------------------------------\n");
    }
  }
  return 0;
}

void listarPorNomeP(Professor lista[], int qtd){
  Professor profOrdNome[TAM];
  Professor professorAux;
  int i, j;

  for(i = 0; i < qtd; i++){
    profOrdNome[i] = lista[i];    
  }

  for(int i = 0; i < qtd; i++){
    for(int j = 0; j < qtd - 1 - i; j++){
      if(strcmp(profOrdNome[j].nome, profOrdNome[j+1].nome) > 0){
        professorAux = profOrdNome[j];
        profOrdNome[j] = profOrdNome[j+1];
        profOrdNome[j+1] = professorAux;
      }
    }
  }

    for(i = 0; i < qtd; i++) {
    printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s \nSEXO: %c\nNº de turmas: %d",
       profOrdNome[i].nome, profOrdNome[i].matricula, profOrdNome[i].nascimento.dia,
       profOrdNome[i].nascimento.mes, profOrdNome[i].nascimento.ano, profOrdNome[i].cpf,
       profOrdNome[i].sexo, lista[i].numMat);
      printf("\n------------------------------------\n");
  }
}

void listarPorDataDeNascimentoP(Professor lista[], int qtd){
  //Não está funcionando 100%
  Professor profsOrdNasc[TAM];
  Professor profAux;
  int i, j;
  long int sumAniver1, sumAniver2;

  for(i = 0; i < qtd; i++){
    profsOrdNasc[i] = lista[i];
  }
  
  for(i = 0, j = 1; i < qtd - 1; i++, j++){
    int multiplicadorMes1 = 100;
    // if(profsOrdNasc[i].nascimento.mes > 10) multiplicadorMes1 = 1000;
    int multiplicadorMes2 = 100;
    // if(profsOrdNasc[j].nascimento.mes > 10) multiplicadorMes2 = 1000;
    sumAniver1 = (profsOrdNasc[i].nascimento.ano * 10000) + (profsOrdNasc[i].nascimento.mes * multiplicadorMes1) + profsOrdNasc[i].nascimento.dia;
    sumAniver2 = (profsOrdNasc[j].nascimento.ano * 10000) + (profsOrdNasc[j].nascimento.mes * multiplicadorMes2) + profsOrdNasc[j].nascimento.dia;
    if(sumAniver1 > sumAniver2){
      profAux= profsOrdNasc[i];
      profsOrdNasc[i] = profsOrdNasc[j];
      profsOrdNasc[j] = profAux
    ;
    }
  }
  printf("\n ||| Alunos Ordenados pelo nascimento: ||| \n");

  for(i = 0; i < qtd; i++) {
    printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s \nSEXO: %c\nNº de turmas: %d",
       profsOrdNasc[i].nome, profsOrdNasc[i].matricula, profsOrdNasc[i].nascimento.dia,
       profsOrdNasc[i].nascimento.mes, profsOrdNasc[i].nascimento.ano, profsOrdNasc[i].cpf,
       profsOrdNasc[i].sexo, profsOrdNasc[i].numMat);
      printf("\n------------------------------------\n");
  }
}

