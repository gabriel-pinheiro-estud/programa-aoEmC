#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define AGUA 0
#define NAVIO 3

void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

int podePosicionarHorizontal(int tab[TAM][TAM], int linha, int colInicial, int navio[], int tamanho) {
    if (linha < 0 || linha >= TAM) return 0;
    if (colInicial < 0 || colInicial + tamanho > TAM) return 0;

    for (int k = 0; k < tamanho; k++) {
        if (tab[linha][colInicial + k] != AGUA) {
            return 0;
        }
    }
    return 1;
}

int podePosicionarVertical(int tab[TAM][TAM], int linInicial, int coluna, int navio[], int tamanho) {
    if (coluna < 0 || coluna >= TAM) return 0;
    if (linInicial < 0 || linInicial + tamanho > TAM) return 0;

    for (int k = 0; k < tamanho; k++) {
        if (tab[linInicial + k][coluna] != AGUA) {
            return 0;
        }
    }
    return 1;
}

void posicionarHorizontal(int tab[TAM][TAM], int linha, int colInicial, int navio[], int tamanho) {
    for (int k = 0; k < tamanho; k++) {
        tab[linha][colInicial + k] = navio[k];
    }
}

void posicionarVertical(int tab[TAM][TAM], int linInicial, int coluna, int navio[], int tamanho) {
    for (int k = 0; k < tamanho; k++) {
        tab[linInicial + k][coluna] = navio[k];
    }
}

void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\nTabuleiro (0 = agua, 3 = navio):\n\n");

    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int tabuleiro[TAM][TAM];

    int navioHorizontal[NAVIO_TAM] = { NAVIO, NAVIO, NAVIO };
    int navioVertical[NAVIO_TAM]   = { NAVIO, NAVIO, NAVIO };

    int linhaH = 2;
    int colH   = 1;
    int linhaV = 5;
    int colV   = 7;

    inicializarTabuleiro(tabuleiro);

    if (podePosicionarHorizontal(tabuleiro, linhaH, colH, navioHorizontal, NAVIO_TAM)) {
        posicionarHorizontal(tabuleiro, linhaH, colH, navioHorizontal, NAVIO_TAM);
    } else {
        printf("ERRO: Coordenadas invalidas para o navio horizontal (ou sobreposicao).\n");
        return 0;
    }

    if (podePosicionarVertical(tabuleiro, linhaV, colV, navioVertical, NAVIO_TAM)) {
        posicionarVertical(tabuleiro, linhaV, colV, navioVertical, NAVIO_TAM);
    } else {
        printf("ERRO: Coordenadas invalidas para o navio vertical (ou sobreposicao).\n");
        return 0;
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
