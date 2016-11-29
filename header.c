#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"
#include "ranking.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
// ------------------------------------------------------------


// FUNÇÕES DO MENU PRINCIPAL

void menuPrincipal()
{
    int opcao, continua = 1; //Variável de controle do loop do while

    //Print do menu principal do jogo
    printf("\tAUTORES: Filipe Pacheco de Fraga e Marcelo Audibert Chaves\n\n\n%38d!\n\n\n\t1 - Modo Clássico\n\n\t2 - Modo Fácil\n\n\t3 - Modo Personalizado\n\n\t4 - Rank\n\n\t0 - Sair\n\n\t%44s\n%40s", 1024, "Qual a opção desejada, jogador?", "OPÇÃO: ");

    //Loop para pegar a entrada correta do usuário
    do
    {
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 4)
            printf("%58s\n%40s", "Desculpe, mas esta opção é inválida...", "OPÇÃO: ");
        else
            continua = 0;

    }while (continua);

    system("CLS");

    //Switch em cima do retorno da função do menu, que retorna a entrada do usuário direcionando-o para o respectivo menu
    switch(opcao)
    {
        case 1: mainClassico(); //Clássico
            break;
        case 2: //Fácil
            break;
        case 3: //Personalizado
            break;
        case 4: menuRanking(); //Rank
            break;
    }
}

// ------------------------------------------------------------

// FUNÇÃO PARA IMPRIMIR NOME E PONTUAÇÃO NA TELA

void printNomes(char nome[], int pontos) // Função que imprime na parte inferior do console o nome do jogador e seus pontos
{
    int i;

    textbackground(WHITE); // Muda a cor de texto e de fundo
    textcolor(BLACK);

    for(i = 1; i <= CONSOLEX; i++) // Imprime todo o fundo branco na parte inferior do console
    {
        gotoxy(i, CONSOLEY - 3);
        printf(" ");
    }

    gotoxy(1, CONSOLEY - 3); // Move o cursor para baixo
    printf("Nome do jogador: %s\t\tPontuação: %d", nome, pontos); // Imprime o nome e pontuação do jogador

    textbackground(BLACK);
    textcolor(WHITE);
}

// ------------------------------------------------------------

// FUNÇÕES DE ENTRADA DO USUÁRIO ------------------------------

char getKey() // Função que retorna a seta digitada pelo usuário
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

// ------------------------------------------------------------
