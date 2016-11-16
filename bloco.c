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

    for(i = x; i < x + SQUARE_WIDTH; i++)
    {
        for(j = y; j < y + SQUARE_HEIGHT; j++)
        {
            gotoxy(i,j);

            printf(" ");
        }
    }
}

void printSquare(int x, int y, int color)
{
    textbackground(color);
    forSquare(x,y);
    textbackground(BLACK);
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

int whileGetKey()
{
    char tecla = getch();
    int retorno, flag = 0;

    do
    {
        if(tecla == -32)
        {
            tecla = getch();
            switch(tecla)
            {
                case 72: //cima
                case 77: //direita
                case 75: //esquerda
                case 80: //baixo
                    retorno = tecla;
                    flag = 1;
                    break;
            }
        }else{
            switch(tecla)
            {
                case 27: //esc
                    retorno = tecla;
                    flag = 1;
                    break;
            }
        }
    }while(flag == 0);

    return retorno;
}

char getKey()
{
	return whileGetKey();
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
