#include "header.h"
#include <stdio.h>

int menuPrincipal()
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

    //Retorna diretamente a opção dada pelo usuário
    return opcao;
}
