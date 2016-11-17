#include "bloco.h"
#include "classico.h"
#include "header.h"

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

    int continua = 1, l, c;
    float valor;

    do
    {
        l = rand() % TAM;
        c = rand() % TAM;

        if(matriz[l][c].valor == 0)
        {
            continua = 0;

            valor = rand() % 5;

            if(valor > 2)
            {
                matriz[l][c].valor = 4;
            }
            else
            {
                matriz[l][c].valor = 2;
            }
        }
    }while(continua);



    Sleep(1000);

    printSquare(matriz[l][c]);
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
            matriz[i][j].valor = 0;
            matriz[i][j].x = j * SQUARE_WIDTH + 1; // C�lculo para inicializar a posi��o X
            matriz[i][j].y = i * SQUARE_HEIGHT + 1; // e Y do bloco para possibilitar impress�o dele
        }
    }

    //Loop para impress�o dos blocos na tela, automaticamente montando o tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            printSquare(matriz[i][j]); // Posi��o X, Y e COR da Struct Bloco dentro da matriz s�o passados por par�metro.
        }
    }

    aleatorio(matriz);

    while (moveBloco(getKey(), matriz));

}

// ---------------------------------------------------
