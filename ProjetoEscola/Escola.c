#include "Escola.h"

int imprimeMenu() {
  int opcao;
  printf("\n========================================== \n");
  printf("Seja bem vindo ao sistema da Escola Saber.\n");
  printf("Digite a opção desejada:\n");
  printf("  1 - Área do Alunos\n  2 - Área do Professor\n  3 - Central das disciplinas\n  4 - Listar relatórios \n");
  scanf("%d", &opcao);
  return opcao;
}

int main(void) {
  Aluno listaAluno[TAM];
  Professor listaProfessor[TAM];
  Disciplina listaDisciplina[TAM];
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
        qtdProfessor = mainProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 3: {
        qtdDisciplina = mainDisciplina(listaDisciplina, qtdDisciplina, listaProfessor, qtdProfessor, listaAluno, qtdAluno);
        break;
      }
      case 4: {
        exibirRelatoriosPrincipal(listaAluno, qtdAluno, listaProfessor, qtdProfessor, listaDisciplina, qtdDisciplina);
      }
      default: printf("Opção Inválida. Digite um número entre 0 e 4.");
    }
  }

  return 0;
}

int menuRelatoriosPrincipal(){
  int opcao;
  printf("\n\n |||||||||||| GERAR RELATÓRIOS |||||||||||| \n\n");
  printf("Digite a sua opção:\n  1 - Listar aniversariantes de um mês\n  2 - Buscar professores e alunos\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

void exibirRelatoriosPrincipal(Aluno listaA[], int qtdA, Professor listaP[], int qtdP, Disciplina listaD[], int qtdD) {
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuRelatoriosPrincipal();
  
    switch (opcao) {
      case 0:{
        printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
        break;
      } 
      case 1: {
        listarAniversariantes(listaA, qtdA, listaP, qtdP);
        break;
      }
      case 2: {
        buscarPessoas(listaA, qtdA, listaP, qtdP);
        break;
      }
      case 3: {
        //listarPorDataDeNascimentoA(lista, qtd);
        break;
      }
      default: printf("\n Opção Inválida. Digite um número entre 0 e . \n");
    }
  }
}

int listarAniversariantes(Aluno listaA[], int qtdA, Professor listaP[], int qtdP){
  int mes;

  printf("Digite o mês em que você deseja buscar aniversariantes: ");
  scanf("%d", &mes);
  if(validarMes(mes) == INVALIDO){
    printf("\n O mês digitado é inválido. Digite um valor entre 1 e 12. \n");
    return 0;
  }

  for(int i = 0; i < qtdA; i++){
    if (listaA[i].nascimento.mes == mes){
      printf("\n ***** ALUNOS ANIVERSARIANTES DO MÊS ***** \n");
      printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s "
       "\nSEXO: %c\n",
       listaA[i].nome, listaA[i].matricula, listaA[i].nascimento.dia,
       listaA[i].nascimento.mes, listaA[i].nascimento.ano, listaA[i].cpf,
       listaA[i].sexo);
      printf("\n------------------------------------\n");
    }
  }
  for(int i = 0; i < qtdP; i++){
    if (listaP[i].nascimento.mes == mes){
      printf("\n ***** PROFESSORES ANIVERSARIANTES DO MÊS ***** \n");
      printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s "
       "\nSEXO: %c\n",
       listaP[i].nome, listaP[i].matricula, listaP[i].nascimento.dia,
       listaP[i].nascimento.mes, listaP[i].nascimento.ano, listaP[i].cpf,
       listaP[i].sexo);
      printf("\n------------------------------------\n");
    }
  }
  return 0;
}

int buscarPessoas(Aluno listaA[], int qtdA, Professor listaP[], int qtdP){
  char string[TAMNOME];
  int i, j, k;
  int tamanho = 0;
  int tamanhoString;

  getchar();
  printf("Digite o nome (ou fragmento) a ser buscado (Mínimo 3 caracteres): ");
  fgets(string, TAMNOME, stdin);
  
  for(int i = 0; i < 10; i++) if(string[i] == '\n') string[i] = '\0';

  tamanhoString = strlen(string);
  if (tamanhoString < 3){
    printf("\n A string digitada é inválida. Digite pelo menos 3 caracteres para realizar a busca. \n");
    return 0;
  }

  printf("\n ***** ALUNOS ENCONTRADOS ***** \n");
  for(i = 0, j = 0; i < qtdA; i++){
    int tamNome = strlen(listaA[i].nome) - 1;
    for(k = 0; k < tamNome; k++){
      if(string[j] == listaA[i].nome[k]){
        tamanho++;
        j++;
      }
      if (tamanho == tamanhoString){
        printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s "
         "\nSEXO: %c\n",
         listaA[i].nome, listaA[i].matricula, listaA[i].nascimento.dia,
         listaA[i].nascimento.mes, listaA[i].nascimento.ano, listaA[i].cpf,
         listaA[i].sexo);
        printf("\n------------------------------------\n");
        tamanho = 0;
      }
    }
  }
  tamanho = 0;
  printf("\n ***** PROFESSORES ENCONTRADOS ***** \n");
  for(i = 0, j = 0; i < qtdP; i++){
    int tamNome = strlen(listaP[i].nome) - 1;
    for(k = 0; k < tamNome; k++){
      if(string[j] == listaP[i].nome[k]){
        tamanho++;
        j++;
      }
      if (tamanho == tamanhoString){
        printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s "
         "\nSEXO: %c\n",
         listaP[i].nome, listaP[i].matricula, listaP[i].nascimento.dia,
         listaP[i].nascimento.mes, listaP[i].nascimento.ano, listaP[i].cpf,
         listaP[i].sexo);
        printf("\n------------------------------------\n");
        tamanho = 0;
      }
    }
  }

}
