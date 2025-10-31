#include <stdio.h>

typedef struct {
    char nome[50];
    long long populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função para obter o valor de um atributo com base na opção escolhida
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0;
    }
}

int main() {
    Carta carta1, carta2;
    int opcao1, opcao2;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", carta1.nome);
    printf("População: ");
    scanf("%lld", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    carta1.densidade = carta1.populacao / carta1.area;

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%lld", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    carta2.densidade = carta2.populacao / carta2.area;

    printf("\n=== Menu de Comparação ===\n");
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    scanf("%d", &opcao1);

    // Menu dinâmico
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }

    scanf("%d", &opcao2);
    while (opcao2 == opcao1) {
        printf("Atributo já escolhido! Escolha outro: ");
        scanf("%d", &opcao2);
    }

    // Obter valores
    float valor1A = obterValor(carta1, opcao1);
    float valor2A = obterValor(carta2, opcao1);
    float valor1B = obterValor(carta1, opcao2);
    float valor2B = obterValor(carta2, opcao2);

    // Exibição dos valores
    printf("\n=== Comparação entre %s e %s ===\n", carta1.nome, carta2.nome);
    printf("Atributo 1: %d | %s: %.2f | %s: %.2f\n", opcao1, carta1.nome, valor1A, carta2.nome, valor2A);
    printf("Atributo 2: %d | %s: %.2f | %s: %.2f\n", opcao2, carta1.nome, valor1B, carta2.nome, valor2B);

    // Comparação individual com regra especial da densidade
    int vencedorA = (opcao1 == 5) ? ((valor1A < valor2A) ? 1 : (valor1A > valor2A ? 2 : 0))
                                  : ((valor1A > valor2A) ? 1 : (valor1A < valor2A ? 2 : 0));
    int vencedorB = (opcao2 == 5) ? ((valor1B < valor2B) ? 1 : (valor1B > valor2B ? 2 : 0))
                                  : ((valor1B > valor2B) ? 1 : (valor1B < valor2B ? 2 : 0));

    // Soma dos atributos
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n%s: %.2f\n", carta1.nome, soma1, carta2.nome, soma2);

    // Resultado final com operador ternário
    (soma1 > soma2) ? printf("\nVencedor: %s\n", carta1.nome)
    : (soma1 < soma2) ? printf("\nVencedor: %s\n", carta2.nome)
    : printf("\nEmpate!\n");

    return 0;
}
