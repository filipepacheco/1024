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


// INICIALIZA TODO O TABULEIRO COM VALOR ZERO

void inicializaTabuleiro(Bloco matriz[][TAM])
{
    int i,j;

    //Loops para inicializa��o dos blocos dentro do tabuleiro
    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j].valor = 0;
            matriz[i][j].colidiu = 0;
            matriz[i][j].x = j * SQUARE_WIDTH + 1; // C�lculo para inicializar a posi��o X
            matriz[i][j].y = i * SQUARE_HEIGHT + 1; // e Y do bloco para possibilitar impress�o dele
        }
}

// ---------------------------------------------------

// IMPRIMIR TABULEIRO NA TELA

void imprimeTabuleiro(Bloco matriz[][TAM])
{
    int i,j;

    //Loop para impress�o dos blocos na tela, automaticamente montando o tabuleiro
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            printSquare(matriz[i][j]); // Posi��o X, Y e COR da Struct Bloco dentro da matriz s�o passados por par�metro.
        }
    }

    aleatorio(matriz); // Gera o bloco aleat�rio no tabuleiro
}

// ----------------------------------------------------

// MAIN DO MODO DE JOGO CL�SSICO

void mainClassico()
{
    srand( (unsigned)time(NULL) ); // Fun��o para usar o rand();

    Jogador usuario;

    usuario.pontos = 0; // Os pontos inicializam zerados
    usuario.ganhou = 0; // O jogador come�a com o sinalizador de ganhou zerado

    printf("Por gentileza, informe seu nome: "); // O nome do jogador � salvo na struct Jogador
    fflush(stdin);
    gets(usuario.nome);

    system("CLS");

    Bloco matriz[TAM][TAM]; //Declara��o da matriz de blocos que ser� usada como tabuleiro

    inicializaTabuleiro(matriz); // Inicializa toda a matriz com blocos do valor zero

    hideCursor(); //Apaga o cursor da tela para melhor visualiza��o

    imprimeTabuleiro(matriz); // Imprime todo o tabuleiro zerado que j� chama a fun��o aleat�rio

    while(moveBloco(getKey(), matriz, &usuario)); // Fun��o principal que faz o jogo ficar sendo executado. Por par�metro, � passada a matriz e a struct do usu�rio por refer�ncia que vai sendo preenchida com os pontos e, caso ganhe, se ganhou.

    cadastraJogador(usuario); // No final do jogo, cadastra o jogador com quantos pontos ele fez e se ganhou ou n�o o jogo

    menuPrincipal(); // Quando tudo termina, volta para o menu principal.
}

// ---------------------------------------------------
