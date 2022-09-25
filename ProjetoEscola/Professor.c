#include "Professor.h"

int menuProfessor() {
  int opcao;
  printf("\n========== ÁREA DO PROFESSOR ========== \n");
  printf("Digite a sua opção:\n1 - Cadastrar Professor \n2 - Listar Professores \n3 - Excluir professor \n0 - Retornar ao menu anterior\n");
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
  printf("\n ============ LISTA DE PROFESSORES ============\n");
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

   // gcc Escola.c Aluno.c Utils.c Professor.c -o pea