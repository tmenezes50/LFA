#include <stdio.h>
#include <stdlib.h>
#define TAM_PALAVRA 100 

//Função para contar tamanho da palavra
int strlenMelhorado(char* palavra) {
    int tamanho = 0;
    char* atual = palavra;
    while (*atual != '\0') {
        tamanho++;
        atual++;
    }
     return tamanho - 1;
}

//Função para ordenar as palavras
void ordenarMatriz(char** matriz, int qtdPalavras) {
    char* aux;
    for (int i = 0; i < qtdPalavras; i++) {
        for (int j = 0; j < qtdPalavras; j++) {
            if (strlenMelhorado(matriz[i]) > strlenMelhorado(matriz[j])) {
                aux = matriz[j];
                matriz[j] = matriz[i];
                matriz[i] = aux;
            }
        }
    }
}


int main() {
    int qtdPalavras;
    
    printf("Informe a quantidade de palavras: ");
    scanf("%d", &qtdPalavras);
    while (getchar() != '\n');

    char** palavra;
    palavra = (char**)malloc(sizeof(char*) + qtdPalavras);
    for (int i = 0; i < qtdPalavras; i++) {
        palavra[i] = (char*)malloc(sizeof(char) * TAM_PALAVRA);
        printf("Informe a palavra %d: ", (i +1));
        fgets(palavra[i], TAM_PALAVRA, stdin);
        palavra[i][strlenMelhorado(palavra[i])] = '\0';
    }
    ordenarMatriz(palavra, qtdPalavras);
    for (int i = 0; i < qtdPalavras - 1; i++) {
        printf("%s, ", palavra[i]);
    }
    printf("%s", palavra[qtdPalavras - 1]);
    printf("\n");
}