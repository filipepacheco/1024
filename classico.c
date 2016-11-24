#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>

#define TAM 4
#define CONSOLEX 80
#define CONSOLEY 25
#define SQUARE_WIDTH 7
#define SQUARE_HEIGHT 5


// INICIALIZA TODO O TABULEIRO COM VALOR ZERO

void inicializaTabuleiro(Bloco matriz[][TAM])
{
    int i,j;

    //Loops para inicialização dos blocos dentro do tabuleiro
    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j].valor = 0;
            matriz[i][j].colidiu = 0;
            matriz[i][j].x = j * SQUARE_WIDTH + 1; // Cálculo para inicializar a posição X
            matriz[i][j].y = i * SQUARE_HEIGHT + 1; // e Y do bloco para possibilitar impressão dele
        }
}

// ---------------------------------------------------

// IMPRIMIR TABULEIRO NA TELA

void imprimeTabuleiro(Bloco matriz[][TAM])
{
    int i,j;

    //Loop para impressão dos blocos na tela, automaticamente montando o tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            printSquare(matriz[i][j]); // Posição X, Y e COR da Struct Bloco dentro da matriz são passados por parâmetro.
        }
    }

    aleatorio(matriz); // Gera o bloco aleatório no tabuleiro
}

// ----------------------------------------------------

// MAIN DO MODO DE JOGO CLÁSSICO

void mainClassico()
{
    srand( (unsigned)time(NULL) ); // Função para usar o rand();

    char nome[50]; // Variável para armazenar o nome do jogador

    int pontos = 0; // Os pontos inicializam zerados

    printf("Por gentileza, informe seu nome: ");
    fflush(stdin);
    gets(nome);

    system("CLS");

    Bloco matriz[TAM][TAM]; //Declaração da matriz de blocos que será usada como tabuleiro

    inicializaTabuleiro(matriz); // Inicializa toda a matriz com blocos do valor zero

    hideCursor(); //Apaga o cursor da tela para melhor visualização

    imprimeTabuleiro(matriz); // Imprime todo o tabuleiro zerado que já chama a função aleatório

    while(moveBloco(getKey(), matriz, &pontos)); // Função principal que faz o jogo ficar sendo executado

    printf("%d", pontos);

    cadastraJogador(nome); // No final do jogo, cadastra o jogador com quantos pontos ele fez e se ganhou ou não o jogo
}

// ---------------------------------------------------
