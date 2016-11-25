#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>
//#include <ctype.h>

#define SQUARE_WIDTH 6
#define SQUARE_HEIGHT 4
#define COLOR 0x44
#define VEL 1
#define CONSOLEX 80
#define CONSOLEY 25
#define XMAIN 25
#define YMAIN 10
#define SLEEP 100

void aleatorio(Bloco matriz[][TAM]) // Recebe o tabuleiro inteiro por parametro
{
    srand((unsigned)time(NULL)); // Fun��o para conseguir gerar n�meros aleat�rios

    int continua = 1, l, c; // Vari�veis de controle do for e do while
    float valor;

    do
    {
        l = rand() % TAM; // Linha recebe um valor aleat�rio de 0 a TAM
        c = rand() % TAM; // Coluna recebe um valor aleat�rio de 0 a TAM

        if(matriz[l][c].valor == 0) // Se a matriz gerada aleat�ria possui valor 0, muda o valor para 1 ou 2. Sen�o, continua fazendo o while at� encontrar.
        {
            continua = 0; // Faz o while parar
            valor = rand() % 5; // Valor recebe um valor aleat�rio de 0 a 4

            if(valor > 2) // Se o valor for maior que 2, o bloco aleat�rio recebe o valor 2
                matriz[l][c].valor = 2;
            else // Se for menor que dois, o bloco aleat�rio recebe valor 1.
                matriz[l][c].valor = 1;
                // � uma forma de determinar 50% de chance para cada valor.
        }

    }while(continua);

    Sleep(50); // Pequeno delay

    printSquare(matriz[l][c]); // Imprime novamente o bloco com o valor modificado
}

void hideCursor() // Esconde o cursor
{
    CONSOLE_CURSOR_INFO info = {100, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// Fun��o feita em aula para printar os quadrados
void printSquare(Bloco bloco)
{
    int i,j;

    //Este switch controla as cores que ser�o impressas nos blocos. As cores s�o determinadas de acordo com o valor do bloco.
    switch(bloco.valor)
    {
    case 0: bloco.cor = CYAN; break;
    case 1: bloco.cor = LIGHTMAGENTA; break;
    case 2: bloco.cor = GREEN; break;
    case 4: bloco.cor = BLUE; break;
    case 8: bloco.cor = RED; break;
    case 16: bloco.cor = MAGENTA; break;
    case 32: bloco.cor = BROWN; break;
    case 64: bloco.cor = LIGHTGRAY; break;
    case 128: bloco.cor = DARKGRAY; break;
    case 256: bloco.cor = LIGHTBLUE; break;
    case 512: bloco.cor = LIGHTGREEN; break;
    case 1024: bloco.cor = YELLOW; break;
    default: bloco.cor = YELLOW; break;
    }

    textbackground(bloco.cor);

    // Itera��o para impress�o do bloco blaseada no SQUARE_WIDTH
    for(i = bloco.x; i < bloco.x + SQUARE_WIDTH; i++)
        //Itera��o para impress�o do bloco baseada no SQUARE_HEIGHT
        for(j = bloco.y; j < bloco.y + SQUARE_HEIGHT; j++)
        {
            gotoxy(i,j);

            //L�gica para encontrar exatamente o meio do bloco e imprimir seu respectivo valor
            if (i == bloco.x + SQUARE_WIDTH / 2 && j == bloco.y + SQUARE_HEIGHT / 2 && bloco.valor > 0)
            {
                //Descola o cursor de acordo com o tamanho do valor do bloco.
                if(bloco.valor < 100)
                    gotoxy(i-1,j);
                if(bloco.valor > 100)
                    gotoxy(i-2,j);
                if(bloco.valor > 1000)
                    gotoxy(i-3,j);

                //Finalmente imprime o valor do bloco
                printf("%d", bloco.valor);
            }

            //Preenche o bloco com espa�os da respectiva cor
            printf(" ");
        }

    //Volta a a cor ao normal
    textbackground(BLACK);
}

void zeraColisao(Bloco matriz[][TAM])
{
    int i,j;

    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++)
            matriz[i][j].colidiu = 0; // Varre toda a matriz e zera a flag de colis�o

}

// Fun��o que faz o tabuleiro funcionar movendo-se para a respectiva dire��o
int moveBloco(char key, Bloco matriz[][TAM], int *pontos, char nome[])
{
    void printNomes(int p, char nome[])
    {
        int i;

        textbackground(WHITE);
        textcolor(BLACK);
        for(i = 1; i <= CONSOLEX; i++)
        {
            gotoxy(i, CONSOLEY - 3);
            printf(" ");
        }

        gotoxy(1, CONSOLEY - 3);
        printf("Nome do jogador: %s\t\tPontua��o: %d", nome, p);

        textbackground(BLACK);
        textcolor(WHITE);
    }

    // Vari�vel auxiliar do tipo struct bloco que serve para armazenar o bloco a fim de locomove-lo
    Bloco aux;

    // Vari�veis de controle
    int x ,y, retorno = 1, cont = 0, contaux = 0;

    switch(key)
    {
        case 72: // CIMA (y + (-1)), (x + 0)
            do
            {
                cont = 0;
                for (x = 0; x < TAM; x++)
                {
                    for(y = 1; y < TAM; y++)
                    {
                        aux = matriz[y][x]; // Vari�vel tempor�ria AUX recebe o bloco atual para conseguir mover ele (se poss�vel)
                        if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                        {
                            if (matriz[y - 1][x].valor == aux.valor && aux.colidiu == 0) // Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve som�-los
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y - 1][x].valor += aux.valor; // Soma o bloco adjacente com o bloco em evid�ncia e liga a flag de colis�o
                                *pontos += matriz[y - 1][x].valor;
                                matriz[y - 1][x].colidiu = 1;
                                Sleep(SLEEP);
                                printSquare(matriz[y-1][x]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y - 1][x].colidiu = 1;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                            if (matriz[y - 1][x].valor == 0) // Se o bloco adjacente n�o possuir valor, deve s� movimentar o bloco sem somar;
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y - 1][x].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evid�ncia e faz ele se locomover
                                matriz[y - 1][x].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y-1][x]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y - 1][x].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                        }
                    }
                }
            }while(cont);
            break;
        case 77: // DIREITA (y + 0), (x + 1)
            do
            {
                cont = 0;
                for (y = 0; y < TAM; y++)
                {
                    for(x = TAM - 2; x >= 0; x--)
                    {
                        aux = matriz[y][x]; // Vari�vel tempor�ria AUX recebe o bloco atual para conseguir mover ele (se poss�vel)
                        if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                        {
                            if (matriz[y][x+1].valor == aux.valor && aux.colidiu == 0) // Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve som�-los
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y][x+1].valor += aux.valor; // Soma o bloco adjacente com o bloco em evid�ncia e liga a flag de colis�o
                                matriz[y][x+1].colidiu = 1;
                                *pontos += matriz[y][x+1].valor;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x+1]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y][x].colidiu = 1;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                            if (matriz[y][x+1].valor == 0) // Se o bloco adjacente n�o possuir valor, deve s� movimentar o bloco sem somar;
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y][x+1].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evid�ncia e faz ele se locomover
                                matriz[y][x+1].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x+1]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y][x].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                        }
                    }
                }
            }while(cont);
            break;
        case 75: // ESQUERDA (Y + 0), (X - 1)
            do
            {
                cont = 0;
                for (y = 0; y < TAM; y++)
                {
                    for(x = 1; x < TAM; x++)
                    {
                        aux = matriz[y][x]; // Vari�vel tempor�ria AUX recebe o bloco atual para conseguir mover ele (se poss�vel)
                        if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                        {
                            if (matriz[y][x-1].valor == aux.valor && aux.colidiu == 0) // Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve som�-los
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y][x-1].valor += aux.valor; // Soma o bloco adjacente com o bloco em evid�ncia e liga a flag de colis�o
                                matriz[y][x-1].colidiu = 1;
                                *pontos += matriz[y][x-1].valor;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x-1]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y][x].colidiu = 1;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                            if (matriz[y][x-1].valor == 0) // Se o bloco adjacente n�o possuir valor, deve s� movimentar o bloco sem somar;
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y][x-1].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evid�ncia e faz ele se locomover
                                matriz[y][x-1].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x-1]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y][x].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                        }
                    }
                }
            }while(cont);
            break;
        case 80: // BAIXO (y + 1), (x + 0)
            do
            {
                cont = 0;
                for (x = 0; x < TAM; x++)
                {
                    for(y = TAM - 2; y >= 0; y--)
                    {
                        aux = matriz[y][x]; // Vari�vel tempor�ria AUX recebe o bloco atual para conseguir mover ele (se poss�vel)
                        if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                        {
                            if (matriz[y+1][x].valor == aux.valor && aux.colidiu == 0)// Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve som�-los
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y+1][x].valor += aux.valor; // Soma o bloco adjacente com o bloco em evid�ncia e liga a flag de colis�o
                                matriz[y+1][x].colidiu = 1;
                                *pontos += matriz[y+1][x].valor;
                                Sleep(SLEEP);
                                printSquare(matriz[y+1][x]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y+1][x].colidiu = 1;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                            if (matriz[y+1][x].valor == 0) // Se o bloco adjacente n�o possuir valor, deve s� movimentar o bloco sem somar;
                            {
                                cont = 1; // Vari�vel de controle do do - while
                                contaux = 1; // Vari�vel de controle que estipula se deve ou n�o gerar aleat�rio/zerar a colis�o
                                matriz[y+1][x].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evid�ncia e faz ele se locomover
                                matriz[y+1][x].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y+1][x]); // Imprime o bloco adjacente atualizado
                                matriz[y][x].valor = 0;
                                matriz[y+1][x].colidiu = 0;
                                Sleep(SLEEP);
                                printSquare(matriz[y][x]); // Imprime o bloco em evid�ncia zerado
                            }
                        }
                    }
                }
            }while(cont);
            break;
        default:
            retorno = 0;
    }

    if(contaux) // Se houve alguma movimenta��o, ele executa isso
    {
        aleatorio(matriz); // Gera o bloco aleat�rio
        zeraColisao(matriz); // Reseta todas as colis�es da matriz
        printNomes(*pontos, nome);
    }


    return retorno;
}
