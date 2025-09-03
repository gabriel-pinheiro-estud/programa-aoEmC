#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
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

    printf("Populacao (inteiro, use apenas numeros): ");
    scanf("%lu", &carta1.populacao);

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

    printf("Nome da Cidade: ");
    scanf("%99[^\n]", carta2.nomeCidade);

    printf("Populacao (inteiro, use apenas numeros): ");
    scanf("%lu", &carta2.populacao);

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

    float pibReais1 = carta1.pib * 1e9f;
    float pibReais2 = carta2.pib * 1e9f;

    float invDens1 = 1.0f / densidade1;
    float invDens2 = 1.0f / densidade2;

    float superPoder1 = (float)carta1.populacao
                      + carta1.area
                      + pibReais1
                      + (float)carta1.pontosTuristicos
                      + pibPerCapita1
                      + invDens1;

    float superPoder2 = (float)carta2.populacao
                      + carta2.area
                      + pibReais2
                      + (float)carta2.pontosTuristicos
                      + pibPerCapita2
                      + invDens2;

    printf("\n========================\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    const char* vencedorPop   = (carta1.populacao > carta2.populacao) ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)";
    const char* vencedorArea  = (carta1.area      > carta2.area)      ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)";
    const char* vencedorPIB   = (carta1.pib       > carta2.pib)       ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)";
    const char* vencedorPts   = (carta1.pontosTuristicos > carta2.pontosTuristicos) ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)";
    const char* vencedorDens  = (densidade1 < densidade2)             ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)";
    const char* vencedorPCap  = (pibPerCapita1 > pibPerCapita2)       ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)";
    const char* vencedorSP    = (superPoder1   > superPoder2)         ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)";

    printf("\nComparacao de Cartas:\n");
    printf("Populacao: %s\n", vencedorPop);
    printf("Area: %s\n", vencedorArea);
    printf("PIB: %s\n", vencedorPIB);
    printf("Pontos Turisticos: %s\n", vencedorPts);
    printf("Densidade Populacional: %s\n", vencedorDens);
    printf("PIB per Capita: %s\n", vencedorPCap);
    printf("Super Poder: %s\n", vencedorSP);

    printf("========================\n");

    return 0;
}
