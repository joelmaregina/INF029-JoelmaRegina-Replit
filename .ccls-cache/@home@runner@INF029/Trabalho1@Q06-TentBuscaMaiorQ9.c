#include <stdio.h>


int main(){
    int qtdOcorrencias = 0;
    int numerobase = 3539343;
    int numerobusca = 39;
    
    int i, j, k, l, m;
    int maiorBase, maiorBaseBusca;
    int divisor = 1;
    int divisorB = 1;
    int multiplicador;
    int arrayBase[10];
    int arrayBusca[10];

    for(i = numerobase, maiorBase = 1; i >= 10; i = i/10, maiorBase++);
    for(m = numerobusca, maiorBaseBusca = 1; m >= 10; m = m/10, maiorBaseBusca++);
    printf("Maior Base: %d, %d \n", maiorBase, maiorBaseBusca);
    
    for(k = 1; k < maiorBase; k++) divisor *= 10;
    for(k = 1; k < maiorBaseBusca; k++) divisorB *= 10;
    
    for(int m = 0; m < 10; m++) arrayBase[m] = -1;
    for(int m = 0; m < 10; m++) arrayBusca[m] = -1;
    
    for(j = maiorBase, multiplicador = 1, l = 0; j > 0 ; j--, multiplicador*=10, divisor/=10){
        int aux = (numerobase/divisor);
        arrayBase[l++] = aux;
        numerobase %= divisor;
        printf("AUX: %d \n", aux);
    }
    
    if (maiorBaseBusca > 1){
        for(m = maiorBaseBusca, multiplicador = 1, l = 0; m > 0 ; m--, multiplicador*=10, divisorB/=10){
            int aux = (numerobusca/divisorB);
            arrayBusca[l++] = aux;
            numerobusca %= divisorB;
            printf("AUX Busca: %d \n", aux);
        }
    }
    
    for(int d = 0, k = 0; d < maiorBaseBusca ; d++) printf("Busca %d: %d \n", d,arrayBusca[d]);
    
    if(maiorBaseBusca == 1){
        for(int m = 0; arrayBase[m] != -1; m++){
            if(maiorBaseBusca == 1){
                if(arrayBase[m] == numerobusca) qtdOcorrencias++;
            }
        }
    } else {
        for(int m = 0, l = 0; arrayBase[m] != -1; m++){
            if(arrayBase[m] == arrayBusca[l]){
                int cont = 0;
                for(int z = m, y = 0; y < maiorBaseBusca; z++, y++){ 
                    if(arrayBase[z] == arrayBusca[y]){
                        cont++;
                        printf("%d, %d \n", arrayBase[z], arrayBusca[y]);
                        y++;
                    }
                    printf("%d \n", cont);
                }
                if(cont == maiorBaseBusca) qtdOcorrencias++;
            }
        }
    }   
    printf("qtdOcorrencias: %d", qtdOcorrencias);
}


#include <stdio.h>

int main()
{
    int numerobase = 34567368;
    int numerobusca = 3;
    int maiorBase = 1;
    int maiorBaseBusca = 1;
    int arrayBase[10];
    int arrayBusca[10];
    
    int qtdOcorrencias = 0;
    
    for(int i = numerobase ; i >= 10; i = i/10, maiorBase++);
    for(int j = numerobusca ; j >= 10; j = j/10, maiorBaseBusca++);
    
    printf("%d, %d \n", maiorBase, maiorBaseBusca);
    
    // for(int m = 0; m < 10; m++) arrayBase[m] = -1;
    // for(int m = 0; m < 10; m++) arrayBusca[m] = -1;
    
    for(int i = maiorBase -1 ; i > -1; i--){
        arrayBase[i] = numerobase % 10;
        numerobase /= 10;
    } 
    for(int i = maiorBaseBusca -1; i > -1; i--){
        arrayBusca[i] = numerobusca % 10;
        numerobusca /= 10;
    }
    
    if(maiorBaseBusca == 1){
        for(int k = 0, j = 0; numerobase >= 0; k++){
            if(arrayBase[k] == arrayBusca[j]) qtdOcorrencias++;
            j = 0;
        }
    } else {
        for (int k = 0, j = 0 ; arrayBase[k] != -1  ; k++){
            if (arrayBase[k] == arrayBusca[j]){
                int cont = 0;
                printf(" \n %d \n", arrayBase[k]);
                for(int m = k ; m < maiorBase; m++){
                    if (arrayBase[m] == arrayBusca[j]){
                        cont++;
                        j++;
                    } else break;
                }
                if (cont == maiorBaseBusca) qtdOcorrencias ++;
                j = 0;
            }
        }
    }
    
    printf("Quantidade ocorrências:  %d \n", qtdOcorrencias);
    
    for(int i = 0; arrayBase[i] != -1; i++) printf("[%d]: %d \n", i, arrayBase[i]);
    printf("\n");
    for(int i = 0; arrayBusca[i] != -1; i++) printf("[%d]: %d \n", i, arrayBusca[i]);
}