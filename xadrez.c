#include <stdio.h>

int main(void) {
    int movimentosTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= movimentosTorre; i++) {
        printf("Direita (casa %d)\n", i);
    }

    int movimentosBispo = 5;
    int i = 1;
    printf("\nMovimento do Bispo:\n");
    while (i <= movimentosBispo) {
        printf("Cima, Direita (casa %d)\n", i);
        i++;
    }

    int movimentosRainha = 8;
    int j = 1;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda (casa %d)\n", j);
        j++;
    } while (j <= movimentosRainha);

    return 0;
}
