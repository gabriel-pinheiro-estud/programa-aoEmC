#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    int  populacao;
    float area;
    float pib;
    int  pontosTuristicos;
} Carta;

int main(void) {
    Carta carta1;
    Carta carta2;

    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Codigo (ex: A01): ");
    scanf("%3s", carta1.codigo);

    getchar();
    printf("Nome da Cidade: ");
    scanf("%99[^\n]", carta1.nomeCidade);

    printf("Populacao (inteiro): ");
    scanf("%d", &carta1.populacao);

    printf("Area em km2 (use ponto como separador decimal): ");
    scanf("%f", &carta1.area);

    printf("PIB em bilhoes de reais (ex: 699.28): ");
    scanf("%f", &carta1.pib);

    printf("Numero de Pontos Turisticos (inteiro): ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Codigo (ex: B02): ");
    scanf("%3s", carta2.codigo);

    getchar();
    printf("Nome da Cidade: ");
    scanf("%99[^\n]", carta2.nomeCidade);

    printf("Populacao (inteiro): ");
    scanf("%d", &carta2.populacao);

    printf("Area em km2 (use ponto como separador decimal): ");
    scanf("%f", &carta2.area);

    printf("PIB em bilhoes de reais (ex: 300.50): ");
    scanf("%f", &carta2.pib);

    printf("Numero de Pontos Turisticos (inteiro): ");
    scanf("%d", &carta2.pontosTuristicos);

    float densidade1 = (float)carta1.populacao / carta1.area;
    float densidade2 = (float)carta2.populacao / carta2.area;

    float pibPerCapita1 = (carta1.pib * 1e9f) / (float)carta1.populacao;
    float pibPerCapita2 = (carta2.pib * 1e9f) / (float)carta2.populacao;

    printf("\n========================\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    printf("========================\n");

    return 0;
}
