#include <stdio.h>

#define TAM 10          // Tamanho do tabuleiro
#define AGUA 0          // Representa água
#define NAVIO 3         // Representa navio
#define AREA_AFETADA 5  // Representa área atingida por habilidade especial

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== Tabuleiro Atual ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {           // Percorre a matriz de habilidade (5x5)
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {    // Se a posição faz parte da habilidade
                int linhaTab = origemLinha + (i - 2); // Ajuste para centralizar
                int colunaTab = origemColuna + (j - 2);
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = AREA_AFETADA; // Marca como área afetada
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // ---------------- POSICIONANDO NAVIOS ----------------
    // Exemplo de navio horizontal
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;

    // Exemplo de navio vertical
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    // Exemplo de navio diagonal descendente (\)
    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;

    // Exemplo de navio diagonal ascendente (/)
    tabuleiro[9][0] = NAVIO;
    tabuleiro[8][1] = NAVIO;
    tabuleiro[7][2] = NAVIO;

    // ---------------- MATRIZES DE HABILIDADE ----------------
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Construindo a habilidade "Cone"
    for (int i = 0; i < 5; i++) {          // Linhas
        for (int j = 0; j < 5; j++) {      // Colunas
            if (j >= 2 - i && j <= 2 + i && i <= 2) {
                cone[i][j] = 1;
            }
        }
    }

    // Construindo a habilidade "Cruz"
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // Linha central
        cruz[i][2] = 1; // Coluna central
    }

    // Construindo a habilidade "Octaedro"
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ---------------- APLICANDO AS HABILIDADES AO TABULEIRO ----------------
    aplicarHabilidade(tabuleiro, cone, 3, 3);        // Exemplo: Cone centrado em (3,3)
    aplicarHabilidade(tabuleiro, cruz, 6, 2);        // Cruz centrada em (6,2)
    aplicarHabilidade(tabuleiro, octaedro, 5, 8);    // Octaedro centrado em (5,8)

    // ---------------- EXIBINDO O TABULEIRO FINAL ----------------
    exibirTabuleiro(tabuleiro);

    return 0;
}
