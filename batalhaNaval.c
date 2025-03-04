#include <stdio.h>

#define TAMANHO 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água e alguns navios
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    // Posiciona alguns navios
    tabuleiro[4][4] = NAVIO;
    tabuleiro[5][4] = NAVIO;
    tabuleiro[6][4] = NAVIO;
}

// Função para sobrepor a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int x, int y) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tab_x = x + i - TAM_HABILIDADE / 2;
            int tab_y = y + j - TAM_HABILIDADE / 2;
            if (tab_x >= 0 && tab_x < TAMANHO && tab_y >= 0 && tab_y < TAMANHO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[tab_x][tab_y] = HABILIDADE;
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para criar a matriz de efeito da habilidade Cone
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de efeito da habilidade Cruz
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de efeito da habilidade Octaedro
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];
    
    inicializarTabuleiro(tabuleiro);
    
    // Teste com a habilidade Cone
    criarHabilidadeCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 4);
    imprimirTabuleiro(tabuleiro);
    printf("\n");
    
    // Teste com a habilidade Cruz
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    imprimirTabuleiro(tabuleiro);
    printf("\n");
    
    // Teste com a habilidade Octaedro
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    imprimirTabuleiro(tabuleiro);

    
    
    return 0;
}