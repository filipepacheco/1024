#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"
#include "personalizado.h"

#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>
//#include <ctype.h>



int tabuleiroCheio(Bloco matriz[][6], int TAM)
{
    int x,y, cheio = 1;

    for(y = 0; y < TAM; y++)
        for(x = 0; x < TAM; x++) // Itera sobre toda a matriz
            if (matriz[y][x].valor == 0) // Se o bloco estiver livre, retorna 0 indicando que o tabuleiro ainda possui espaço
                cheio = 0;

    return cheio;
}

// INICIALIZA TODO O TABULEIRO COM VALOR ZERO

void inicializaTabuleiro(Bloco matriz[][6], int TAM)
{
    int i,j;

    //Loops para inicialização dos blocos dentro do tabuleiro
    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j].valor = 0;
            matriz[i][j].colidiu = 0;
            matriz[i][j].x = j * iWIDTH + 1; // Cálculo para inicializar a posição X
            matriz[i][j].y = i * iHEIGHT + 3; // e Y do bloco para possibilitar impressão dele
        }
}

// ---------------------------------------------------

// IMPRIMIR TABULEIRO NA TELA

void imprimeTabuleiro(Bloco matriz[][6], int TAM)
{
    int i,j;

    //Loop para impressão dos blocos na tela, automaticamente montando o tabuleiro
    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++)
            printSquare(matriz[i][j]); // Posição X, Y e COR da Struct Bloco dentro da matriz são passados por parâmetro.

    aleatorio(matriz, TAM); // Gera o bloco aleatório no tabuleiro
}

// ----------------------------------------------------

int podeMexer(Bloco matriz[][6], int TAM)
{
    // Variáveis de controle do for, auxiliar para clareza do código e mexe como retorno da função
    int x, y, aux, mexe = 0;

    for(y = 0; y < TAM; y++)
        for(x = 0; x < TAM; x++) // Itera sobre todos os blocos da matriz
        {
            aux = matriz[y][x].valor; // Auxiliar recebe valor atual da iteração
            if(aux > 0 && // Se valor atual > 0 E
                    (aux == matriz[y - 1][x].valor || // Bloco abaixo e valor atual forem iguais OU
                     aux == matriz[y + 1][x].valor || // Bloco acima e valor atual forem iguals OU
                     aux == matriz[y][x + 1].valor || // Bloco a direita e valor atual forem iguais OU
                     aux == matriz[y][x - 1].valor)) // Bloco a esquerda e valor forem iguais OU
                mexe = 1; // Significa que existe a possibilidade de se mover
        }

    return mexe;
}

int aleatorio(Bloco matriz[][6], int TAM) // Recebe o tabuleiro inteiro por parametro
{
    srand((unsigned)time(NULL)); // Função para conseguir gerar números aleatórios

    // Variável de controle do do-while, da posição da matriz e do retorno da função, respectivamente
    int continua = 1, l, c, retorno = 0;
    float valor;

    do
    {
        l = rand() % TAM; // Linha recebe um valor aleatório de 0 a TAM
        c = rand() % TAM; // Coluna recebe um valor aleatório de 0 a TAM

        if(matriz[l][c].valor == 0) // Se a matriz gerada aleatória possui valor 0, muda o valor para 1 ou 2. Senão, continua fazendo o while até encontrar.
        {
            continua = 0; // Faz o while parar
            valor = rand() % 5; // Valor recebe um valor aleatório de 0 a 4

            if(valor > 2) // Se o valor for maior que 2, o bloco aleatório recebe o valor 2
                matriz[l][c].valor = 2;
            else // Se for menor que dois, o bloco aleatório recebe valor 1.
                matriz[l][c].valor = 1;
            // É uma forma de determinar 50% de chance para cada valor.
        }
    }
    while(continua && !tabuleiroCheio(matriz, TAM));

    if(tabuleiroCheio(matriz, TAM)) // Se o tabuleiro estiver cheio
        if(!podeMexer(matriz, TAM)) // E não há mais movimentos
            retorno = 1; // Retorna

    Sleep(50); // Pequeno delay

    printSquare(matriz[l][c]); // Imprime novamente o bloco com o valor modificado

    return retorno;
}

void hideCursor() // Esconde o cursor
{
    CONSOLE_CURSOR_INFO info = {100, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// Função feita em aula para printar os quadrados
void printSquare(Bloco bloco)
{
    int i,j;

    //Este switch controla as cores que serão impressas nos blocos. As cores são determinadas de acordo com o valor do bloco.
    switch(bloco.valor)
    {
    case 0:
        bloco.cor = CYAN;
        break;
    case 1:
        bloco.cor = LIGHTMAGENTA;
        break;
    case 2:
        bloco.cor = GREEN;
        break;
    case 4:
        bloco.cor = BLUE;
        break;
    case 8:
        bloco.cor = RED;
        break;
    case 16:
        bloco.cor = MAGENTA;
        break;
    case 32:
        bloco.cor = BROWN;
        break;
    case 64:
        bloco.cor = LIGHTGRAY;
        break;
    case 128:
        bloco.cor = DARKGRAY;
        break;
    case 256:
        bloco.cor = LIGHTBLUE;
        break;
    case 512:
        bloco.cor = LIGHTGREEN;
        break;
    case 1024:
        bloco.cor = YELLOW;
        break;
    default:
        bloco.cor = YELLOW;
        break;
    }

    textbackground(bloco.cor);

    // Iteração para impressão do bloco blaseada no WIDTH
    for(i = bloco.x; i < bloco.x + WIDTH; i++)
        //Iteração para impressão do bloco baseada no HEIGHT
        for(j = bloco.y; j < bloco.y + HEIGHT; j++)
        {
            gotoxy(i,j);

            //Lógica para encontrar exatamente o meio do bloco e imprimir seu respectivo valor
            if (i == bloco.x + WIDTH / 2 && j == bloco.y + HEIGHT / 2 && bloco.valor > 0)
            {
                //Descola o cursor de acordo com o tamanho do valor do bloco.
                if(bloco.valor < 100)
                    gotoxy(i-1,j);
                if(bloco.valor > 100)
                    gotoxy(i-2,j);

                //Finalmente imprime o valor do bloco
                printf("%d", bloco.valor);
            }

            //Preenche o bloco com espaços da respectiva cor
            printf(" ");
        }

    //Volta a a cor ao normal
    textbackground(BLACK);
}

void zeraColisao(Bloco matriz[][6], int TAM)
{
    int i,j;

    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++)
            matriz[i][j].colidiu = 0; // Varre toda a matriz e zera a flag de colisão
}


// Função que faz o tabuleiro funcionar movendo-se para a respectiva direção
int moveBloco(char key, Bloco matriz[][6], int TAM, Jogador *usuario)
{
    // Variável auxiliar do tipo struct bloco que serve para armazenar o bloco a fim de locomove-lo
    Bloco aux;

    // Variáveis de controle para o for, retorno da função, controle do while e controle da movimentação (respectivamente)
    int x, y, retorno = 1, continua = 0, moveu = 0, resul;

    switch(key) // Pega a tecla apertada pelo usuário e move o tabuleiro respectivamente
    {
    case 72: // CIMA (y + (-1)), (x + 0)
        do
        {
            continua = 0;
            for (x = 0; x < TAM; x++)
            {
                for(y = 1; y < TAM; y++)
                {
                    aux = matriz[y][x]; // Variável temporária AUX recebe o bloco atual para conseguir mover ele (se possível)
                    if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                    {
                        if (matriz[y - 1][x].valor == aux.valor && aux.colidiu == 0) // Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve somá-los
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y - 1][x].valor += aux.valor; // Soma o bloco adjacente com o bloco em evidência e liga a flag de colisão
                            usuario->pontos += matriz[y - 1][x].valor;
                            matriz[y - 1][x].colidiu = 1;

                            if (matriz[y - 1][x].valor == 1024) // Verifica se o usuário ganhou o jogo
                                usuario->ganhou = 1;

                            Sleep(SLEEP);
                            printSquare(matriz[y-1][x]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y - 1][x].colidiu = 1;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                        if (matriz[y - 1][x].valor == 0) // Se o bloco adjacente não possuir valor, deve só movimentar o bloco sem somar;
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y - 1][x].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evidência e faz ele se locomover
                            matriz[y - 1][x].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y-1][x]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y - 1][x].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                    }
                }
            }
        }
        while(continua);
        break;
    case 77: // DIREITA (y + 0), (x + 1)
        do
        {
            continua = 0;
            for (y = 0; y < TAM; y++)
            {
                for(x = TAM - 2; x >= 0; x--)
                {
                    aux = matriz[y][x]; // Variável temporária AUX recebe o bloco atual para conseguir mover ele (se possível)
                    if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                    {
                        if (matriz[y][x+1].valor == aux.valor && aux.colidiu == 0) // Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve somá-los
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y][x+1].valor += aux.valor; // Soma o bloco adjacente com o bloco em evidência e liga a flag de colisão
                            matriz[y][x+1].colidiu = 1;
                            usuario->pontos += matriz[y][x+1].valor;

                            if (matriz[y][x + 1].valor == 1024) // Verifica se o usuário ganhou o jogo
                                usuario->ganhou = 1;

                            Sleep(SLEEP);
                            printSquare(matriz[y][x+1]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y][x].colidiu = 1;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                        if (matriz[y][x+1].valor == 0) // Se o bloco adjacente não possuir valor, deve só movimentar o bloco sem somar;
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y][x+1].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evidência e faz ele se locomover
                            matriz[y][x+1].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x+1]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y][x].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                    }
                }
            }
        }
        while(continua);
        break;
    case 75: // ESQUERDA (Y + 0), (X - 1)
        do
        {
            continua = 0;
            for (y = 0; y < TAM; y++)
            {
                for(x = 1; x < TAM; x++)
                {
                    aux = matriz[y][x]; // Variável temporária AUX recebe o bloco atual para conseguir mover ele (se possível)
                    if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                    {
                        if (matriz[y][x-1].valor == aux.valor && aux.colidiu == 0) // Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve somá-los
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y][x-1].valor += aux.valor; // Soma o bloco adjacente com o bloco em evidência e liga a flag de colisão
                            matriz[y][x-1].colidiu = 1;
                            usuario->pontos += matriz[y][x-1].valor;

                            if (matriz[y][x - 1].valor == 1024) // Verifica se o usuário ganhou o jogo
                                usuario->ganhou = 1;

                            Sleep(SLEEP);
                            printSquare(matriz[y][x-1]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y][x].colidiu = 1;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                        if (matriz[y][x-1].valor == 0) // Se o bloco adjacente não possuir valor, deve só movimentar o bloco sem somar;
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y][x-1].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evidência e faz ele se locomover
                            matriz[y][x-1].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x-1]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y][x].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                    }
                }
            }
        }
        while(continua);
        break;
    case 80: // BAIXO (y + 1), (x + 0)
        do
        {
            continua = 0;
            for (x = 0; x < TAM; x++)
            {
                for(y = TAM - 2; y >= 0; y--)
                {
                    aux = matriz[y][x]; // Variável temporária AUX recebe o bloco atual para conseguir mover ele (se possível)
                    if (aux.valor > 0) // Se o bloco selecionado possui algum valor significativo
                    {
                        if (matriz[y+1][x].valor == aux.valor && aux.colidiu == 0)// Se o bloco adjacente possui o mesmo valor do bloco selecionado, deve somá-los
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y+1][x].valor += aux.valor; // Soma o bloco adjacente com o bloco em evidência e liga a flag de colisão
                            matriz[y+1][x].colidiu = 1;
                            usuario->pontos += matriz[y+1][x].valor;

                            if (matriz[y+1][x].valor == 1024) // Verifica se o usuário ganhou o jogo
                                usuario->ganhou = 1;

                            Sleep(SLEEP);
                            printSquare(matriz[y+1][x]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y+1][x].colidiu = 1;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                        if (matriz[y+1][x].valor == 0) // Se o bloco adjacente não possuir valor, deve só movimentar o bloco sem somar;
                        {
                            continua = 1; // Variável de controle do do - while
                            moveu = 1; // Variável de controle que estipula se deve ou não gerar aleatório/zerar a colisão
                            matriz[y+1][x].valor = aux.valor; // O bloco adjacente vazio recebe o bloco em evidência e faz ele se locomover
                            matriz[y+1][x].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y+1][x]); // Imprime o bloco adjacente atualizado
                            matriz[y][x].valor = 0;
                            matriz[y+1][x].colidiu = 0;
                            Sleep(SLEEP);
                            printSquare(matriz[y][x]); // Imprime o bloco em evidência zerado
                        }
                    }
                }
            }
        }
        while(continua);
        break;
    default: // Qualquer outra tecla que não seja direcional faz com que termine o jogo
        retorno = 0;
    }

    if (usuario->ganhou == 1) // Verifica se o usuário ganhou o jogo checando o status da variavel ganhou na struct
    {
        int resul = MessageBox(0,"Parabéns! Você venceu!\n Gostaria de continuar?", "", MB_YESNO);
        if (resul)
        {
            retorno = 1;
        }else{
            retorno =0;
        }
    }
    else if(moveu)  // Se houve alguma movimentação, ele executa isso
    {
        if(aleatorio(matriz, TAM)) // Gera o bloco aleatório que já faz a verificação se o jogo acabou
            retorno = 0;
        zeraColisao(matriz, TAM); // Reseta todas as colisões da matriz
        printNomes(usuario->nome, usuario->pontos);
    }

    return retorno; // Retorno = 0 significa que o jogo acabou. retorno > 0 significa que continua
}
