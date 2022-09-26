#include "Professor.h"

int menuProfessor() {
  int opcao;
  printf("\n========== ÁREA DO PROFESSOR ========== \n");
  printf("Digite a sua opção:\n  1 - Cadastrar Professor \n  2 - Listar Professores\n  3 - Atualizar Professor \n  4 - Excluir Professor \n  0 - Retornar ao menu anterior\n");
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
      default: printf("Opção Inválida. Digite um número entre 0 e 4.");
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
    printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s \nSEXO: %c\n", lista[i].nome, lista[i].matricula, lista[i].nascimento.dia, lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].cpf, lista[i].sexo);
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
          default: printf("Opção Inválida. Digite um número entre 0 e 3.");
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
        professor[j].matricula = professor[j+1].matricula;
        strcpy(professor[j].nome, professor[j+1].nome);
        professor[j].nascimento.dia = professor[j+1].nascimento.dia;
        professor[j].nascimento.mes = professor[j+1].nascimento.mes;
        professor[j].nascimento.ano = professor[j+1].nascimento.ano;
        strcpy(professor[j].cpf, professor[j+1].cpf);
        professor[j].sexo = professor[j+1].sexo;
      }
      printf("\n ------ Professor excluído com sucesso! ------ \n ");
      qtd--;
      return qtd;
    }
  }
  printf("\n ----- Número de matricula não encontrado! ----- \n");
  return qtd;
}

