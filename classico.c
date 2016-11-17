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

// MAIN DO MODO DE JOGO CL�SSICO

void mainClassico()
{
    srand( (unsigned)time(NULL) ); // Fun��o para usar o rand();

    int i,j;

    Bloco matriz[TAM][TAM]; //Declara��o da matriz de blocos que ser� usada como tabuleiro

    //Loops para inicializa��o dos blocos dentro do tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j].cor = RED; //Por padr�o, as cores ser�o associadas aos valores. Por exemplo:
            matriz[i][j].valor = 0; //O valor ZERO est� relacionado � cor VERMELHA. (Sujeito � mudan�as)
            matriz[i][j].x = j * SQUARE_WIDTH + 1; // C�lculo para inicializar a posi��o X
            matriz[i][j].y = i * SQUARE_HEIGHT + 1; // e Y do bloco para possibilitar impress�o dele
        }
    }

    //Loop para impress�o dos blocos na tela, automaticamente montando o tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            printSquare(matriz[i][j].x, matriz[i][j].y, matriz[i][j].cor); // Posi��o X, Y e COR da Struct Bloco dentro da matriz s�o passados por par�metro.
        }
    }

    aleatorio(matriz);

    moveBloco(getKey(), matriz);
}

// ---------------------------------------------------
