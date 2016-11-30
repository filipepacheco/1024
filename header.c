#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"
#include "ranking.h"
#include "personalizado.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
// ------------------------------------------------------------


// FUN��ES DO MENU PRINCIPAL

void menuPrincipal()
{
    int opcao, continua = 1; //Vari�vel de controle do loop do while

    //Print do menu principal do jogo
    printf("\tAUTORES: Filipe Pacheco de Fraga e Marcelo Audibert Chaves\n\n\n%38d!\n\n\n\t1 - Modo Cl�ssico\n\n\t2 - Modo F�cil\n\n\t3 - Modo Personalizado\n\n\t4 - Rank\n\n\t0 - Sair\n\n\t%44s\n%40s", 1024, "Qual a op��o desejada, jogador?", "OP��O: ");

    //Loop para pegar a entrada correta do usu�rio
    do
    {
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 4)
            printf("%58s\n%40s", "Desculpe, mas esta op��o � inv�lida...", "OP��O: ");
        else
            continua = 0;

    }while (continua);

    system("CLS");

    //Switch em cima do retorno da fun��o do menu, que retorna a entrada do usu�rio direcionando-o para o respectivo menu
    switch(opcao)
    {
        case 1: mainClassico(); //Cl�ssico
            break;
        case 2: //F�cil
            break;
        case 3: mainPersonalizado(); //Personalizado
            break;
        case 4: menuRanking(); //Rank
            break;
    }
}

// ------------------------------------------------------------

// FUN��O PARA IMPRIMIR NOME E PONTUA��O NA TELA

void printNomes(char nome[], int pontos) // Fun��o que imprime na parte inferior do console o nome do jogador e seus pontos
{
    int i;

    textbackground(WHITE); // Muda a cor de texto e de fundo
    textcolor(BLACK);

    for(i = 1; i <= CONSOLEX; i++) // Imprime todo o fundo branco na parte inferior do console
    {
        gotoxy(i, 1);
        printf(" ");
    }

    gotoxy(1, 1); // Move o cursor para cima
    printf("Nome do jogador: %s\t\tPontua��o: %d", nome, pontos); // Imprime o nome e pontua��o do jogador

    textbackground(BLACK);
    textcolor(WHITE);
}

// ------------------------------------------------------------

// FUN��ES DE ENTRADA DO USU�RIO ------------------------------

char getKey() // Fun��o que retorna a seta digitada pelo usu�rio
{
    fflush(stdin);
	char tecla = getch();
    int retorno;

    if(tecla == -32)
        tecla = getch();

    retorno = tecla;

    return retorno;
}

// ------------------------------------------------------------
