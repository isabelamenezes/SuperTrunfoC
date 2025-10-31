#include <stdio.h>

int main() {
    // Quantidade de casas que o cavalo deve se mover
    int casasBaixo = 2;
    int casasEsquerda = 1;

    // Movimento de outras peças (exemplo, só pra contexto do desafio anterior)
    printf("Movimento da Torre:\n");
    printf("Cima\n");
    printf("Cima\n");
    printf("Direita\n");

    // Linha em branco separando o Cavalo das demais peças
    printf("\n");

    // Movimento do Cavalo
    printf("Movimento do Cavalo:\n");

    // Loop externo (for) para movimento para baixo
    for (int i = 0; i < casasBaixo; i++) {
        printf("Baixo\n");

        // Loop interno (while) para movimento à esquerda (executa apenas uma vez ao final)
        int j = 0;
        while (i == casasBaixo - 1 && j < casasEsquerda) {
            printf("Esquerda\n");
            j++;
        }
    }

    return 0;
}