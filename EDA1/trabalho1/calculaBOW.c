#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "retirarPontuacao.c"

void calculaBOW(FILE *dicionario, FILE *TR, int *cont) {
    char palavraD[40] = "";
    char palavraTR[40] = "";
    int i = 0;
    int tamanho_palavra;

    fseek(dicionario, 0, SEEK_SET);
    do {
        fseek(TR, 0, SEEK_SET);
        fscanf(dicionario, "%s", palavraD);
        printf("%s\n", palavraD);
        while(!feof(TR)) {
            fscanf(TR, "%s", palavraTR);
            retirarPontuacao(palavraTR);
            if(strcmp(strlwr(palavraD), strlwr(palavraTR)) == 0) {
                cont[i]++;
            }
        }
        i++;
    } while(!feof(dicionario));
}