#include "classico.h"
#include "header.h"
#include "bloco.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>

#define TAM 4
#define CONSOLEX 80
#define CONSOLEY 25
#define SQUARE_WIDTH 7
#define SQUARE_HEIGHT 5

// IMPRIMIR TABULEIRO NA TELA


void aleatorio(Bloco matriz[][TAM])
{
    srand( (unsigned)time(NULL) );

    int l = rand() % TAM;
    int c = rand() % TAM;

    int valor = rand() % 5;
    if(valor == 3)
    {
        matriz[l][c].valor = 4;
        matriz[l][c].cor = YELLOW;
    }
    else
    {
        matriz[l][c].valor = 2;
        matriz[l][c].cor = BLUE;
    }

    Sleep(1000);

    printSquare(matriz[l][c].x, matriz[l][c].y, matriz[l][c].cor);
}

// ---------------------------------------------------

// MAIN DO MODO DE JOGO CLÁSSICO

void mainClassico()
{
    srand( (unsigned)time(NULL) ); // Função para usar o rand();

    int i,j;

    Bloco matriz[TAM][TAM]; //Declaração da matriz de blocos que será usada como tabuleiro

    //Loops para inicialização dos blocos dentro do tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j].cor = RED; //Por padrão, as cores serão associadas aos valores. Por exemplo:
            matriz[i][j].valor = 0; //O valor ZERO está relacionado à cor VERMELHA. (Sujeito à mudanças)
            matriz[i][j].x = j * SQUARE_WIDTH + 1; // Cálculo para inicializar a posição X
            matriz[i][j].y = i * SQUARE_HEIGHT + 1; // e Y do bloco para possibilitar impressão dele
        }
    }

    //Loop para impressão dos blocos na tela, automaticamente montando o tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            printSquare(matriz[i][j].x, matriz[i][j].y, matriz[i][j].cor); // Posição X, Y e COR da Struct Bloco dentro da matriz são passados por parâmetro.
        }
    }

    aleatorio(matriz);

    moveBloco(getKey(), matriz);
}

// ---------------------------------------------------
