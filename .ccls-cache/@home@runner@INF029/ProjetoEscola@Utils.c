#include "Utils.h"

int validarSexo(char sexo)
{
  int valor = INVALIDO;
    
    if (sexo == 'F' || sexo == 'f' || sexo == 'M' || sexo == 'm' || sexo == 'O' || sexo == 'o') valor = VALIDO;
    
    return valor;
}

int validarNascimento(int dia, int mes, int ano)
{
    int valor = VALIDO;
    
    // Valida os meses de 30 dias:
    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) valor = INVALIDO;
    
    // Confere se o ano é bisexto e a quantidade de dias do mês de Fevereiro a depender se o ano é bisexto ou não:
    if ((ano % 4 == 0)  && ((ano % 100 != 0) || (ano % 400 == 0))){
        if (mes == 2 && dia > 29) valor = INVALIDO;
    } else {
        if(mes == 2 && dia > 28) valor = INVALIDO;
    }
    
    // Valida se as datas digitadas existem:
    if(dia > 31 || dia < 1 || mes > 12 || mes  < 1 || ano > 2022 || ano < 1870) valor = INVALIDO;
    
    return valor;
}


int validarCPF(char cpf[])
{
    int valor = VALIDO;
    char cpfLimpo[12];
    int i, j, multiplicador, multiplicado;
    int soma1 = 0;
    int soma2 = 0;
    int primeiroD, primeiroDString, segundoD, segundoDString;
    char cpfComPrimeiroDigito[11];
    char cpfCompleto[12];
    
    // Retira os caracteres especiais do CPF caso o usuário os digite:
    for(i = 0, j = 0; cpf[i] != '\0'; i++){
        if(cpf[i] >= '0' && cpf[i] <= '9'){
            cpfLimpo[j++] = cpf[i];
        }
    }
    cpfLimpo[j] = '\0';
    
    //Verifica se o CPF tem o número correto de caracteres:
    for(i = 0; cpfLimpo[i] != '\0'; i++);
    if (i < 10){
        valor = INVALIDO;
        return valor;
    }
    // Verifica se o CPF digitado é uma sequencia de números iguais (Resultaria em um falso 'CPF Válido');
    if (cpfLimpo[0] == cpfLimpo[1] && 
        cpfLimpo[1] == cpfLimpo[2] &&
        cpfLimpo[2] == cpfLimpo[3] &&
        cpfLimpo[3] == cpfLimpo[4] &&
        cpfLimpo[4] == cpfLimpo[5] &&
        cpfLimpo[5] == cpfLimpo[6] &&
        cpfLimpo[6] == cpfLimpo[7] &&
        cpfLimpo[7] == cpfLimpo[8] &&
        cpfLimpo[8] == cpfLimpo[9] &&
        cpfLimpo[9] == cpfLimpo[10]){
            valor = INVALIDO;
            return valor;
        }
    
    // Faz a multiplicação e somatório dos valores dos primeiros 9 números do CPF:
    for(i = 0, multiplicador = 10; i < 9; i++, multiplicador --){
        char caracter = cpfLimpo[i];
        int numero = caracter - '0';
        soma1 += (numero * multiplicador);
        // printf("\n Resultado = %d \n", soma1);
    }
    // Acha o valor correto do primeiro digito verificador e o transforma em string
    primeiroD = 11 - (soma1 % 11);
    if (primeiroD > 9) primeiroD = 0;
    primeiroDString = primeiroD + '0';
    // Adciona o 1° digito verificador a um novo CPF em construção para posterior comparação.
    for(i = 0; i < 9; i++){
        cpfComPrimeiroDigito[i] = cpfLimpo[i];
    }
    cpfComPrimeiroDigito[i++] = primeiroDString;
    cpfComPrimeiroDigito[i] = '\0';
    // printf("Com o 1 digito = \n");
    // puts(cpfComPrimeiroDigito);
    
    
    // Faz a multiplicação e somatório dos valores dos primeiros 10 números do CPF (incluindo o digito verificador cauculado anteriormente):
    for(i = 0, multiplicador = 11; i < 10; i++, multiplicador --){
        char caracter = cpfComPrimeiroDigito[i];
        int numero = caracter - '0';
        soma2 += (numero * multiplicador);
        // printf("\n Resultado = %d \n", soma2);
    }
    // Acha o valor correto do segundo digito verificador e o transforma em string
    segundoD = 11 - (soma2 % 11);
    if (segundoD > 9) segundoD = 0;
    segundoDString = segundoD + '0';
    // Adciona o 2° digito verificador a um CPF em construção para posterior comparação.
    for(i = 0; i < 10; i++){
        cpfCompleto[i] = cpfComPrimeiroDigito[i];
    }
    cpfCompleto[i++] = segundoDString;
    cpfCompleto[i] = '\0';
    // printf("Com o 2 digito = \n");
    // puts(cpfCompleto);
    
    for(i = 0; i < 12; i++){
        if(cpfLimpo[i] != cpfCompleto[i]){
            valor = INVALIDO;
            break;
        } 
    }
    
    return valor;
}

int validarMes(int mes){
  int valor = INVALIDO;

  if(mes >= 1 && mes <= 12) valor = VALIDO;

  return valor;
}
