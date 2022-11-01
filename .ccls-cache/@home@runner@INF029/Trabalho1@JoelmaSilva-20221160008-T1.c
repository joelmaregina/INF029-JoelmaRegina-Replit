// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Joelma Regina de Assis da Silva
//  email: joelma_silvaa@hotmail.com
//  Matrícula: 20221160008
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include "JoelmaSilva-20221160008-T1.h"
#include <stdlib.h>
#include <math.h>

int ehBissexto(int ano);
int contaDias(int diaInicial, int diaFinal, int mesInicial, int mesFinal, int anoInicial, int anoFinal);

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;
  //DataQuebrada dataQuebrada = quebraData(data);
  DataQuebrada dataRecebida;

  //quebrar a string data em strings sDia, sMes, sAno
  dataRecebida = quebraData(data);
  
  if (dataRecebida.valido == 0) return 0;

  // Valida se as datas digitadas existem:
  if(dataRecebida.iDia > 31 || dataRecebida.iDia < 1 || dataRecebida.iMes > 12 || dataRecebida.iMes  < 1) return 0;
  
  // Valida os meses de 30 dias:
  if((dataRecebida.iMes == 4 || dataRecebida.iMes == 6 || dataRecebida.iMes == 9 || dataRecebida.iMes == 11) && dataRecebida.iDia > 30) return 0;
    
  // Confere se o ano é bisexto e a quantidade de dias do mês de Fevereiro a depender se o ano é bisexto ou não:
  if ((dataRecebida.iAno % 4 == 0)  && ((dataRecebida.iAno % 100 != 0) || (dataRecebida.iAno % 400 == 0))){
    if (dataRecebida.iMes == 2 && dataRecebida.iDia > 29) return 0;
  } else {
    if(dataRecebida.iMes == 2 && dataRecebida.iDia > 28) return 0;
  }

  return datavalida;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  DiasMesesAnos dma;

  DataQuebrada dInicial = quebraData(datainicial);
  DataQuebrada dFinal = quebraData(datafinal);

  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }else{
    //verifique se a data final não é menor que a data inicial
    if(dInicial.iAno > dFinal.iAno){
      dma.retorno = 4;
      return dma;
    } else if((dInicial.iAno <= dFinal.iAno) && (dInicial.iMes > dFinal.iMes)){
      dma.retorno = 4;
      return dma;
    } else if((dInicial.iAno <= dFinal.iAno) && (dInicial.iMes == dFinal.iMes) && dInicial.iDia > dFinal.iDia){
      dma.retorno = 4;
      return dma;
    }
    
    //calcule os dados e armazene nas três variáveis a seguir:
    if((dFinal.iAno >= dInicial.iAno) && (dFinal.iMes >= dInicial.iMes) && dFinal.iDia >= dInicial.iDia){
      dma.qtdAnos = dFinal.iAno - dInicial.iAno;
      dma.qtdMeses = dFinal.iMes - dInicial.iMes;
      dma.qtdDias = dFinal.iDia - dInicial.iDia;
    } else if ((dFinal.iAno >= dInicial.iAno) && (dFinal.iMes >= dInicial.iMes) && dFinal.iDia < dInicial.iDia){
      dma.qtdAnos = dFinal.iAno - dInicial.iAno;
      dma.qtdMeses = dma.qtdMeses = dFinal.iMes - dInicial.iMes - 1;
      dma.qtdDias = contaDias(dInicial.iDia, dFinal.iDia, dInicial.iMes, dFinal.iMes, dInicial.iAno, dFinal.iAno);
    }
    
    //se tudo der certo
    dma.retorno = 1;
    return dma;
    
  } 
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  int tamanhoTexto = strlen(texto);
  int i;

  if(isCaseSensitive){
    for(i = 0; i < tamanhoTexto; i++){
      if(c == texto[i]){
        qtdOcorrencias++;
      }
    }
  } else {
    for(i = 0; i < tamanhoTexto; i++){
      if(((c >= 65 && c <= 90) && c == texto[i] || c + 32 == texto[i]) || ((c >= 97 && c <= 122) && c == texto[i] || c - 32 == texto[i])){
        qtdOcorrencias++;
      }
    }
  }

  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int valor;
    int i, j, k;
    int indexP = 0;
    int inicio = -1;
    int fim = -1;
    int acentos = 0;
    int acentosBusca = 0;
    int tamTexto = strlen(strTexto);
    int tamString = strlen(strBusca);

    // Para desconsiderar as posicões duplicadas dos caracteres acentuados da string de busca:
    for(int i = 0; i < tamString; i++) if (strBusca[i] == -61) acentosBusca++;
    tamString -= acentosBusca;
    
    for (i = 0; i < 30; i++) posicoes[i] = -1;

    for(i = 0, j = 0; i < tamTexto; i++){
      // Encontra o primeiro caracter igual e guarda a posição inicial
      if (strTexto[i] == strBusca[j]){
        valor = 0;
        inicio = i;
        // Busca por mais caracteres iguais após o primeiro achado
        for(k = i; k < tamTexto; k++){
          if(strTexto[k] == strBusca[j]){
            valor++;
            j++;
          } else break; 
        }
        // Se o tamanho da string for do mesmo tamanho da sequencia encontrada, guarda a posiçao final da string buscada:
        if(valor == tamString){
            fim = k;
            i = k-1;
            // Como C por padrão utiliza a Tabela ASCII reduzida (0 á 127), os caracteres acentuados terão valores negativos:
            for(int l = 0; l <= k; l++) if(strTexto[l] < 0) acentos++;
        }
        // Como em C  um caracter acentuado ocupa 2 posições: Dividimos a contagem de acentos por 2.
        acentos /=2;
        if(inicio != -1 && fim != -1){
          posicoes[indexP++] = (inicio+1) - acentos;
          posicoes[indexP++] = (fim) - acentos;
          qtdOcorrencias++;
        }
        inicio = -1;
        fim = -1;
        j = 0;
        acentos = 0;
      }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int i, j, k;
  int maiorBase;
  int divisor = 1; 
  int multiplicador;
  int invertido = 0;
  
  for(i = num, maiorBase = 1; i >= 10; i = i/10, maiorBase++);
  
  for(k = 1; k < maiorBase; k++) divisor *= 10; 
  
  for(j = maiorBase, multiplicador = 1 ; j > 0 ; j--, multiplicador*=10, divisor/=10){
      int aux = (num/divisor)*multiplicador;
      invertido += aux;
      num %= divisor;
  }
  num = invertido;
  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
// QUESTÃO 6 SEM USAR ARRAY:
int q6(int numerobase, int numerobusca){
    int maiorBaseBusca = 1;
    int k;
    int qtdOcorrencias = 0;
    
    for(int j = numerobusca ; j >= 10 ; j = j/10, maiorBaseBusca++);
    
    for(int k = numerobase ; k > 0; k /= 10){
        int restoBase = k % 10;
        int restoBusca = numerobusca % 10;
        if(maiorBaseBusca == 1 && numerobusca == restoBase) qtdOcorrencias ++;
        if (maiorBaseBusca > 1) {
          if (k % 10 == restoBusca){
            int cont = 0;
            int aux = numerobusca;
            for(int l = k; l > 0 ; l /= 10){
              restoBusca = aux%10;
              if( l % 10 == restoBusca){
                cont++;
                aux /=10;
              } else break;
              if(cont == maiorBaseBusca) {
                  qtdOcorrencias++;
                  k /= pow(10,(maiorBaseBusca-1));
              }      
            }
          }
        }
    }
    return qtdOcorrencias;
}
// //QUESTÃO 6 USANDO ARRAY:
// int q6(int numerobase, int numerobusca){
//     int maiorBase = 1;
//     int maiorBaseBusca = 1;
//     int arrayBase[10];
//     int arrayBusca[10];
//     int qtdOcorrencias = 0;
//     int m;
    
//     for(int i = numerobase ; i >= 10; i = i/10, maiorBase++);
//     for(int j = numerobusca ; j >= 10; j = j/10, maiorBaseBusca++);
    
//     for(int m = 0; m < 10; m++) arrayBase[m] = -1;
//     for(int m = 0; m < 10; m++) arrayBusca[m] = -1;
    
//     for(int i = maiorBase -1 ; i > -1; i--){
//         arrayBase[i] = numerobase % 10;
//         numerobase /= 10;
//     } 
//     for(int i = maiorBaseBusca -1; i > -1; i--){
//         arrayBusca[i] = numerobusca % 10;
//         numerobusca /= 10;
//     }
    
//     for (int k = 0, j = 0 ; arrayBase[k] != -1  ; k++){
//         if (arrayBase[k] == arrayBusca[j]){
//             int cont = 0;
//             for(m = k ; m < maiorBase; m++){
//                 if (arrayBase[m] == arrayBusca[j]){
//                     cont++;
//                     j++;
//                 } else break;
//             }
//             if (cont == maiorBaseBusca){
//               qtdOcorrencias ++;
//               k = m -1;
//             }
//             j = 0;
//         }
//     }
//   return qtdOcorrencias;
// }

int ehBissexto(int ano){
  if ((ano % 4 == 0)  && ((ano % 100 != 0) || (ano % 400 == 0))){
    return 1;
  } else {
    return 0;
  }
}

int contaDias(int diaInicial, int diaFinal, int mesInicial, int mesFinal, int anoInicial, int anoFinal){
  int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int limiteMesInicial;
  int limiteMesFinal;
  int diasMesInicial;
  int totalDias;

  if(mesFinal - mesInicial == 1 && anoFinal == anoInicial){
    if ((mesInicial == 2 && ehBissexto(anoInicial) == 1)) meses[1] = 29; 
    diasMesInicial = (meses[mesInicial - 1]) - diaInicial;
    totalDias = diasMesInicial + diaFinal;
  } else if (mesFinal - mesInicial == 1 && anoFinal > anoInicial){
    int penultimoMes = mesFinal - 1;
    if (penultimoMes == 2 && ehBissexto(anoFinal) == 1) meses[1] = 29; 
    diasMesInicial = (meses[mesInicial - 1]) - diaInicial;
    totalDias = diasMesInicial + diaFinal;
  }else{
    int penultimoMes = mesFinal - 1;
    if (penultimoMes == 2 && ehBissexto(anoFinal) == 1) meses[1] = 29;
    diasMesInicial = (meses[penultimoMes - 1]) - diaInicial;
    totalDias = diasMesInicial + diaFinal;
  }

  return totalDias;
}
      
