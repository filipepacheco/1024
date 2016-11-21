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

//


//


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
                matriz[l][c].valor = 2;
            }
            else
            {
                matriz[l][c].valor = 1;
            }
        }
    }while(continua);



    Sleep(1000);

    printSquare(matriz[l][c]);
}

// ---------------------------------------------------

//

void inicializaTabuleiro(Bloco matriz[][TAM])
{
    int i,j;

    //Loops para inicialização dos blocos dentro do tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j].valor = 0;
            matriz[i][j].x = j * SQUARE_WIDTH + 1; // Cálculo para inicializar a posição X
            matriz[i][j].y = i * SQUARE_HEIGHT + 1; // e Y do bloco para possibilitar impressão dele
        }
    }

}

//

//

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

    aleatorio(matriz);
}

//

// MAIN DO MODO DE JOGO CLÁSSICO

void mainClassico()
{
    srand( (unsigned)time(NULL) ); // Função para usar o rand();

    char nome[50];

    int *pontos;

    printf("Por gentileza, informe seu nome: ");
    fflush(stdin);
    gets(nome);

    Bloco matriz[TAM][TAM]; //Declaração da matriz de blocos que será usada como tabuleiro

    inicializaTabuleiro(matriz);

    hideCursor(); //Apaga o cursor da tela para melhor visualização

    imprimeTabuleiro(matriz);

    pontos = 0;
    while(moveBloco(getKey(), matriz, &pontos));

    printf("%d", pontos);

    cadastraJogador(nome);
}

// ---------------------------------------------------
