#include <stdio.h>

#define TAMANHO 10     // Tamanho fixo do tabuleiro
#define NAVIO 3        // Valor que representa parte do navio
#define AGUA 0         // Valor que representa água
#define TAM_NAVIO 3    // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    char colunas[TAMANHO] = {'A','B','C','D','E','F','G','H','I','J'};

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio horizontal
    int linhaH = 1, colunaH = 2;
    if (colunaH + TAM_NAVIO <= TAMANHO) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }
    }

    // Navio vertical
    int linhaV = 4, colunaV = 6;
    if (linhaV + TAM_NAVIO <= TAMANHO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // Navio diagonal principal (↘)
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + TAM_NAVIO <= TAMANHO && colunaD1 + TAM_NAVIO <= TAMANHO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // Navio diagonal secundária (↙)
    int linhaD2 = 0, colunaD2 = 9;
    if (linhaD2 + TAM_NAVIO <= TAMANHO && colunaD2 - TAM_NAVIO + 1 >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    // Exibir o tabuleiro
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%c ", colunas[j]);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    

