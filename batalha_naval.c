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

int podePosicionarHorizontal(int tab[TAM][TAM], int linha, int col) {
    if (linha < 0 || linha >= TAM) return 0;
    if (col < 0 || col + NAVIO_TAM > TAM) return 0;

    for (int k = 0; k < NAVIO_TAM; k++) {
        if (tab[linha][col + k] != AGUA) return 0;
    }
    return 1;
}

int podePosicionarVertical(int tab[TAM][TAM], int lin, int col) {
    if (col < 0 || col >= TAM) return 0;
    if (lin < 0 || lin + NAVIO_TAM > TAM) return 0;

    for (int k = 0; k < NAVIO_TAM; k++) {
        if (tab[lin + k][col] != AGUA) return 0;
    }
    return 1;
}

int podePosicionarDiagPrincipal(int tab[TAM][TAM], int lin, int col) {
    if (lin < 0 || col < 0) return 0;
    if (lin + NAVIO_TAM > TAM || col + NAVIO_TAM > TAM) return 0;

    for (int k = 0; k < NAVIO_TAM; k++) {
        if (tab[lin + k][col + k] != AGUA) return 0;
    }
    return 1;
}

int podePosicionarDiagSecundaria(int tab[TAM][TAM], int lin, int col) {
    if (lin < 0 || col < 0) return 0;
    if (lin + NAVIO_TAM > TAM) return 0;
    if (col - (NAVIO_TAM - 1) < 0) return 0;

    for (int k = 0; k < NAVIO_TAM; k++) {
        if (tab[lin + k][col - k] != AGUA) return 0;
    }
    return 1;
}

void posicionarHorizontal(int tab[TAM][TAM], int linha, int col) {
    for (int k = 0; k < NAVIO_TAM; k++) {
        tab[linha][col + k] = NAVIO;
    }
}

void posicionarVertical(int tab[TAM][TAM], int lin, int col) {
    for (int k = 0; k < NAVIO_TAM; k++) {
        tab[lin + k][col] = NAVIO;
    }
}

void posicionarDiagPrincipal(int tab[TAM][TAM], int lin, int col) {
    for (int k = 0; k < NAVIO_TAM; k++) {
        tab[lin + k][col + k] = NAVIO;
    }
}

void posicionarDiagSecundaria(int tab[TAM][TAM], int lin, int col) {
    for (int k = 0; k < NAVIO_TAM; k++) {
        tab[lin + k][col - k] = NAVIO;
    }
}

int main(void) {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    int linH = 2, colH = 1;
    int linV = 5, colV = 7;
    int linD1 = 0, colD1 = 6;
    int linD2 = 7, colD2 = 3;

    if (podePosicionarHorizontal(tabuleiro, linH, colH)) {
        posicionarHorizontal(tabuleiro, linH, colH);
    } else {
        printf("ERRO: Navio horizontal invalido ou em sobreposicao.\n");
        return 0;
    }

    if (podePosicionarVertical(tabuleiro, linV, colV)) {
        posicionarVertical(tabuleiro, linV, colV);
    } else {
        printf("ERRO: Navio vertical invalido ou em sobreposicao.\n");
        return 0;
    }

    if (podePosicionarDiagPrincipal(tabuleiro, linD1, colD1)) {
        posicionarDiagPrincipal(tabuleiro, linD1, colD1);
    } else {
        printf("ERRO: Navio diagonal principal invalido ou em sobreposicao.\n");
        return 0;
    }

    if (podePosicionarDiagSecundaria(tabuleiro, linD2, colD2)) {
        posicionarDiagSecundaria(tabuleiro, linD2, colD2);
    } else {
        printf("ERRO: Navio diagonal secundaria invalido ou em sobreposicao.\n");
        return 0;
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
