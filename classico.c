#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"
#include "personalizado.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>


// MAIN DO MODO DE JOGO CL�SSICO

void mainClassico()
{
    int TAM = 4, *flag, f=0; // MODO CL�SSICO POSSUI UM TABULEIRO 4X4

    flag = &f;
    srand( (unsigned)time(NULL) ); // Fun��o para usar o rand();

    Jogador usuario;

    usuario.pontos = 0; // Os pontos inicializam zerados
    usuario.ganhou = 0; // O jogador come�a com o sinalizador de ganhou zerado

    printf("Por gentileza, informe seu nome: "); // O nome do jogador � salvo na struct Jogador
    fflush(stdin);
    gets(usuario.nome);

    system("CLS");

    Bloco matriz[6][6]; //Declara��o da matriz de blocos que ser� usada como tabuleiro

    inicializaTabuleiro(matriz, TAM); // Inicializa toda a matriz com blocos do valor zero

    hideCursor(); //Apaga o cursor da tela para melhor visualiza��o

    imprimeTabuleiro(matriz, TAM); // Imprime todo o tabuleiro zerado que j� chama a fun��o aleat�rio

    while(moveBloco(getKey(), matriz, TAM, &usuario, flag)); // Fun��o principal que faz o jogo ficar sendo executado. Por par�metro, � passada a matriz e a struct do usu�rio por refer�ncia que vai sendo preenchida com os pontos e, caso ganhe, se ganhou.

    cadastraJogador(usuario); // No final do jogo, cadastra o jogador com quantos pontos ele fez e se ganhou ou n�o o jogo

    Sleep(200);
    system("CLS");
    menuPrincipal(); // Quando tudo termina, volta para o menu principal.
}

// ---------------------------------------------------
