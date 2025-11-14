#include <stdio.h>

#define TAM 10        
#define TAM_NAVIO 3   

int main() {


    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; 
        }
    }

    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO]   = {3, 3, 3};

    int linhaH = 2;
    int colunaH = 4;

    int linhaV = 5;
    int colunaV = 7;

    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }

    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: navio vertical não cabe no tabuleiro.\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] == 3 ||
            tabuleiro[linhaV + i][colunaV] == 3) {

            printf("Erro: navios se sobrepõem.\n");
            return 1;
        }
    }

    
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    printf("\n===== BATALHA NAVAL - TABULEIRO =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}