#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// ------------------------------------------------------------


// FUN��ES DO MENU PRINCIPAL

void menuPrincipal()
{
    int opcao, continua = 1; //Vari�vel de controle do loop do while

    //Print do menu principal do jogo
    printf("\tAUTORES: Filipe Pacheco de Fraga e Marcelo Audibert Chaves\n\n\n%38d!\n\n\n\t1 - Modo Cl�ssico\n\n\t2 - Modo F�cil\n\n\t3 - Modo Personalizado\n\n\t4 - Rank\n\n\t0 - Sair\n\n\t%44s\n%40s", 1024, "Qual a op��o desejada, jogador?", "OP��O: ");

    //Loop para pegar a entrada correta do usu�rio
    /*do
    {
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 4)
            printf("%58s\n%40s", "Desculpe, mas esta op��o � inv�lida...", "OP��O: ");
        else
            continua = 0;

    }while (continua);*/

    opcao = 1;

    system("CLS");

    //Switch em cima do retorno da fun��o do menu, que retorna a entrada do usu�rio direcionando-o para o respectivo menu
    switch(opcao)
    {
        case 1: mainClassico(); //Cl�ssico
            break;
        case 2: //F�cil
            break;
        case 3: //Personalizado
            break;
        case 4: //Rank
            break;
    }
}

// ------------------------------------------------------------

// FUN��ES DE ENTRADA DO USU�RIO ------------------------------

char getKey()
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


//

void printNomes()
{

}

//
