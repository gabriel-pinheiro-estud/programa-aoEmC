#include <stdio.h>


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
    printf("Nome do Pais/Cidade: ");
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
    printf("Nome do Pais/Cidade: ");
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
    printf("Nome: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Demografica: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita (info): %.2f reais\n", pibPerCapita1);

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Demografica: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita (info): %.2f reais\n", pibPerCapita2);

    int opcao;
    printf("\n===== MENU DE COMPARACAO =====\n");
    printf("1 - Nome (apenas exibir)\n");
    printf("2 - Populacao (maior vence)\n");
    printf("3 - Area (maior vence)\n");
    printf("4 - PIB (maior vence)\n");
    printf("5 - Pontos Turisticos (maior vence)\n");
    printf("6 - Densidade Demografica (MENOR vence)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    printf("\n=== Resultado da Comparacao ===\n");

    switch (opcao) {
        case 1: {
            printf("Atributo: Nome (exibicao)\n");
            printf("Carta 1: %s (%s)\n", carta1.nomeCidade, carta1.estado);
            printf("Carta 2: %s (%s)\n", carta2.nomeCidade, carta2.estado);
            printf("Observacao: Este atributo nao decide vencedor.\n");
        } break;

        case 2: {
            printf("Atributo: Populacao\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Vencedora: Carta 1 (%s)\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedora: Carta 2 (%s)\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
                if (carta1.pontosTuristicos != carta2.pontosTuristicos) {
                    printf("(Curiosidade) Pontos Turisticos - C1: %d | C2: %d\n",
                           carta1.pontosTuristicos, carta2.pontosTuristicos);
                }
            }
        } break;

        case 3: {
            printf("Atributo: Area\n");
            printf("Carta 1 - %s (%s): %.2f km²\n", carta1.nomeCidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f km²\n", carta2.nomeCidade, carta2.estado, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Vencedora: Carta 1 (%s)\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Vencedora: Carta 2 (%s)\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
                if (carta1.populacao != carta2.populacao) {
                    printf("(Curiosidade) Populacao - C1: %d | C2: %d\n",
                           carta1.populacao, carta2.populacao);
                }
            }
        } break;

        case 4: {
            printf("Atributo: PIB (bilhoes de reais)\n");
            printf("Carta 1 - %s (%s): %.2f bilhoes\n", carta1.nomeCidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): %.2f bilhoes\n", carta2.nomeCidade, carta2.estado, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Vencedora: Carta 1 (%s)\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedora: Carta 2 (%s)\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
                if (pibPerCapita1 != pibPerCapita2) {
                    printf("(Curiosidade) PIB per Capita - C1: %.2f | C2: %.2f\n",
                           pibPerCapita1, pibPerCapita2);
                }
            }
        } break;

        case 5: {
            printf("Atributo: Pontos Turisticos\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.pontosTuristicos);
            printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedora: Carta 1 (%s)\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Vencedora: Carta 2 (%s)\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
                if (densidade1 != densidade2) {
                    printf("(Curiosidade) Densidade - C1: %.2f | C2: %.2f\n",
                           densidade1, densidade2);
                }
            }
        } break;

        case 6: {
            printf("Atributo: Densidade Demografica (MENOR vence)\n");
            printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.nomeCidade, carta1.estado, densidade1);
            printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.nomeCidade, carta2.estado, densidade2);

            if (densidade1 < densidade2) {
                printf("Vencedora: Carta 1 (%s)\n", carta1.nomeCidade);
            } else if (densidade2 < densidade1) {
                printf("Vencedora: Carta 2 (%s)\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
                if (carta1.area != carta2.area) {
                    printf("(Curiosidade) Area - C1: %.2f | C2: %.2f\n",
                           carta1.area, carta2.area);
                }
            }
        } break;

        default: {
            printf("Opcao invalida. Execute novamente e escolha 1..6.\n");
        } break;
    }

    printf("========================\n");
    return 0;
}
