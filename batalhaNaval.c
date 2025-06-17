#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro (10x10), inicializada com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaNavioVertical = 2;  // Linha inicial do navio vertical
    int colunaNavioVertical = 4; // Coluna inicial do navio vertical

    int linhaNavioHorizontal = 7; // Linha inicial do navio horizontal
    int colunaNavioHorizontal = 1; // Coluna inicial do navio horizontal

    // Vetores representando os navios (cada um com 3 partes)
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // === Posicionando o navio vertical ===
    // Verificação de limites antes de posicionar
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = navioVertical[i];
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // === Posicionando o navio horizontal ===
    // Verificação de limites antes de posicionar
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Validação para evitar sobreposição
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == NAVIO) {
                printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
                return 1;
            }
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // === Exibindo o tabuleiro ===
    printf("\n=== Tabuleiro da Batalha Naval ===\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
