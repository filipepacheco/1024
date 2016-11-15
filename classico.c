#include "classico.h"

#include <stdio.h>
#include <conio2.h>

#define TAM 5
#define TOTAL 20

// IMPRIMIR TABULEIRO NA TELA

void imprimeTabuleiro()
{
    int x, y, inicioX = 1, inicioY = 1;

    //textbackground(RED);

    for(x = inicioX; x < inicioX + TOTAL; x++)
    {
        for(y = inicioY; y < inicioY + TOTAL; y++)
        {

            if (y % TAM == 0 && y != TOTAL){
                gotoxy(x,y);
                printf("_");
            }else if(x % TAM == 0 && x != TOTAL){
                gotoxy(x,y);
                printf("|");
            }//else{
               // gotoxy(x,y);
                //printf(" ");
          //  }
        }
    }

    textbackground(BLACK);

    gotoxy(15,15);
    system("pause");
}

// ---------------------------------------------------

// MAIN DO MODO DE JOGO CLÁSSICO

void mainClassico()
{
    Bloco matrizPrincipal[TAM][TAM];

    int i, j;

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matrizPrincipal[i][j].cor = i;
            matrizPrincipal[i][j].valor = j;
        }
    }

    imprimeTabuleiro();
}

// ---------------------------------------------------
