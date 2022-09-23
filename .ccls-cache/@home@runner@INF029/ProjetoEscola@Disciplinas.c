#include "Disciplinas.h"

Disciplinas cadastrarDisciplina(){
  Disciplinas disciplinaAtual[iDisciplina];
  
  printf("============ CADASTRO DE DISCIPLINAS ============ \n");
  printf("Digite o seu nome da disciplina: \n");
  fgets(disciplinaAtual[i].nome, TAMNOME, stdin);
  
  printf("Digite o código da disciplina: \n");
  fgets(disciplinaAtual[i].codigoDisciplina, TAMMATRICULA, stdin);
  
  printf("Digite o semestre da disciplina: \n");
  scanf("%c", &disciplinaAtual[i].semestre);
  getchar();
  
  printf("Digite o professor da disciplina: \n");
  fgets(disciplinaAtual[i].cpf, TAMCPF, stdin);
  getchar();
  
  iDisciplina++;
  
  return disciplinaAtual[iDisciplina];
}