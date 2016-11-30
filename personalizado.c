#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>

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

// MAIN DO MODO DE JOGO PERSONALIZADO
// O modo de jogo personalizado nada mais é do que uma cópia do modo de jogo Clássico. Porém, o TAM é informado pelo usuário.

void mainPersonalizado()
{
    int TAM, continua;
    int *ganhou, zero = 0;

    ganhou = &zero;

    system("CLS");

    printf("No modo personalizado, podemos escolher um tabuleiro 5x5 ou 6x6.\nEscolha sua opção:\n5 - Tabuleiro 5 x 5\n6 - Tabuleiro 6 x 6\nOPÇÃO: ");
    do
    {
        scanf("%d", &TAM);

        if (TAM == 5 || TAM == 6)
            continua = 0;
        else
            printf("Você digitou uma opção inválida. Escolha entre 5 e 6.\nOPÇÃO: ");
    }while(continua);

    srand( (unsigned)time(NULL) ); // Função para usar o rand();

    Jogador usuario;

    usuario.pontos = 0; // Os pontos inicializam zerados
    usuario.ganhou = 0; // O jogador começa com o sinalizador de ganhou zerado

    printf("Por gentileza, informe seu nome: "); // O nome do jogador é salvo na struct Jogador
    fflush(stdin);
    gets(usuario.nome);

    system("CLS");

    Bloco matriz[6][6]; //Declaração da matriz de blocos que será usada como tabuleiro

    inicializaTabuleiro(matriz, TAM); // Inicializa toda a matriz com blocos do valor zero

    hideCursor(); //Apaga o cursor da tela para melhor visualização

    imprimeTabuleiro(matriz, TAM); // Imprime todo o tabuleiro zerado que já chama a função aleatório


    if(TAM == 6)
        adjustConsole(79.9, 31);
    else
        adjustConsole(79.9, 26);

    while(moveBloco(getKey(), matriz, TAM, &usuario, ganhou)); // Função principal que faz o jogo ficar sendo executado. Por parâmetro, é passada a matriz e a struct do usuário por referência que vai sendo preenchida com os pontos e, caso ganhe, se ganhou.

    adjustConsole(79.9, 21);

    cadastraJogador(usuario); // No final do jogo, cadastra o jogador com quantos pontos ele fez e se ganhou ou não o jogo

    Sleep(200);
    system("CLS");
    menuPrincipal(); // Quando tudo termina, volta para o menu principal.
}

// ---------------------------------------------------
