#include "Aluno.h"

int menuAluno() {
  int opcao;
  printf("\n============ ÁREA DO ALUNO ============ \n");
  printf("Digite a sua opção:\n  1 - Cadastrar Aluno \n  2 - Listar Alunos \n  3 - Atualizar Aluno\n  4 - Excluir aluno \n  5 - Listar relatórios de Alunos\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainAluno(Aluno listaAluno[], int qtdAluno) {
  
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuAluno();

    switch (opcao) {
      case 0:{
        printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
        break;
      } 
      case 1: {
        qtdAluno = cadastrarAluno(listaAluno, qtdAluno);
        break;
      }
      case 2: {
        listaAlunos(listaAluno, qtdAluno);
        break;
      }
      case 3: {
        atualizarAluno(listaAluno, qtdAluno);
        break;
      }
      case 4: {
        qtdAluno = excluirAluno(listaAluno, qtdAluno);
        break;
      }
      case 5: {
        exibirRelatoriosA(listaAluno, qtdAluno);
      }
      default:
        printf("Opção Inválida. Digite um número entre 0 e 5.");
    }
  }
  return qtdAluno;
}

int cadastrarAluno(Aluno aluno[], int qtd) {
  char nome[TAMNOME];
  int dia, mes, ano;
  char cpf[TAMCPF];
  char sexo;

  printf("============ CADASTRO DE ALUNOS ============ \n");
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

  if (validarNascimento(dia, mes, ano) == VALIDO && validarCPF(cpf) == VALIDO &&
      validarSexo(sexo) == VALIDO) {
    printf("==== Aluno cadastrado com sucesso! ==== \n");
    printf("\n======================================= \n");
    aluno[qtd].matricula = getProximaMatriculaA();
    strcpy(aluno[qtd].nome, nome);
    aluno[qtd].nascimento.dia = dia;
    aluno[qtd].nascimento.mes = mes;
    aluno[qtd].nascimento.ano = ano;
    //aluno[qtd].dataInt = calculaDataInt(aluno[qtd].nascimento.dia, aluno[qtd].nascimento.mes, aluno[qtd].nascimento.ano);
    strcpy(aluno[qtd].cpf, cpf);
    aluno[qtd].sexo = sexo;
    qtd++;
  } else {
    if (validarNascimento(dia, mes, ano) == INVALIDO)
      printf("Aluno não cadastrado: Data de nascimento inválida! \n");
    if (validarCPF(cpf) == INVALIDO)
      printf("Aluno não cadastrado: CPF inválido! \n");
    if (validarSexo(sexo) == INVALIDO)
      printf("Aluno não cadastrado: Sexo inválido! \n");
  }

    aluno[qtd].numDisciplinas = 0;

  return qtd;
}

void listaAlunos(Aluno lista[], int qtd) {
  printf("\n ============ LISTA DE ALUNOS ============\n");
  for (int i = 0; i < qtd; i++) {
    printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s "
           "\nSEXO: %c\n",
           lista[i].nome, lista[i].matricula, lista[i].nascimento.dia,
           lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].cpf,
           lista[i].sexo);
    printf("\n------------------------------------\n");
  }
}

int getProximaMatriculaA() {
  static int matriculaAtualAluno = 1000;
  matriculaAtualAluno++;
  return matriculaAtualAluno;
}

int menuAtualizarAluno() {
  int opcao;
  printf("\n++++++++++ ATUALIZAR ALUNO ++++++++++ \n");
  printf("Digite a sua opção:\n  1 - Alterar nome \n  2 - Corrigir data de nascimento\n  3 - Alterar sexo\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

int atualizarAluno (Aluno aluno[], int qtd){
  int numMatricula;
  int dia, mes, ano;
  char sexo;
  
  printf("Digite a matrícula do aluno que você quer Atualizar: ");
  scanf("%d", &numMatricula);
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuAtualizarAluno();

    for (int i = 0; i < qtd; i++) {
      if (aluno[i].matricula == numMatricula){
        switch (opcao) {
          case 0:{
            printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
            break;
          } 
          case 1: {
            getchar();
            printf("Digite o novo nome do aluno: ");
            fgets(aluno[i].nome, TAMNOME, stdin);
            printf("\n ---- Nome atualizado com sucesso! --- \n");
            break;
          }
          case 2: {
            printf("Digite a data de nascimento corrigida DD MM AAAA : \n");
            scanf("%d %d %d", &dia, &mes, &ano);
            if(validarNascimento(dia, mes, ano) == VALIDO){
              aluno[i].nascimento.dia = dia;
              aluno[i].nascimento.mes = mes;
              aluno[i].nascimento.ano = ano;
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
              aluno[i].sexo = sexo;
                printf("\n ---- Sexo atualizado com sucesso! --- \n");
            } else {
              printf("\n ---- Sexo inválido! --- \n");
            }
            break;
          default: printf("Opção Inválida. Digite um número entre 0 e 3.");
          }
        }
      return 0;
      }
    }
    printf(" \n ------ Número de matricula não encontrado! ----- \n");
    opcao = 0;
  }
  return 0;
}

int excluirAluno(Aluno lista[], int qtd){
  int numMatricula;
  
  printf("\n----------- EXCLUIR ALUNO ----------- \n");
  printf("Digite a matrícula do aluno que você quer excluir: ");
  scanf("%d", &numMatricula);

  for (int i = 0; i < qtd; i++) {
    if (lista[i].matricula == numMatricula){
      for (int j = i ; j < qtd-1; j++){
        lista[j] = lista[j+1];
      }
      printf("\n ------ Aluno excluído com sucesso! ------ \n");
      qtd--;
      return qtd;
    }
  }
  printf("\n ----- Número de matricula não encontrado! ----- \n");
  return qtd;
}

int menuGerarRelatoriosA(){
  int opcao;
  printf("\n\n |||||||||||| GERAR RELATÓRIOS |||||||||||| \n\n");
  printf("Digite a sua opção:\n  1 - Listar alunos por Sexo \n  2 - Listar inscritos em pelo menos 3 disciplinas\n  3 - Listar alunos ordenados por nome crescente \n  4 - Listar alunos ordenados por data de nascimento\n  0 - Retornar ao menu anterior\n");
  scanf("%d", &opcao);
  return opcao;
}

void exibirRelatoriosA(Aluno lista[], int qtd){
  int opcao = 1;

  while (opcao != 0) {
    opcao = menuGerarRelatoriosA();

    switch (opcao) {
      case 0:{
        printf("\n ... RETORNANDO AO MENU ANTERIOR ... \n\n");
        break;
      } 
      case 1: {
        listarPorSexoA(lista, qtd);
        break;
      }
      case 2:{
        listarInscritosMais3Disc(lista, qtd);
        break;
      }
      case 3: {
        listarPorNomeA(lista, qtd);
        break;
      }
      case 4: {
        listarPorDataDeNascimentoA(lista, qtd);
        break;
      }
      default: printf("Opção Inválida. Digite um número entre 0 e 4.");
    }
  }
}

int listarPorSexoA(Aluno lista[], int qtd){
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
       "\nSEXO: %c\n",
       lista[i].nome, lista[i].matricula, lista[i].nascimento.dia,
       lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].cpf,
       lista[i].sexo);
      printf("\n------------------------------------\n");
    }
  }
  return 0;
}

void listarInscritosMais3Disc(Aluno lista[], int qtd){
  for(int i = 0; i < qtd; i++){
    if (lista[i].numDisciplinas >= 3 ){
      printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s "
       "\nSEXO: %c\nNº de disciplinas: %d",
       lista[i].nome, lista[i].matricula, lista[i].nascimento.dia,
       lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].cpf,
       lista[i].sexo, lista[i].numDisciplinas);
      printf("\n------------------------------------\n");
    }
  }
}

void listarPorNomeA(Aluno lista[], int qtd){
  
}

void listarPorDataDeNascimentoA(Aluno lista[], int qtd){
  Aluno alunosOrdAniver[TAM];
  Aluno alunoAux;
  int i, j;
  long int sumAniver1, sumAniver2;

  for(i = 0; i < qtd; i++){
    alunosOrdAniver[i] = lista[i];    
  }
  
  for(i = 0, j = 1; i < qtd - 1; i++, j++){
    int multiplicadorMes1 = 100;
    if(alunosOrdAniver[i].nascimento.mes > 10) multiplicadorMes1 = 1000;
    int multiplicadorMes2 = 100;
    if(alunosOrdAniver[j].nascimento.mes > 10) multiplicadorMes2 = 1000;
    sumAniver1 = (alunosOrdAniver[i].nascimento.ano * 10000) + (alunosOrdAniver[i].nascimento.mes * multiplicadorMes1) + alunosOrdAniver[i].nascimento.dia;
    sumAniver2 = (alunosOrdAniver[j].nascimento.ano * 10000) + (alunosOrdAniver[j].nascimento.mes * multiplicadorMes2) + alunosOrdAniver[j].nascimento.dia;

    
    if(sumAniver1 < sumAniver2){
      alunoAux = alunosOrdAniver[i];
      alunosOrdAniver[i] = alunosOrdAniver[j];
      alunosOrdAniver[j] = alunoAux;
    }
  }
  printf("\n ||| Alunos Ordenados pelo nascimento: ||| \n");

  for(i = 0; i < qtd; i++) {
    printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s \nSEXO: %c\n",
       alunosOrdAniver[i].nome, alunosOrdAniver[i].matricula, alunosOrdAniver[i].nascimento.dia,
       alunosOrdAniver[i].nascimento.mes, alunosOrdAniver[i].nascimento.ano, alunosOrdAniver[i].cpf,
       alunosOrdAniver[i].sexo);
      printf("\n------------------------------------\n");
  }
}

// void listarPorDataDeNascimentoA(Aluno lista[], int qtd){
//   Aluno alunosOrdAniver[TAM];
//   Aluno alunoAux;
//   int i, j;
//   unsigned long int sumAniver1, sumAniver2;

//   for(i = 0; i < qtd; i++){
//     alunosOrdAniver[i] = lista[i];
//   }
  
//   for(i = 0, j = 1; i < qtd - 1; i++, j++){
//     int multiplicadorMes1 = 1000;
//     int multiplicadorDia1 = 1;
//     int multiplicadorMes2 = 1000;
//     int multiplicadorDia2 = 1;
//     int ano1 = alunosOrdAniver[i].nascimento.ano;
//     int mes1 = alunosOrdAniver[i].nascimento.mes;
//     int dia1 = alunosOrdAniver[i].nascimento.dia;
//     int ano2 = alunosOrdAniver[j].nascimento.ano;
//     int mes2 = alunosOrdAniver[j].nascimento.mes;
//     int dia2 = alunosOrdAniver[j].nascimento.dia;

//     if(mes1 < 10){
//       mes1 = mes1 - 10;
//       multiplicadorMes1 = 100000;
//     } 
//     if(dia1 < 10){
//       dia1 = dia1 - 10;
//       multiplicadorDia1 = 100;
//     } 
//     if(mes2 < 10){
//       mes2 = mes2 - 10;
//       multiplicadorMes2 = 100000;
//     } 
//     if(dia2 < 10){
//       dia2 = dia2 - 10;
//       multiplicadorDia2 = 100;
//     }
    
//     sumAniver1 = (ano1 * 1000000) + (mes1 * multiplicadorMes1) + (dia1 * multiplicadorDia1);
//     sumAniver2 = (ano2 * 1000000) + (mes2 * multiplicadorMes2) + (dia2 * multiplicadorDia2);
    
//     if(sumAniver1 < sumAniver2){
//       alunoAux = alunosOrdAniver[i];
//       alunosOrdAniver[i] = alunosOrdAniver[j];
//       alunosOrdAniver[j] = alunoAux;
//     }
//   }
//   printf("\n ||| Alunos Ordenados pelo nascimento: ||| \n");

//   for(i = 0; i < qtd; i++) {
//     printf("Nome: %s \nMatricula: %d\nData de Nascimento: %d/%d/%d;\nCPF: %s \nSEXO: %c\n",
//        alunosOrdAniver[i].nome, alunosOrdAniver[i].matricula, alunosOrdAniver[i].nascimento.dia,
//        alunosOrdAniver[i].nascimento.mes, alunosOrdAniver[i].nascimento.ano, alunosOrdAniver[i].cpf,
//        alunosOrdAniver[i].sexo);
//       printf("\n------------------------------------\n");
//   }
// }
