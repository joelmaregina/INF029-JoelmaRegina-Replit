#include <stdio.h>

#define VALIDO 1
#define INVALIDO 0
#define TAMNOME 41
#define TAMCPF 15
#define TAMMATRICULA 12
#define TAMCODDISC 8
#define NUMALUNOS 3
#define NUMPROFESSORES 3
#define NUMDISCIPLINAS 3

int iAluno = 0;
int iProfessor = 0;
int iDisciplina = 0;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int matricula[TAMMATRICULA];
    char nome[TAMNOME];
    char sexo;
    Data nascimento;
    char cpf[TAMCPF];
} Alunos[NUMALUNOS];

typedef struct
{
    int matricula[TAMMATRICULA];
    char nome[TAMNOME];
    char sexo;
    Data nascimento;
    char cpf[TAMCPF];
} Professores[NUMPROFESSORES];

typedef struct
{
    char nome[TAMNOME];
    int codigoDisciplina[TAMCODDISC];
    char semestre;
    Professores nomeProfessor;
} Disciplinas[NUMDISCIPLINAS];

Alunos[iAluno] cadastrarAluno();
// Professores cadastrarProfessor();
// Disciplinas cadastrarDisciplina();
// int validarSexo(char sexo);
// int validarNascimento(int dia, int mes, int ano);
// int validarCPF(char cpf[]);

int main()
{
  int opcao;
  printf("======================================= \n");
  printf(" Seja bem vindo ao sistema da Escola Saber.");
  printf(" Digite a opção desejada: ");
  printf("1 - Cadastro de Aluns\n2 - Cadastro de professore\n 3 - Cadastro de Disciplina\n 4 - Listar relatórios\n5 - Sair do programa");

  switch(opcao){
    case 1: {
      Alunos alunoAtual[iAluno] = cadastrarAluno();
      
      
      break;
    }
    // case 2: 
    //   Professores professorAtual = cadastrarProfessor(); 
    //   break;
    // case 3: 
    //   Disciplinas disciplinaAtual = cadastrarDisciplina(); 
    //   break;
    // case 4:
    //   ///////
    // case 5: break;
    // default: printf("Opção Inválida. Digite um número entre 1 e 5.");
   }
  
}

Alunos[iAluno] cadastrarAluno()
{
  Aluno alunoAtual[iAluno];

  printf("============ CADASTRO DE ALUNOS ============ \n");
  printf("Digite o número de matrícula: \n");
  fgets(alunoAtual[iAluno].matricula, TAMMATRICULA, stdin);
  
  printf("Digite o seu nome: \n");
  fgets(alunoAtual[iAluno].nome, TAMNOME, stdin);
  
  printf("Digite seu sexo: \n");
  scanf("%c", &alunoAtual[iAluno].sexo);

  printf("Digite sua data de nascimento DD MM AAAA : \n");
  scanf("%d %d %d", &alunoAtual[iAluno].nascimento.dia, &alunoAtual[iAluno].nascimento.mes, &alunoAtual[iAluno].nascimento.ano);
  getchar();
  
  printf("Digite seu CPF: \n");
  fgets(alunoAtual[iAluno].cpf, TAMCPF, stdin);
  getchar();
  
  iAluno++;
  
  return alunoAtual[iAluno];
}