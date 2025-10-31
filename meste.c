#include <stdio.h>

// -----------------------------
// Função recursiva da TORRE
// -----------------------------
void moverTorre(int casas) {
    if (casas == 0) return; // caso base
    printf("Cima\n");
    moverTorre(casas - 1); // chamada recursiva
}

// -----------------------------
// Função recursiva + loops do BISPO
// -----------------------------
void moverBispo(int vertical, int horizontal) {
    if (vertical == 0 || horizontal == 0) return; // caso base

    for (int i = 0; i < vertical; i++) { // movimento vertical
        printf("Cima\n");
        for (int j = 0; j < horizontal; j++) { // movimento horizontal
            printf("Direita\n");
        }
    }

    // Chamada recursiva simulando repetição de diagonais
    moverBispo(vertical - 1, horizontal - 1);
}

// -----------------------------
// Função recursiva da RAINHA
// -----------------------------
void moverRainha(int casas) {
    if (casas == 0) return;

    // Rainha se move como torre e bispo
    printf("Cima\n");
    moverRainha(casas - 1);
}

// -----------------------------
// Movimento complexo do CAVALO (loops aninhados + múltiplas condições)
// -----------------------------
void moverCavalo() {
    int casasCima = 2;
    int casasDireita = 1;

    // Loop externo: movimentação para cima
    for (int i = 1, j = 0; i <= casasCima; i++, j++) {
        printf("Cima\n");

        // Loop interno: movimentação para direita
        for (int k = 0; k < casasDireita; k++) {
            if (i < casasCima) continue; // só move pra direita no último "Cima"
            printf("Direita\n");
            break; // sai do loop interno após 1 movimento
        }
    }
}

// -----------------------------
// Função principal
// -----------------------------
int main() {
    // TORRE
    printf("Movimento da Torre:\n");
    moverTorre(3); // Exemplo: 3 casas para cima

    printf("\n");

    // BISPO
    printf("Movimento do Bispo:\n");
    moverBispo(2, 2); // Exemplo: 2 casas para cima e 2 para direita (diagonal)

    printf("\n");

    // RAINHA
    printf("Movimento da Rainha:\n");
    moverRainha(3);

    printf("\n");

    // CAVALO
    printf("Movimento do Cavalo:\n");
    moverCavalo();

    return 0;
}