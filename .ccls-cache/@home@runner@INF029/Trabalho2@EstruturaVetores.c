#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

estrutura vetorPrincipal[TAM];

No *inserirElementos(No *inicio, int valor);

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int validaPosicao(int posicao)
{
    if (posicao < 1 || posicao > 10) return POSICAO_INVALIDA;
    else return SUCESSO;
}

int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    // se posição é um valor válido {entre 1 e 10}
    if (validaPosicao(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
  
    // o tamanho nao pode ser menor que 1
    if (tamanho < 1) return TAMANHO_INVALIDO;
  
    // a posicao pode já existir estrutura auxiliar
    if (vetorPrincipal[posicao - 1].estAuxiliar != NULL ) return JA_TEM_ESTRUTURA_AUXILIAR;
    else {
      vetorPrincipal[posicao - 1].estAuxiliar = (int*)malloc(sizeof(int) * tamanho);

      
      // o tamanho ser muito grande
      if(vetorPrincipal[posicao - 1].estAuxiliar == NULL){  
        return SEM_ESPACO_DE_MEMORIA;
      }

      // deu tudo certo, crie
      vetorPrincipal[posicao - 1].tamanho = tamanho;
      vetorPrincipal[posicao -1].qtd = 0;
      return SUCESSO;
    }

} 

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    //printf("AQUI 1\n");
    if (validaPosicao(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    } else {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1].estAuxiliar != NULL ){
            if (vetorPrincipal[posicao-1].qtd < vetorPrincipal[posicao -1].tamanho){
                //insere
                vetorPrincipal[posicao-1].estAuxiliar[vetorPrincipal[posicao-1].qtd] = valor;
                vetorPrincipal[posicao-1].qtd++;
                return SUCESSO;
              } else {
                return SEM_ESPACO;
            }
        } else {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Retorno (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(validaPosicao(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    if(vetorPrincipal[posicao-1].estAuxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    if(vetorPrincipal[posicao-1].qtd == 0) return ESTRUTURA_AUXILIAR_VAZIA;
    vetorPrincipal[posicao-1].qtd--;
    return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Retorno (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if(validaPosicao(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    if(vetorPrincipal[posicao-1].estAuxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    if(vetorPrincipal[posicao-1].qtd == 0) return ESTRUTURA_AUXILIAR_VAZIA;

    for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
      if(vetorPrincipal[posicao-1].estAuxiliar[i] == valor){
        for(int j = i; j < vetorPrincipal[posicao-1].qtd -1 ; j++){
          vetorPrincipal[posicao-1].estAuxiliar[j] = vetorPrincipal[posicao-1].estAuxiliar[j+1];
        }
        vetorPrincipal[posicao-1].qtd--;
        return SUCESSO;
      }
    }
    return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  
    if(validaPosicao(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    if(vetorPrincipal[posicao-1].estAuxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
        vetorAux[i] = vetorPrincipal[posicao-1].estAuxiliar[i];
    }
    return SUCESSO;

}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int i, j, k , aux;
  
    if(validaPosicao(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    if(vetorPrincipal[posicao-1].estAuxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
        vetorAux[i] = vetorPrincipal[posicao-1].estAuxiliar[i];
    }
  
    for (i = 0; i < vetorPrincipal[posicao-1].qtd ; i++){
       for(j = 1 ; j < vetorPrincipal[posicao-1].qtd; j++){
           aux = vetorAux[j];
            for( k = j - 1; k >= 0 && aux < vetorAux[k] ; k--){
                vetorAux[k+1] = vetorAux[k];
            }
            vetorAux[k+1] = aux;
        }
    }
    return SUCESSO;
    
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i, j, k;  
    int cont = 0;
  
    for(i = 0, k = 0; i < 10; i++){
      if (vetorPrincipal[i].qtd == 0) {
        cont++;
      } else {
        for (j = 0; j < vetorPrincipal[i].qtd; j++){
          vetorAux[k++] = vetorPrincipal[i].estAuxiliar[j];
        }
      }
    }
    if(cont == 10) return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    return SUCESSO;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int i, j, k, l, aux;  
  int cont = 0;
  
    for(i = 0, k = 0; i < 10; i++){
      if (vetorPrincipal[i].qtd == 0) {
        cont++;
      } else {
        for (j = 0; j < vetorPrincipal[i].qtd; j++){
          vetorAux[k++] = vetorPrincipal[i].estAuxiliar[j];
        }
      }
    }
    if(cont == 10) return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for (i = 0; i < k ; i++){
        for(j = 1 ; j < k; j++){
          aux = vetorAux[j];
          for( l = j - 1; l >= 0 && aux < vetorAux[l] ; l--){
              vetorAux[l+1] = vetorAux[l];
          }
          vetorAux[l+1] = aux;
        }
    }
    return SUCESSO;
   
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Retorno (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (validaPosicao(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    if(vetorPrincipal[posicao-1].estAuxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;

    novoTamanho = vetorPrincipal[posicao-1].tamanho + novoTamanho;
  
    //printf("\n%d\n", vetorPrincipal[posicao-1].tamanho );
    //printf("\n%d\n", novoTamanhoFinal);

    if( novoTamanho >= 1){
        int *vetorRealloc = vetorPrincipal[posicao - 1].estAuxiliar;
        vetorRealloc = (int*)realloc(vetorPrincipal[posicao-1].estAuxiliar, sizeof(int) * novoTamanho);
      
        // o tamanho ser muito grande
        if(vetorPrincipal[posicao - 1].estAuxiliar == NULL) return SEM_ESPACO_DE_MEMORIA;
      
        // deu tudo certo, crie
        if(novoTamanho < vetorPrincipal[posicao -1].qtd){
  				vetorPrincipal[posicao -1].qtd = novoTamanho;
  			}
        vetorPrincipal[posicao - 1].tamanho = novoTamanho;
        return SUCESSO;
    } else return NOVO_TAMANHO_INVALIDO;
  
    
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if (validaPosicao(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    if(vetorPrincipal[posicao-1].estAuxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    if(vetorPrincipal[posicao-1].qtd == 0) return ESTRUTURA_AUXILIAR_VAZIA;
    return vetorPrincipal[posicao - 1].qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
  int i, j, cont;
  No *inicioCabecote = NULL;

  //Cria cabeçote:
  inicioCabecote = (No*) malloc(sizeof(No));

  for(i = 0; i < TAM; i++){
    if(vetorPrincipal[i].estAuxiliar != NULL && vetorPrincipal[i].qtd > 0){
      for(j = 0 ; j < vetorPrincipal[i].qtd; j++){
        inserirElementos(inicioCabecote, vetorPrincipal[i].estAuxiliar[j]);
      }
      cont++;
    }
  }

  if(cont > 0) return inicioCabecote;
  else return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  int i;
  No *atual;

  atual = inicio -> prox;

  for(i = 0; atual != NULL; i++){
    vetorAux[i] = atual -> conteudo;
    atual = atual -> prox;
  }
  
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  No *atual = *inicio;
  No *prox;

  while(atual != NULL){
    prox = atual -> prox;
    free(atual);
    atual = prox;
  }

  *inicio = atual;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
  for (int i = 0; i < TAM; i++) vetorPrincipal[i].estAuxiliar = NULL;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
  for(int i = 0; i < TAM; i++) free(vetorPrincipal[i].estAuxiliar);
}

No *inserirElementos(No *inicio, int valor){
  No *novo;
  No *atual;

  novo = (No*) malloc (sizeof (No));

  atual = inicio;

  if(inicio == NULL){
    novo-> conteudo = valor;
    novo -> prox = NULL;
    inicio = novo;
  } else {
    while(atual -> prox != NULL) atual = atual -> prox;
    atual -> prox = novo;
    novo -> conteudo = valor;
    novo -> prox = NULL;
  }

  return inicio;
}