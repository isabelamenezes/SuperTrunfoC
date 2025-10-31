#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[3];
    char codigo[5];
    char nomeCidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    struct Carta carta1, carta2;

    // ===== Entrada dos dados da primeira carta =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", carta1.estado);

    printf("Código da carta (ex: A01): ");
    scanf("%4s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // ===== Entrada dos dados da segunda carta =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", carta2.estado);

    printf("Código da carta (ex: A02): ");
    scanf("%4s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // ===== Cálculos =====
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // ===== Comparação =====
    // Escolha do atributo de comparação — altere aqui se quiser comparar outro
    // Opções: populacao, area, pib, densidadePopulacional, pibPerCapita
    printf("\n=== Comparação de cartas (Atributo: PIB per capita) ===\n");

    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}