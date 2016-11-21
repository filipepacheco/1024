#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

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

// Função feita em aula para printar os quadrados
void printSquare(Bloco bloco)
{
    int i,j;

    switch(bloco.valor)
    {
    case 0: bloco.cor = CYAN; break;
    case 1: bloco.cor = LIGHTRED; break;
    case 2: bloco.cor = GREEN; break;
    case 4: bloco.cor = BLUE; break;
    case 8: bloco.cor = RED; break;
    case 16: bloco.cor = MAGENTA; break;
    case 32: bloco.cor = BROWN; break;
    case 64: bloco.cor = LIGHTGRAY; break;
    case 128: bloco.cor = DARKGRAY; break;
    case 256: bloco.cor = LIGHTBLUE; break;
    case 512: bloco.cor = LIGHTGREEN; break;
    case 1024: bloco.cor = YELLOW; break;
    }

    textbackground(bloco.cor);
    textcolor(WHITE);

    // Interação para impressão do bloco blaseada no SQUARE_WIDTH
    for(i = bloco.x; i < bloco.x + SQUARE_WIDTH; i++)
    {
        for(j = bloco.y; j < bloco.y + SQUARE_HEIGHT; j++)
        {
            gotoxy(i,j);

            if (i == bloco.x + SQUARE_WIDTH / 2 && j == bloco.y + SQUARE_HEIGHT / 2 && bloco.valor > 0)
            {
                if(bloco.valor < 100)
                    gotoxy(i-1,j);
                if(bloco.valor > 100)
                    gotoxy(i-2,j);
                if(bloco.valor > 1000)
                    gotoxy(i-3,j);

                printf("%d", bloco.valor);
            }

            printf(" ");
        }
    }

    textbackground(BLACK);
}

int moveBloco(char key, Bloco matriz[][TAM], int *pontos)
{
    Bloco aux;

    int x,y, retorno = 1, cont = 0, contaux = 0;

    switch(key)
    {
        case 72: // CIMA (y + (-1)), (x + 0)
            do
            {
                cont = 0;
                for (x = 0; x < TAM; x++)
                {
                    for(y = 1; y < TAM; y++)
                    {
                        aux = matriz[y][x];
                        if (aux.valor > 0 && (matriz[y - 1][x].valor == aux.valor || matriz[y - 1][x].valor == 0))
                        {
                            contaux = 1;
                            cont++;
                            matriz[y - 1][x].valor += aux.valor;
                            pontos += aux.valor;
                            Sleep(10);
                            printSquare(matriz[y-1][x]);
                            matriz[y][x].valor = 0;
                            Sleep(10);
                            printSquare(matriz[y][x]);
                        }
                    }
                }
            }while(cont);
            break;
        case 77: // DIREITA (y + 0), (x + 1)
            do
            {
                cont = 0;
                for (y = 0; y < TAM; y++)
                {
                    for(x = TAM - 2; x >= 0; x--)
                    {
                        aux = matriz[y][x];
                        if (aux.valor > 0 && (matriz[y][x+1].valor == aux.valor || matriz[y][x+1].valor == 0))
                        {
                            cont++;
                            contaux = 1;
                            matriz[y][x+1].valor += aux.valor;
                            Sleep(10);
                            printSquare(matriz[y][x+1]);
                            matriz[y][x].valor = 0;
                            Sleep(10);
                            printSquare(matriz[y][x]);
                        }
                    }
                }
            }while(cont);
            break;
        case 75: // ESQUERDA
            do
            {
                cont = 0;
                for (y = 0; y < TAM; y++)
                {
                    for(x = 1; x < TAM; x++)
                    {
                        aux = matriz[y][x];
                        if (aux.valor > 0 && (matriz[y][x-1].valor == aux.valor || matriz[y][x-1].valor == 0))
                        {
                            cont++;
                            contaux = 1;
                            matriz[y][x-1].valor += aux.valor;
                            Sleep(10);
                            printSquare(matriz[y][x-1]);
                            matriz[y][x].valor = 0;
                            Sleep(10);
                            printSquare(matriz[y][x]);
                        }
                    }
                }
            }while(cont);
            break;
        case 80: // BAIXO (y + 1), (x + 0)
            do
            {
                cont = 0;
                for (x = 0; x < TAM; x++)
                {
                    for(y = TAM - 2; y >= 0; y--)
                    {
                        aux = matriz[y][x];
                        if (aux.valor > 0 && (matriz[y+1][x].valor == aux.valor || matriz[y+1][x].valor == 0))
                        {
                            cont++;
                            contaux = 1;
                            matriz[y+1][x].valor += aux.valor;
                            Sleep(10);
                            printSquare(matriz[y+1][x]);
                            matriz[y][x].valor = 0;
                            Sleep(10);
                            printSquare(matriz[y][x]);
                        }
                    }
                }
            }while(cont);
            break;
        default:
            retorno = 0;
    }

    if(contaux)
        aleatorio(matriz);

    return retorno;
}
