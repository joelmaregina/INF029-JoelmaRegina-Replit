#include "Professor.h"

mainProfessor() {
  Professor professorAtual[iProfessor];

  printf("============ CADASTRO DE PROFESSORES ============ \n");
  printf("Digite o número de matrícula: \n");
  fgets(professorAtual[i].matricula, TAMMATRICULA, stdin);
  
  printf("Digite o seu nome: \n");
  fgets(professorAtual[i].nome, TAMNOME, stdin);
  
  printf("Digite seu sexo: \n");
  scanf("%c", &professorAtual[i].sexo);

  printf("Digite sua data de nascimento DD MM AAAA : \n");
  scanf("%d %d %d", &professorAtual[i].nascimento.dia, &professorAtual[i].nascimento.mes, &professorAtual[i].nascimento.ano);
  getchar();
  
  printf("Digite seu CPF: \n");
  fgets(professorAtual[i].cpf, TAMCPF, stdin);
  getchar();
  
  iProfessor++;
  
  return professorAtual[iProfessor];
}