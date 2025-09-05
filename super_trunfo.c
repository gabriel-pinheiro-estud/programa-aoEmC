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
/* Mapeamento dos atributos no menu */
enum Atributo {
    ATR_POP = 1,
    ATR_AREA = 2,
    ATR_PIB = 3,
    ATR_PONTOS = 4,
    ATR_DENSIDADE = 5,
    ATR_PIB_PER_CAPITA = 6
};

int main(void) {
    Carta c1, c2;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", c1.estado);
    printf("Codigo (ex: A01): ");
    scanf("%3s", c1.codigo);
    getchar();
    printf("Nome do Pais/Cidade: ");
    scanf("%99[^\n]", c1.nomeCidade);
    printf("Populacao (inteiro): ");
    scanf("%d", &c1.populacao);
    printf("Area em km2 (use ponto): ");
    scanf("%f", &c1.area);
    printf("PIB em bilhoes de reais (ex: 699.28): ");
    scanf("%f", &c1.pib);
    printf("Pontos Turisticos (inteiro): ");
    scanf("%d", &c1.pontosTuristicos);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", c2.estado);
    printf("Codigo (ex: B02): ");
    scanf("%3s", c2.codigo);
    getchar();
    printf("Nome do Pais/Cidade: ");
    scanf("%99[^\n]", c2.nomeCidade);
    printf("Populacao (inteiro): ");
    scanf("%d", &c2.populacao);
    printf("Area em km2 (use ponto): ");
    scanf("%f", &c2.area);
    printf("PIB em bilhoes de reais (ex: 300.50): ");
    scanf("%f", &c2.pib);
    printf("Pontos Turisticos (inteiro): ");
    scanf("%d", &c2.pontosTuristicos);

    float dens1 = (float)c1.populacao / c1.area;
    float dens2 = (float)c2.populacao / c2.area;
    float pcap1 = (c1.pib * 1e9f) / (float)c1.populacao;
    float pcap2 = (c2.pib * 1e9f) / (float)c2.populacao;

    printf("\n========================\n");
    printf("Carta 1: %s (%s)\n", c1.nomeCidade, c1.estado);
    printf("Populacao: %d | Area: %.2f km² | PIB: %.2f bi | Pontos: %d\n",
           c1.populacao, c1.area, c1.pib, c1.pontosTuristicos);
    printf("Densidade: %.2f hab/km² | PIB per Capita: %.2f R$\n", dens1, pcap1);

    printf("\nCarta 2: %s (%s)\n", c2.nomeCidade, c2.estado);
    printf("Populacao: %d | Area: %.2f km² | PIB: %.2f bi | Pontos: %d\n",
           c2.populacao, c2.area, c2.pib, c2.pontosTuristicos);
    printf("Densidade: %.2f hab/km² | PIB per Capita: %.2f R$\n", dens2, pcap2);

    int a1, a2;
    printf("\n===== Escolha o PRIMEIRO atributo =====\n");
    printf("1 - Populacao (maior vence)\n");
    printf("2 - Area (maior vence)\n");
    printf("3 - PIB (bilhoes) (maior vence)\n");
    printf("4 - Pontos Turisticos (maior vence)\n");
    printf("5 - Densidade Demografica (MENOR vence)\n");
    printf("6 - PIB per Capita (maior vence)\n");
    printf("Opcao: ");
    scanf("%d", &a1);

    switch (a1) {
        case ATR_POP:
        case ATR_AREA:
        case ATR_PIB:
        case ATR_PONTOS:
        case ATR_DENSIDADE:
        case ATR_PIB_PER_CAPITA:
            break;
        default:
            printf("Opcao invalida para o primeiro atributo. Encerrando.\n");
            return 0;
    }

    printf("\n===== Escolha o SEGUNDO atributo (diferente do primeiro) =====\n");
    if (a1 != ATR_POP)           printf("1 - Populacao (maior vence)\n");
    if (a1 != ATR_AREA)          printf("2 - Area (maior vence)\n");
    if (a1 != ATR_PIB)           printf("3 - PIB (bilhoes) (maior vence)\n");
    if (a1 != ATR_PONTOS)        printf("4 - Pontos Turisticos (maior vence)\n");
    if (a1 != ATR_DENSIDADE)     printf("5 - Densidade Demografica (MENOR vence)\n");
    if (a1 != ATR_PIB_PER_CAPITA)printf("6 - PIB per Capita (maior vence)\n");
    printf("Opcao: ");
    scanf("%d", &a2);

    if (a2 == a1) {
        printf("Voce escolheu o mesmo atributo duas vezes. Encerrando.\n");
        return 0;
    }
    switch (a2) {
        case ATR_POP:
        case ATR_AREA:
        case ATR_PIB:
        case ATR_PONTOS:
        case ATR_DENSIDADE:
        case ATR_PIB_PER_CAPITA:
            break;
        default:
            printf("Opcao invalida para o segundo atributo. Encerrando.\n");
            return 0;
    }

    auto getNomeAtributo = [](int a) {
        return (a == ATR_POP) ? "Populacao" :
               (a == ATR_AREA) ? "Area" :
               (a == ATR_PIB) ? "PIB (bilhoes)" :
               (a == ATR_PONTOS) ? "Pontos Turisticos" :
               (a == ATR_DENSIDADE) ? "Densidade Demografica" :
               (a == ATR_PIB_PER_CAPITA) ? "PIB per Capita" :
               "Desconhecido";
    };

    auto getValor = [&](int a, int carta) -> float {
        const Carta* c = (carta == 1) ? &c1 : &c2;
        switch (a) {
            case ATR_POP:            return (float)c->populacao;
            case ATR_AREA:           return c->area;
            case ATR_PIB:            return c->pib;
            case ATR_PONTOS:         return (float)c->pontosTuristicos;
            case ATR_DENSIDADE:      return (carta == 1) ? dens1 : dens2;
            case ATR_PIB_PER_CAPITA: return (carta == 1) ? pcap1 : pcap2;
            default:                 return 0.0f;
        }
    };

    auto venceAttr = [](int atributo, float v1, float v2) {
        return (atributo == ATR_DENSIDADE) ? (v1 < v2) : (v1 > v2);
    };

    float v1_a1 = getValor(a1, 1);
    float v2_a1 = getValor(a1, 2);
    const char* nomeA1 = getNomeAtributo(a1);

    printf("\n--- Atributo 1: %s ---\n", nomeA1);
    printf("Carta 1 - %s: %.2f\n", c1.nomeCidade, v1_a1);
    printf("Carta 2 - %s: %.2f\n", c2.nomeCidade, v2_a1);

    int c1VenceA1 = venceAttr(a1, v1_a1, v2_a1) ? 1 : 0;

    if (v1_a1 == v2_a1) {
        printf("Resultado (A1): Empate\n");
    } else if (c1VenceA1) {
        printf("Resultado (A1): Carta 1 (%s) venceu\n", c1.nomeCidade);
    } else {
        printf("Resultado (A1): Carta 2 (%s) venceu\n", c2.nomeCidade);
    }

    float v1_a2 = getValor(a2, 1);
    float v2_a2 = getValor(a2, 2);
    const char* nomeA2 = getNomeAtributo(a2);

    printf("\n--- Atributo 2: %s ---\n", nomeA2);
    printf("Carta 1 - %s: %.2f\n", c1.nomeCidade, v1_a2);
    printf("Carta 2 - %s: %.2f\n", c2.nomeCidade, v2_a2);

    int c1VenceA2 = venceAttr(a2, v1_a2, v2_a2) ? 1 : 0;

    if (v1_a2 == v2_a2) {
        printf("Resultado (A2): Empate\n");
    } else if (c1VenceA2) {
        printf("Resultado (A2): Carta 1 (%s) venceu\n", c1.nomeCidade);
    } else {
        printf("Resultado (A2): Carta 2 (%s) venceu\n", c2.nomeCidade);
    }

    float soma1 = v1_a1 + v1_a2;
    float soma2 = v2_a1 + v2_a2;

    printf("\n--- Soma dos Atributos ---\n");
    printf("%s: %.2f + %.2f = %.2f\n", c1.nomeCidade, v1_a1, v1_a2, soma1);
    printf("%s: %.2f + %.2f = %.2f\n", c2.nomeCidade, v2_a1, v2_a2, soma2);

    if (soma1 > soma2) {
        printf("\n>>> Vencedora da Rodada: Carta 1 (%s)\n", c1.nomeCidade);
    } else if (soma2 > soma1) {
        printf("\n>>> Vencedora da Rodada: Carta 2 (%s)\n", c2.nomeCidade);
    } else {
        printf("\n>>> Empate!\n");
    }

    printf("========================\n");
    return 0;
}
