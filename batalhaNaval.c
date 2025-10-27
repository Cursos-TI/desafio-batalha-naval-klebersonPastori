#include <stdio.h>

#define TAMANHO 10   // Tamanho fixo do tabuleiro
#define NAVIO 4      // Valor que representa parte do navio
#define AGUA 0       // Valor que representa água
#define TAM_NAVIO 4  // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    char colunas[TAMANHO] = {'A','B','C','D','E','F','G','H','I','J'};

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    // Navio horizontal
    int linhaH = 2, colunaH = 4; // começa na linha 2, coluna 4
    // Navio vertical
    int linhaV = 5, colunaV = 7; // começa na linha 5, coluna 7

    // Validação: verificar se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO <= TAMANHO) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    // Validação: verificar se o navio vertical cabe no tabuleiro
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
        } else {
            printf("Erro: Navios se sobrepõem!\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // Exibir o tabuleiro com legenda
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    // Cabeçalho das colunas
    printf("   "); // espaço para alinhar com a numeração das linhas
    for (int j = 0; j < TAMANHO; j++) {
        printf("%c ", colunas[j]);
    }
    printf("\n");

    // Linhas numeradas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i+1); // imprime número da linha (1–10) alinhado
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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

    

