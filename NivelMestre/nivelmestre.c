#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_super_poder(Carta c) {
    return (float)c.populacao + c.area + c.pib + c.pontos_turisticos + c.pib_per_capita + (1.0 / c.densidade_populacional);
}

int main() {
    Carta c1, c2;

    // Entrada de dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", c1.estado);
    printf("Codigo: ");
    scanf("%d", &c1.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c1.nome);
    printf("Populacao: ");
    scanf("%lu", &c1.populacao);
    printf("Area (km²): ");
    scanf("%f", &c1.area);
    printf("PIB: ");
    scanf("%f", &c1.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c1.pontos_turisticos);

    // Entrada de dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]", c2.estado);
    printf("Codigo: ");
    scanf("%d", &c2.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c2.nome);
    printf("Populacao: ");
    scanf("%lu", &c2.populacao);
    printf("Area (km²): ");
    scanf("%f", &c2.area);
    printf("PIB: ");
    scanf("%f", &c2.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c2.pontos_turisticos);

    // Cálculo de Densidade Populacional e PIB per capita
    c1.densidade_populacional = c1.populacao / c1.area;
    c2.densidade_populacional = c2.populacao / c2.area;

    c1.pib_per_capita = c1.pib / c1.populacao;
    c2.pib_per_capita = c2.pib / c2.populacao;

    // Cálculo do Super Poder
    c1.super_poder = calcular_super_poder(c1);
    c2.super_poder = calcular_super_poder(c2);

    // Comparações
    printf("\nComparação de Cartas:\n");

    printf("Populacao: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);

    return 0;
}