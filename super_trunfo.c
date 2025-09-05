#include <stdio.h>

const int ATRIBUTO_ESCOLHIDO = 1;

typedef struct {
    char estado[3];
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

    printf("Estado (ex: SP): ");
    scanf("%2s", carta1.estado);

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

    printf("Estado (ex: RJ): ");
    scanf("%2s", carta2.estado);

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
    printf("Estado: %s\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    printf("\nComparacao de cartas (Atributo: ");

    if (ATRIBUTO_ESCOLHIDO == 1) {
        printf("Populacao):\n");
        printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (ATRIBUTO_ESCOLHIDO == 2) {
        printf("Area):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.area);

        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (ATRIBUTO_ESCOLHIDO == 3) {
        printf("PIB):\n");
        printf("Carta 1 - %s (%s): %.2f bilhoes\n", carta1.nomeCidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f bilhoes\n", carta2.nomeCidade, carta2.estado, carta2.pib);

        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (ATRIBUTO_ESCOLHIDO == 4) {
        printf("Densidade Populacional):\n");
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.nomeCidade, carta1.estado, densidade1);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.nomeCidade, carta2.estado, densidade2);

        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (densidade2 < densidade1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (ATRIBUTO_ESCOLHIDO == 5) {
        printf("PIB per Capita):\n");
        printf("Carta 1 - %s (%s): %.2f reais\n", carta1.nomeCidade, carta1.estado, pibPerCapita1);
        printf("Carta 2 - %s (%s): %.2f reais\n", carta2.nomeCidade, carta2.estado, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (pibPerCapita2 > pibPerCapita1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else {
        printf("ATRIBUTO INVALIDO)\n");
        printf("Ajuste a constante ATRIBUTO_ESCOLHIDO para 1..5.\n");
    }

    printf("========================\n");
    return 0;
}
