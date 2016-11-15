#include "header.h"
#include "classico.h"

#include <stdio.h>
// ------------------------------------------------------------


// FUNÇÕES DO MENU PRINCIPAL

void menuPrincipal()
{
    int opcao, continua = 1; //Variável de controle do loop do while

    //Print do menu principal do jogo
    printf("\tAUTORES: Filipe Pacheco de Fraga e Marcelo Audibert Chaves\n\n\n%38d!\n\n\n\t1 - Modo Clássico\n\n\t2 - Modo Fácil\n\n\t3 - Modo Personalizado\n\n\t4 - Rank\n\n\t0 - Sair\n\n\t%44s\n%40s", 1024, "Qual a opção desejada, jogador?", "OPÇÃO: ");

    //Loop para pegar a entrada correta do usuário
    /*do
    {
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 4)
            printf("%58s\n%40s", "Desculpe, mas esta opção é inválida...", "OPÇÃO: ");
        else
            continua = 0;

    }while (continua);*/

    opcao = 1;

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
        case 4: //Rank
            break;
    }
}

// ------------------------------------------------------------


