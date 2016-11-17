#include "bloco.h"
#include "classico.h"
#include "header.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
//#include <ctype.h>

#define SQUARE_WIDTH 6
#define SQUARE_HEIGHT 4
#define COLOR 0x44
#define VEL 1
#define CONSOLEX 80
#define CONSOLEY 25
#define XMAIN 25
#define YMAIN 10

void hideCursor()
{
    CONSOLE_CURSOR_INFO info = {100, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void forSquare(int x, int y)
{
    int i,j;

    // Interação para impressão do bloco blaseada no SQUARE_WIDTH
    for(i = x; i < x + SQUARE_WIDTH; i++)
    {
        for(j = y; j < y + SQUARE_HEIGHT; j++)
        {
            gotoxy(i,j);


            // AQUI DEVE IR UMA LÓGICA QUE FAZ IMPRIMIR O bloco.valor DO BLOCO NO CENTRO DO QUADRADO!


            printf(" ");
        }
    }
}

// Função feita em aula para printar os quadrados
void printSquare(int x, int y, int color)
{
    textbackground(color);
    forSquare(x,y);
    textbackground(BLACK);
}

void moveBloco(char key, Bloco matriz[][TAM])
{
    int i,j;

    switch(key)
    {
        case 72: // CIMA
            for (i = 0; i < TAM; i++)
            {
                for(j = 0; j < TAM; j++)
                {
                    if (matriz[i][j].valor > 0)
                    {
                        printf("%d",matriz[i][j].x);
                    }
                }
            }
            break;
        case 77: // DIREITA
            break;
        case 75: // ESQUERDA
            break;
        case 80: // BAIXO
            break;

    }
}


/*
void eraseSquare(int x, int y)
{
    forSquare(x,y);
}

int canMove(int x, int y, int modX, int modY)
{
    int retorno = 1;
    if( ((x + modX) > CONSOLEX - SQUARE_WIDTH) || ((y + modY > CONSOLEY - SQUARE_HEIGHT)) || ((x + modX) < 1) || ((y+modY < 1)) )
    {
        retorno = 0;
    }
    return retorno;
}

void getModXY(char key, int *modX, int *modY)
{
    switch(key)
    {
        case 77:
            *modX = VEL;
            *modY = 0;
            break;
        case 75:
            *modX = -VEL;
            *modY = 0;
            break;
        case 80:
            *modY = VEL;
            *modX = 0;
            break;
        case 72:
            *modY = -VEL;
            *modX = 0;
            break;
    }
}



void whileMain()
{
    hideCursor();

    int x = XMAIN, y = YMAIN, modX, modY, key;
    do
    {
        key = getKey();
        getModXY(key, &modX, &modY);

        if(canMove(x, y, modX, modY)) {
            eraseSquare(x, y);
            x += modX;
            y += modY;

            printSquare(x, y, COLOR);
        }
    } while (key != 27);
}
*/
