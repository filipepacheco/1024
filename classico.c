#include "classico.h"
#include "header.h"
#include "bloco.h"

#include <stdio.h>
#include <conio2.h>

#define TAM 4
#define CONSOLEX 80
#define CONSOLEY 25
#define SQUARE_WIDTH 5
#define SQUARE_HEIGHT 4

// IMPRIMIR TABULEIRO NA TELA


// ---------------------------------------------------

// MAIN DO MODO DE JOGO CLÁSSICO

void aleatorio(Bloco matriz[][TAM])
{
    srand( (unsigned)time(NULL) );

    int l = rand() % TAM + 1;
    int c = rand() % TAM + 1;

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

    printSquare(matriz[l][c].x, matriz[l][c].y, matriz[l][c].cor);
}

void mainClassico()
{
    srand( (unsigned)time(NULL) );

    Bloco matriz[TAM][TAM];
    int i,j;

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j].cor = RED;
            matriz[i][j].valor = 0;
            matriz[i][j].x = j * SQUARE_WIDTH + 1;
            matriz[i][j].y = i * SQUARE_HEIGHT + 1;
        }
    }

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            printSquare(matriz[i][j].x, matriz[i][j].y, matriz[i][j].cor);
        }
    }

    aleatorio(matriz);
}

// ---------------------------------------------------
