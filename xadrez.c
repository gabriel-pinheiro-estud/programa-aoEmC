#include <stdio.h>


void moverTorreDireitaRec(int casasRestantes);
void moverBispoCimaDireitaRec(int casasRestantes);
void moverRainhaEsquerdaRec(int casasRestantes);

const int TORRE_PASSOS   = 5;
const int BISPO_PASSOS   = 5;
const int RAINHA_PASSOS  = 8;

void moverTorreDireitaRec(int casasRestantes) {
    if (casasRestantes <= 0) {
        return;
    }

    printf("Direita\n");

    moverTorreDireitaRec(casasRestantes - 1);
}

void moverBispoCimaDireitaRec(int casasRestantes) {
    if (casasRestantes <= 0) {
        return;
    }

    for (int v = 0; v < 1; v++) {
        printf("Cima\n");
        for (int h = 0; h < 1; h++) {
            printf("Direita\n");
        }
    }

    moverBispoCimaDireitaRec(casasRestantes - 1);
}

void moverRainhaEsquerdaRec(int casasRestantes) {
    if (casasRestantes <= 0) {
        return;
    }

    printf("Esquerda\n");

    moverRainhaEsquerdaRec(casasRestantes - 1);
}

void moverCavaloCimaDireita(void) {
    const int fasesTotais = 3;

    for (int fase = 1; fase <= fasesTotais; fase++) {
        int passosAlvo = (fase < 3) ? 1 : 1;

        int passo = 0;
        while (passo <= passosAlvo) {
            if (passo == 0) {
                passo++;
                continue;
            }

            if (fase == 1 || fase == 2) {
                printf("Cima\n");
            } else {
                printf("Direita\n");
            }

            if (passo == passosAlvo) {
                break;
            }

            passo++;
        }
    }
}

int main(void) {
    printf("Movimento da Torre (recursivo):\n");
    moverTorreDireitaRec(TORRE_PASSOS);

    printf("\nMovimento do Bispo (recursivo + loops aninhados):\n");
    moverBispoCimaDireitaRec(BISPO_PASSOS);

    printf("\nMovimento da Rainha (recursivo):\n");
    moverRainhaEsquerdaRec(RAINHA_PASSOS);

    printf("\nMovimento do Cavalo (loops aninhados c/ continue/break):\n");
    moverCavaloCimaDireita();

    return 0;
}
