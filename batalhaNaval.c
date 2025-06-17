#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para verificar se a posição está dentro dos limites
int dentroDoLimite(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar sobreposição antes de posicionar
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (!dentroDoLimite(linha[i], coluna[i]) || tabuleiro[linha[i]][coluna[i]] != AGUA) {
            return 0; // Não pode posicionar
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

int main() {
    // Inicializando o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Navio Horizontal (tamanho 3)
    int navioHorizontalLinha[3] = {2, 2, 2};
    int navioHorizontalColuna[3] = {1, 2, 3};
    if (podePosicionar(tabuleiro, navioHorizontalLinha, navioHorizontalColuna, 3)) {
        posicionarNavio(tabuleiro, navioHorizontalLinha, navioHorizontalColuna, 3);
    }

    // Navio Vertical (tamanho 3)
    int navioVerticalLinha[3] = {5, 6, 7};
    int navioVerticalColuna[3] = {4, 4, 4};
    if (podePosicionar(tabuleiro, navioVerticalLinha, navioVerticalColuna, 3)) {
        posicionarNavio(tabuleiro, navioVerticalLinha, navioVerticalColuna, 3);
    }

    // Navio Diagonal Descendente (\)
    int navioDiagonal1Linha[3] = {0, 1, 2};
    int navioDiagonal1Coluna[3] = {0, 1, 2};
    if (podePosicionar(tabuleiro, navioDiagonal1Linha, navioDiagonal1Coluna, 3)) {
        posicionarNavio(tabuleiro, navioDiagonal1Linha, navioDiagonal1Coluna, 3);
    }

    // Navio Diagonal Ascendente (/)
    int navioDiagonal2Linha[3] = {7, 6, 5};
    int navioDiagonal2Coluna[3] = {0, 1, 2};
    if (podePosicionar(tabuleiro, navioDiagonal2Linha, navioDiagonal2Coluna, 3)) {
        posicionarNavio(tabuleiro, navioDiagonal2Linha, navioDiagonal2Coluna, 3);
    }

    // Exibindo o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
