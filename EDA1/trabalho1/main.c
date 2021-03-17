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
            retiraPontuacao(palavraTR);
            if(strcmp(palavraD, palavraTR) == 0) {
                cont[i]++;
            }
        }
        i++;
    } while(!feof(dicionario));
}

int main() {
    char nome_arquivo[30] = "";
    int *contA, *contB;
    FILE *arquivoD = NULL;
    FILE *refA = NULL;
    char opcao = '0';
    int num;

    while(opcao != 'S') {
        printf("\n################## Trabalho 1 ##################");
        printf("\n");
        printf("\nD - Ler arquivo de dicionario");
        printf("\nA - Ler texto de referencia A (TRA)");
        printf("\nB - Ler texto de referencia B (TRB)");
        printf("\nE - Exibir BOWs de TRA e TRB");
        printf("\nS - Sair");
        printf("\nOpcao: ");
        scanf("\n%c", &opcao);
        switch(opcao) {
            case 'D':
                printf("Arquivo de dicionario: ");
                scanf("%s", nome_arquivo);
                if(arquivoD != NULL) {
                    fclose(arquivoD);
                }
                arquivoD = fopen(nome_arquivo, "r");
                if(arquivoD == NULL) {
                    printf("Nao foi possivel abrir o arquivo\n");
                } else {
                    printf("%s aberto!\n", nome_arquivo);
                    num = contaPalavras(arquivoD);
                    printf("%d\n", num);
                    contA = (int*) calloc(num, sizeof(int));
                    contB = (int*) calloc(num, sizeof(int));
                }
                break;
            case 'A':
                printf("Arquivo de referencia A: ");
                scanf("%s", nome_arquivo);
                if(refA != NULL) {
                    fclose(refA);
                }
                refA = fopen(nome_arquivo, "r");
                if(refA == NULL) {
                    printf("Nao foi possivel abrir o arquivo\n");
                } else {
                    printf("%s aberto!\n", nome_arquivo);
                    if(arquivoD == NULL) {
                        printf("Nao foi possivel abrir o arquivo dicionario\n");
                    } else {
                        calculaBOW(arquivoD, refA, contA);
                        for(int x = 0; x < num; x++) {
                            printf("%d\n", contA[x]);
                        }
                    }
                }
                break;
            case 'S':
                break;
        }
    }

    fclose(arquivoD);
    fclose(refA);
    printf("Programa encerrado\n");

    return 0;
}