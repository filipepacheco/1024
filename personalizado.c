#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>

// FUN��O PARA AUMENTAR/DIMINUIR O CONSOLE

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

void adjustConsole(float x, float y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

    SMALL_RECT windowSize = {0, 0, x, y};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);

    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

// ---------------------------------------------------

// MAIN DO MODO DE JOGO PERSONALIZADO
// O modo de jogo personalizado nada mais � do que uma c�pia do modo de jogo Cl�ssico. Por�m, o TAM � informado pelo usu�rio.

void mainPersonalizado()
{
    int TAM, continua;
    int *ganhou, zero = 0;

    ganhou = &zero;

    system("CLS");

    printf("\n\tNo modo personalizado, podemos escolher um tabuleiro 5x5 ou 6x6.\n\n\n\n\tEscolha sua op��o:\n\n\t5 - Tabuleiro 5 x 5\n\n\t6 - Tabuleiro 6 x 6\n\n\n\n\n\t\tOP��O: ");

    do
    { // Loop para checar integridade da entrada do usu�rio
        scanf("%d", &TAM);

        if (TAM == 5 || TAM == 6)
            continua = 0;
        else
            printf("Voc� digitou uma op��o inv�lida. Escolha entre 5 e 6.\nOP��O: ");
    }while(continua);

    srand( (unsigned)time(NULL) ); // Fun��o para usar o rand();

    Jogador usuario;

    usuario.pontos = 0; // Os pontos inicializam zerados
    usuario.ganhou = 0; // O jogador come�a com o sinalizador de ganhou zerado

    system("CLS");

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

    if(TAM == 6)
        adjustConsole(79.9, 31);
    else
        adjustConsole(79.9, 26);

    while(moveBloco(getKey(), matriz, TAM, &usuario, ganhou)); // Fun��o principal que faz o jogo ficar sendo executado. Por par�metro, � passada a matriz e a struct do usu�rio por refer�ncia que vai sendo preenchida com os pontos e, caso ganhe, se ganhou.

    adjustConsole(79.9, 21);

    cadastraJogador(usuario); // No final do jogo, cadastra o jogador com quantos pontos ele fez e se ganhou ou n�o o jogo

    Sleep(200);
    system("CLS");
    menuPrincipal(); // Quando tudo termina, volta para o menu principal.
}

// ---------------------------------------------------
