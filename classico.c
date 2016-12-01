#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"
#include "personalizado.h"

#include <stdio.h>
#include <conio2.h> // Estilização do console e movimentação do cursor
#include <windows.h> // Manipulação do console
#include <time.h> // Números randoms


// MAIN DO MODO DE JOGO CLÁSSICO

void mainClassico()
{
    int TAM = 4; // MODO CLÁSSICO POSSUI UM TABULEIRO 4X4
    int *ganhou, zero = 0;

    ganhou = &zero;

    srand( (unsigned)time(NULL) ); // Função para usar o rand();

    Jogador usuario;

    usuario.pontos = 0; // Os pontos inicializam zerados
    usuario.ganhou = 0; // O jogador começa com o sinalizador de ganhou zerado

    printf("\n\n\tPor gentileza, informe seu nome: "); // O nome do jogador é salvo na struct Jogador
    fflush(stdin);
    gets(usuario.nome);

    system("CLS");


    // Instruções do jogo
    printf("\n\n\tInstruções:\n\n\tUtilize as setas direcionais do teclado para movimentar\n\to tabuleiro! O objetivo é movimentar os blocos e juntar\n\tos que possuiremo mesmo valor.\n\tAo juntá-los, você soma o valor deles e acumula o valor\n\tsomado como pontos.\n\tSe você chegar no número 1024, parabéns, você venceu!\n\tSe o tableiro encher e você não tiver mais movimentos,\n\tvocê perde.\n\tApertar qualquer outro botão que não sejam as setas\n\tdirecionais fará com que você retorne ao menu inicial.\n\n\n\n\t");

    system("PAUSE");
    system("CLS");

    Bloco matriz[6][6]; //Declaração da matriz de blocos que será usada como tabuleiro

    inicializaTabuleiro(matriz, TAM); // Inicializa toda a matriz com blocos do valor zero

    hideCursor(); //Apaga o cursor da tela para melhor visualização

    imprimeTabuleiro(matriz, TAM); // Imprime todo o tabuleiro zerado que já chama a função aleatório

    while(moveBloco(getKey(), matriz, TAM, &usuario, ganhou)); // Função principal que faz o jogo ficar sendo executado. Por parâmetro, é passada a matriz e a struct do usuário por referência que vai sendo preenchida com os pontos e, caso ganhe, se ganhou.

    cadastraJogador(usuario); // No final do jogo, cadastra o jogador com quantos pontos ele fez e se ganhou ou não o jogo

    Sleep(200);
    system("CLS");
    menuPrincipal(); // Quando tudo termina, volta para o menu principal.
}

// ---------------------------------------------------
