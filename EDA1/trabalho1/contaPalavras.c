#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contaPalavras(FILE *arquivo) {
    char c;
    int palavras = 1;

    while(1) {
        c = fgetc(arquivo);
        if(c == '\n') {
            palavras++;
        }
        if(c == EOF) {
            break;
        }
    }
    return palavras;
}