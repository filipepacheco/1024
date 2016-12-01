#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"
#include "personalizado.h"

#include <stdio.h>
#include <conio2.h> // Estiliza��o do console e movimenta��o do cursor
#include <windows.h> // Manipula��o do console
#include <time.h> // N�meros randoms


// MAIN DO MODO DE JOGO CL�SSICO

void mainClassico()
{
    int TAM = 4; // MODO CL�SSICO POSSUI UM TABULEIRO 4X4
    int *ganhou, zero = 0;

    ganhou = &zero;

    srand( (unsigned)time(NULL) ); // Fun��o para usar o rand();

    Jogador usuario;

    usuario.pontos = 0; // Os pontos inicializam zerados
    usuario.ganhou = 0; // O jogador come�a com o sinalizador de ganhou zerado

    printf("\n\n\tPor gentileza, informe seu nome: "); // O nome do jogador � salvo na struct Jogador
    fflush(stdin);
    gets(usuario.nome);

    system("CLS");


    // Instru��es do jogo
    printf("\n\n\tInstru��es:\n\n\tUtilize as setas direcionais do teclado para movimentar\n\to tabuleiro! O objetivo � movimentar os blocos e juntar\n\tos que possuiremo mesmo valor.\n\tAo junt�-los, voc� soma o valor deles e acumula o valor\n\tsomado como pontos.\n\tSe voc� chegar no n�mero 1024, parab�ns, voc� venceu!\n\tSe o tableiro encher e voc� n�o tiver mais movimentos,\n\tvoc� perde.\n\tApertar qualquer outro bot�o que n�o sejam as setas\n\tdirecionais far� com que voc� retorne ao menu inicial.\n\n\n\n\t");

    system("PAUSE");
    system("CLS");

    Bloco matriz[6][6]; //Declara��o da matriz de blocos que ser� usada como tabuleiro

    inicializaTabuleiro(matriz, TAM); // Inicializa toda a matriz com blocos do valor zero

    hideCursor(); //Apaga o cursor da tela para melhor visualiza��o

    imprimeTabuleiro(matriz, TAM); // Imprime todo o tabuleiro zerado que j� chama a fun��o aleat�rio

    while(moveBloco(getKey(), matriz, TAM, &usuario, ganhou)); // Fun��o principal que faz o jogo ficar sendo executado. Por par�metro, � passada a matriz e a struct do usu�rio por refer�ncia que vai sendo preenchida com os pontos e, caso ganhe, se ganhou.

    cadastraJogador(usuario); // No final do jogo, cadastra o jogador com quantos pontos ele fez e se ganhou ou n�o o jogo

    Sleep(200);
    system("CLS");
    menuPrincipal(); // Quando tudo termina, volta para o menu principal.
}

// ---------------------------------------------------
