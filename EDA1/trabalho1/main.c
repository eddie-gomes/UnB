#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contaPalavras.c"
#include "calculaBOW.c"

int main() {
    char nome_arquivo[30] = "";
    int *contA, *contB;
    FILE *dicionario = NULL;
    FILE *TRA = NULL;
    FILE *TRB = NULL;
    char *nomeDicionario;
    char opcao = '0';
    int *num;
    char * vetorDicionario;

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
                scanf("%s", nomeDicionario); // Escaneia nome do arquivo Dicionário
                if(dicionario != NULL) { // Caso o arquivo Dicionário já estiver aberto, fecha e abre outro
                    fclose(dicionario);
                }
                dicionario = fopen(nomeDicionario, "r"); // Lê o arquivo Dicionário de nome igual ao escaneado na linha 31
                if(dicionario == NULL) { // Caso falhe em localizar o arquivo Dicionário, printa o erro e volta a tela inicial.
                    printf("Nao foi possivel abrir o arquivo\n");
                } else {
                    num = contaPalavras(dicionario);
                    printf("%s aberto!\n", nomeDicionario);
                    contA = (int*) calloc(num, sizeof(int)); // Alocação do ponteiro A de tamanho igual a quantidade de palavras do arquivo Dicionário
                    contB = (int*) calloc(num, sizeof(int)); // Alocação do ponteiro B de tamanho igual a quantidade de palavras do arquivo Dicionário
                }
                break;

            case 'A':
                printf("Arquivo de referencia A: ");
                scanf("%s", nome_arquivo); // Escaneia nome do texto de referência A (TRA)
                if(TRA != NULL) { // Caso o TRA já esteja aberto, fecha
                    fclose(TRA);
                }
                TRA = fopen(nome_arquivo, "r"); // Abre o TRA de nome igual ao escaneado na linha 48
                if(TRA == NULL) { // Caso não seja possível abrir o arquivo TRA, printa erro
                    printf("Nao foi possivel abrir o arquivo\n");
                } else {
                    printf("%s aberto!\n", nome_arquivo);
                    if(dicionario == NULL) {
                        printf("Nao foi possivel abrir o arquivo dicionario\n");
                    } else {
                        calculaBOW(dicionario, TRA, contA);

                        for(int x = 0; x < num; x++) {
                            printf("%d\n", contA[x]);
                        }

                    }
                }
                break;

                case 'B':
                printf("Arquivo de referencia B: ");
                scanf("%s", nome_arquivo); // Escaneia nome do texto de referência A (TRA)
                if(TRB != NULL) { // Caso o TRA já esteja aberto, fecha
                    fclose(TRB);
                }
                TRB = fopen(nome_arquivo, "r"); // Abre o TRA de nome igual ao escaneado na linha 48
                if(TRB == NULL) { // Caso não seja possível abrir o arquivo TRA, printa erro
                    printf("Nao foi possivel abrir o arquivo\n");
                } else {
                    printf("%s aberto!\n", nome_arquivo);
                    if(dicionario == NULL) {
                        printf("Nao foi possivel abrir o arquivo dicionario\n");
                    } else {
                        calculaBOW(dicionario, TRB, contB);
                    }
                }
                break;
            
            case 'E':
            vetorDicionario = (int*) calloc(num, sizeof(int));
            vetorDicionario = strtok(dicionario,'\n');
            printf("\nPalavras \t\t Texto A(#) \t\t Texto B(#)");
                for(int x = 0; x < num; x++) {
                    printf("\nPalavras \t\t Texto A(#) \t\t Texto B(#)");
                        if(contA[x] != 0 || contB[x] != 0){
                            printf("\n%s \t\t %d \t\t %d\n", vetorDicionario[x], contA[x], contB[x]);
                         };
                };

            break;

            case 'S':
                break;
        }
    }

    fclose(dicionario);
    fclose(TRA);
    printf("Programa encerrado\n");

    return 0;
}