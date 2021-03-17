#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "retirarPontuacao.c"

void calculaBOW(FILE *dicionario, FILE *TRA, int *cont) {
    char palavraD[40] = "";
    char palavraTR[40] = "";
    int i = 0;
    int tamanho_palavra;

    fseek(dicionario, 0, SEEK_SET);
    do {
        fseek(TRA, 0, SEEK_SET);
        fscanf(dicionario, "%s", palavraD);
        printf("%s\n", palavraD);
        while(!feof(TRA)) {
            strlwr((char *)fscanf(TRA, "%s", palavraTR));
            retirarPontuacao(palavraTR);
            printf("-------------%s-----------------", palavraTR);
            if(strcmp(palavraD, palavraTR) == 0) {
                printf("TESTE TESTE %s", palavraTR);
                cont[i]++;
            }
        }
        i++;
    } while(!feof(dicionario));
}