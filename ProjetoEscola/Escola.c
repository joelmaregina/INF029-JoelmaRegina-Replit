#include "Escola.h"

int imprimeMenu() {
  int opcao;
  printf("\n========================================== \n");
  printf("Seja bem vindo ao sistema da Escola Saber.\n");
  printf("Digite a opção desejada:\n");
  printf("  1 - Área do Alunos\n  2 - Área do Professor\n  3 - Central das disciplinas\n  4 - Inscrever aluno em disciplina\n  5 - Busca | Aniversariantes do mês \n ");
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
        inscreverAlunoDisciplina(listaAluno, qtdAluno, listaDisciplina, qtdDisciplina);
        break;
      }
      case 5: {
        exibirRelatoriosPrincipal(listaAluno, qtdAluno, listaProfessor, qtdProfessor, listaDisciplina, qtdDisciplina);
      }
      break;
      default: printf("Opção Inválida. Digite um número entre 0 e 5.");
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
      default: printf("\n Opção Inválida. Digite um número entre 0 e 2. \n");
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

int inscreverAlunoDisciplina(Aluno listaA[], int qtdA, Disciplina listaD[], int qtdD){
  int matriculaAluno;
  int codigoDisciplina;
  int indexA;
  int indexD;
  
  printf("\n Digite a matricula do Aluno: \n");
  scanf("%d", &matriculaAluno);
  indexA = validarMatriculaAluno(listaA, qtdA, matriculaAluno);
  if(indexA != -1){
    printf("\n Aluno encontrado! \n\n");
  } else {
    printf("\n Aluno não encontrado!\n");
    return 0;
  } 
  
  printf("\n Digite o código da disciplina: \n");
  scanf("%d", &codigoDisciplina);
  indexD = validarDisciplina(listaD, qtdD, codigoDisciplina);
  if(indexD != -1){
    for(int i = 0; i <= listaA[indexA].numDisciplinas; i++){
      if(listaA[indexA].disciplinas[i] == codigoDisciplina){
        printf("\n O(A) aluno(a) %s já está matriculado nesta disciplina! \n", listaA[indexA].nome);
        return 0;
      }
    }
    printf("\n Disciplina: %s  encontrada! \n Aluno(a) %s inscrito(a) com sucesso! \n\n", listaD[indexD].nome, listaA[indexA].nome);
    listaD[indexD].alunos[listaD[indexD].numAlunos] = listaA[indexA].matricula;
    listaA[indexA].disciplinas[listaA[indexA].numDisciplinas] = listaD[indexD].codigoDisciplina;
    listaD[indexD].numAlunos++;
    listaA[indexA].numDisciplinas++;
  } else {
    printf("\n Disciplina não encontrada!\n");
    return 0;
  } 
  
}

int validarMatriculaAluno(Aluno listaAluno[], int qtdAluno, int matriculaAluno){
  for(int i = 0; i < qtdAluno; i++){
    if(matriculaAluno == listaAluno[i].matricula){
      return i;
    }
  }
  return -1;
}

int validarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, int codigoDisciplina){
  for(int i = 0; i < qtdDisciplina; i++){
    if(codigoDisciplina == listaDisciplina[i].codigoDisciplina){
      return i;
    }
  }
  return -1;
}
