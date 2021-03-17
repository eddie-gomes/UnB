#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void retiraPontuacao(char *palavra) {
    char pontuacao[6] = {'\n', ' ', '.', ',', ';', ':'};
    int tamanho = strlen(palavra);

    for(int i = 0; i < strlen(palavra); i++) {
        if(palavra[tamanho-1] == pontuacao[i]) {
            palavra[tamanho-1] = '\0';
            break;
        }
    }
}