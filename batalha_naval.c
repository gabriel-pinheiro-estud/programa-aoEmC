#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define H 5
#define AGUA 0
#define NAVIO 3
#define EFEITO 5

void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;
}

void exibirComEfeito(int tab[TAM][TAM], int efeito[TAM][TAM], const char* titulo) {
    printf("\n%s\n\n", titulo);

    printf("   ");
    for (int j = 0; j < TAM; j++) printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            int v = AGUA;
            if (tab[i][j] == NAVIO) v = NAVIO;
            else if (efeito[i][j] == 1) v = EFEITO;
            printf("%2d ", v);
        }
        printf("\n");
    }
}

void zerarEfeito(int efeito[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            efeito[i][j] = 0;
}

int podeHorizontal(int tab[TAM][TAM], int linha, int col) {
    if (linha < 0 || linha >= TAM) return 0;
    if (col < 0 || col + NAVIO_TAM > TAM) return 0;
    for (int k = 0; k < NAVIO_TAM; k++)
        if (tab[linha][col + k] != AGUA) return 0;
    return 1;
}
void posicionarHorizontal(int tab[TAM][TAM], int linha, int col) {
    for (int k = 0; k < NAVIO_TAM; k++)
        tab[linha][col + k] = NAVIO;
}

int podeVertical(int tab[TAM][TAM], int lin, int col) {
    if (col < 0 || col >= TAM) return 0;
    if (lin < 0 || lin + NAVIO_TAM > TAM) return 0;
    for (int k = 0; k < NAVIO_TAM; k++)
        if (tab[lin + k][col] != AGUA) return 0;
    return 1;
}
void posicionarVertical(int tab[TAM][TAM], int lin, int col) {
    for (int k = 0; k < NAVIO_TAM; k++)
        tab[lin + k][col] = NAVIO;
}

int podeDiagPrincipal(int tab[TAM][TAM], int lin, int col) {
    if (lin < 0 || col < 0) return 0;
    if (lin + NAVIO_TAM > TAM || col + NAVIO_TAM > TAM) return 0;
    for (int k = 0; k < NAVIO_TAM; k++)
        if (tab[lin + k][col + k] != AGUA) return 0;
    return 1;
}
void posicionarDiagPrincipal(int tab[TAM][TAM], int lin, int col) {
    for (int k = 0; k < NAVIO_TAM; k++)
        tab[lin + k][col + k] = NAVIO;
}

int podeDiagSecundaria(int tab[TAM][TAM], int lin, int col) {
    if (lin < 0 || col < 0) return 0;
    if (lin + NAVIO_TAM > TAM) return 0;
    if (col - (NAVIO_TAM - 1) < 0) return 0;
    for (int k = 0; k < NAVIO_TAM; k++)
        if (tab[lin + k][col - k] != AGUA) return 0;
    return 1;
}
void posicionarDiagSecundaria(int tab[TAM][TAM], int lin, int col) {
    for (int k = 0; k < NAVIO_TAM; k++)
        tab[lin + k][col - k] = NAVIO;
}

void zerarHabilidade(int m[H][H]) {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < H; j++)
            m[i][j] = 0;
}

void construirCone(int cone[H][H]) {
    zerarHabilidade(cone);
    int mid = H / 2;
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < H; c++) {
            int dif = c - mid;
            if (dif < 0) dif = -dif;
            if (dif <= r) cone[r][c] = 1;
            else cone[r][c] = 0;
        }
    }
}

void construirCruz(int cruz[H][H]) {
    zerarHabilidade(cruz);
    int mid = H / 2;
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < H; c++) {
            if (r == mid || c == mid) cruz[r][c] = 1;
            else cruz[r][c] = 0;
        }
    }
}

void construirOctaedro(int oct[H][H]) {
    zerarHabilidade(oct);
    int mid = H / 2;
    int raio = mid;
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < H; c++) {
            int dr = r - mid; if (dr < 0) dr = -dr;
            int dc = c - mid; if (dc < 0) dc = -dc;
            if (dr + dc <= raio) oct[r][c] = 1;
            else oct[r][c] = 0;
        }
    }
}

void aplicarHabilidade(int efeito[TAM][TAM],
                       int hab[H][H],
                       int ancLin, int ancCol,
                       int offLin, int offCol) {
    int topo = ancLin - offLin;
    int esquerda = ancCol - offCol;

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < H; c++) {
            if (hab[r][c] == 1) {
                int tr = topo + r;
                int tc = esquerda + c;
                if (tr >= 0 && tr < TAM && tc >= 0 && tc < TAM) {
                    efeito[tr][tc] = 1;
                }
            }
        }
    }
}

int main(void) {
    int tab[TAM][TAM];
    inicializarTabuleiro(tab);

    int linH = 2, colH = 1;
    int linV = 5, colV = 7;
    int linD1 = 0, colD1 = 6;
    int linD2 = 7, colD2 = 3;

    if (!podeHorizontal(tab, linH, colH))  { printf("ERRO: horizontal invalido.\n"); return 0; }
    if (!podeVertical(tab,   linV, colV))  { printf("ERRO: vertical invalido.\n");   return 0; }
    if (!podeDiagPrincipal(tab, linD1, colD1)) { printf("ERRO: diag principal invalida.\n"); return 0; }
    if (!podeDiagSecundaria(tab, linD2, colD2)) { printf("ERRO: diag secundaria invalida.\n"); return 0; }

    posicionarHorizontal(tab, linH, colH);
    posicionarVertical(tab,   linV, colV);
    posicionarDiagPrincipal(tab, linD1, colD1);
    posicionarDiagSecundaria(tab, linD2, colD2);

    int cone[H][H], cruz[H][H], oct[H][H];
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(oct);

    int efeitoVazio[TAM][TAM]; zerarEfeito(efeitoVazio);
    exibirComEfeito(tab, efeitoVazio, "TABULEIRO BASE (sem habilidade)");

    int efeitoCone[TAM][TAM]; zerarEfeito(efeitoCone);
    aplicarHabilidade(efeitoCone, cone, 1, 4, 0, H/2);
    exibirComEfeito(tab, efeitoCone, "HABILIDADE: CONE (origem = ápice em 1,4)");

    int efeitoCruz[TAM][TAM]; zerarEfeito(efeitoCruz);
    aplicarHabilidade(efeitoCruz, cruz, 6, 2, H/2, H/2);
    exibirComEfeito(tab, efeitoCruz, "HABILIDADE: CRUZ (origem = centro em 6,2)");

    int efeitoOct[TAM][TAM]; zerarEfeito(efeitoOct);
    aplicarHabilidade(efeitoOct, oct, 5, 7, H/2, H/2);
    exibirComEfeito(tab, efeitoOct, "HABILIDADE: OCTAEDRO (origem = centro em 5,7)");

    printf("\nLegenda: 0=agua | 3=navio | 5=area de habilidade\n");
    return 0;
}
