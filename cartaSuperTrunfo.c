#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define NUM_CARTAS 2

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado;                // Letra A-H
    char codigo[4];             // Ex: A01
    char nomeCidade[MAX_NOME]; // Nome da cidade
    int populacao;              // Número de habitantes
    float area;                 // Área em km²
    float pib;                  // PIB em bilhões
    int pontosTuristicos;       // Número de pontos turísticos
} Carta;

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Carta cartas[NUM_CARTAS];

    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\n--- Inserir dados da Carta %d ---\n", i + 1);

        // Estado
        do {
            printf("Estado (A-H): ");
            scanf(" %c", &cartas[i].estado);
            if (cartas[i].estado < 'A' || cartas[i].estado > 'H') {
                printf("Estado inválido. Digite uma letra entre A e H.\n");
            }
        } while (cartas[i].estado < 'A' || cartas[i].estado > 'H');

        // Código da carta
        printf("Código da Carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        limparBuffer(); // Limpa o buffer antes de ler strings

        // Nome da cidade
        printf("Nome da Cidade: ");
        fgets(cartas[i].nomeCidade, MAX_NOME, stdin);
        // Remove o '\n' do final, se existir
        size_t len = strlen(cartas[i].nomeCidade);
        if (len > 0 && cartas[i].nomeCidade[len - 1] == '\n') {
            cartas[i].nomeCidade[len - 1] = '\0';
        }

        // População
        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        // Área
        printf("Área (em km²): ");
        scanf("%f", &cartas[i].area);

        // PIB
        printf("PIB (em bilhões de reais): ");
        scanf("%f", &cartas[i].pib);

        // Pontos turísticos
        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }

    // Exibe as cartas
    printf("\n======= Cartas Cadastradas =======\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
    }

    return 0;
}