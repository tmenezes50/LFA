#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define TAMANHO_VETOR 500


int main() {
    do {
    
    /* criação de variáveis */
    int tamanho_palavra = 0;
    int aceito = TRUE;
    int a = 0;
    int b = 0;
    int c = 0;
    char *str;

    /* alocando vetor de string */
    str = (char *)malloc(TAMANHO_VETOR* sizeof(char*));

    if(str == NULL) {
        free;
        printf("espaço insuficiente\n");
    }

    /* recebendo entrada  da palavra */
    printf("\n: ");

    for(int i = 0; i < TAMANHO_VETOR; i++) {
        scanf("%s", &str[i]);
        if (getchar() == '\n') i = TAMANHO_VETOR;   
    }

    /* contando numero de letras na palavras */
    for(int i = 0; i < TAMANHO_VETOR; i++) {
        if(str[i] != NULL) {
            if(str[i] == 'a' ) {
                a++;
            }
            if(str[i] == 'b') {
                b++;
            }
            if(str[i] == 'c') {
                c++;
            }
            tamanho_palavra ++;
        } else { i = TAMANHO_VETOR; }
    }


    for(int i = 0; i < tamanho_palavra; i++) {

        /* 1 - testando se a palavra tem mais de uma letra */
        if(tamanho_palavra < 2) {
            aceito = FALSE;  // 
        }

        /* 2 - certificando se a palavra possui somente as letras a, b ou c */
        if(str[i] != 'a' && str[i] != 'b' && str[i] != 'c') {
            aceito = FALSE;
        }

        /* 3 - certificando para a palavra começar somente com a ou b e termina com b */
        if((str[0] != 'a' && str[0] != 'b') || str[tamanho_palavra-1] != 'b') {
            aceito = FALSE;
        }

        /* 4 - caso a primeira seja a, certifica que todas as outras seguintes sejam a também */
        if(a > 0) {
            for(int i = 0; i < a; i++) {
                if(str[i] != 'a') {
                    aceito = FALSE;
                    i = a;
                }
            }
        }

        /* 5 - certifica que a proxima palavra depois do a seja b */
        if(str[a] != 'b' || str[a+1] != 'b') {
            aceito = FALSE;
        }

        /* 6 - certifica que para cada c adicionado, teremos dois b a mais */
        if (b > c + 2){
            aceito = FALSE;
        } 

        /* 7 - certifica que sempre depois de c terá um b */
        if(c > 1) {
            for(int i = 0; i < tamanho_palavra; i++) {
                if (str[i] == 'c') {
                    if(str[i + 1] != 'b') {
                        aceito = FALSE;
                        i = tamanho_palavra;
                    }
                }
            }
        }

        /* 8 - caso tenha c, certifica que ela vai ser a penultima letra da palavra  */
        if(c > 0) {
            if (str[tamanho_palavra - 2] != 'c') {
                aceito = FALSE;
            }
        }
    }


    /* retorna se palavra foi aceita ou nao */
    if(aceito == TRUE) {
        printf("aceita");
    } else { printf("rejeita"); }
    } while (getchar() != EOF);
    
    return 0;
}