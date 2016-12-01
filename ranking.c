#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>


// RESETA O RANKING APAGANDO TODO O CONTEUDO DO ARQUIVO

void resetRanking()
{
    system("CLS");

    FILE *arq;

    arq = fopen("jogadores", "wb"); // Abre arquivo binário

    if(arq){
        printf("Ranking resetado com sucesso."); // Ao abrir arquivo, apaga todo ele
    }else
        printf("Erro ao resetar ranking.");

    fclose(arq);

    Sleep(3000);
}


// -------------------------------------------

// SALVA O RANKING EM ARQUIVO .TXT

void salvaRanking() // Função para salvar o ranking de arquivo binário em arquivo txt.
{
    system("CLS");

    FILE *arqBin; // Declaração dos ponteiros dos arquivos
    FILE *arqTxt;

    Jogador player; // Variável auxiliar para leitura

    int cont = 0; // Variável de controle do array de structs
    int teste, i;
    char nome[50]; // Inicializa variáveis para arquivo txt
    char aux[4];
    size_t size = sizeof(Jogador);

    arqBin = fopen("jogadores", "rb+"); // Abertura do arquivo binário

    if (arqBin) // Se abriu binário com sucesso
    {
        while (!feof(arqBin))
        {
            teste = fread(&player, size, 1, arqBin);
            if (teste)
                cont++; // Faz a contagem de quantos jogadores estão salvos no ranking
        }

        rewind(arqBin); // Reseta cursor

        printf("Informe o nome do arquivo onde deseja salvar: ");
        fflush(stdin);
        gets(nome);

        Jogador usuario[cont];// Inicializa struct a partir do numero de jogadores salvos no ranking

        arqTxt = fopen(nome, "w"); // Abertura do arquivo txt

        if (arqTxt) // Se abriu com sucesso
        {
            for(i = 0; i < cont; i++)
            {
                teste = fread(&usuario[i], size, 1, arqBin); // Lê o arquivo binário
                if(teste) // Se leu com sucesso
                {
                    if(usuario[i].ganhou == 1) { aux[0] = 's'; aux[1] = 'i'; aux[2] = 'm'; aux[3] = '\0';}
                    else { aux[0] = 'n'; aux[1] = 'a'; aux[2] = 'o'; aux[3] = '\0';} // Lógica para transformar 0 em não e 1 em sim na hora da impressão do ranking

                    teste = fprintf(arqTxt, "Nome: %s; Pontuação: %d; Ganhou: %s;\n", usuario[i].nome, usuario[i].pontos, aux); // Imprime no arquivo txt
                    if (!teste) // Caso haja falha na escrita no txt
                        printf("Erro de escrita!\n");
                }
            }


            printf("Arquivos gravado com sucesso.\n");
        }
        else
            printf("Erro ao abrir arquivo texto.\n");
    }else
        printf("Erro ao abrir arquivo binário.\n");

    fclose(arqBin);
    fclose(arqTxt);

    Sleep(3000);
}

// -------------------------------------------

// IMPRIME O RANKING NO CONSOLE

void imprimeRanking()
{
    FILE *arq;

    Jogador jogador;

    char aux[4];

    int teste, i=1;

    arq = fopen("jogadores", "r");

    if (arq)
    {
        while(!feof(arq))
        {
            teste = fread(&jogador, sizeof(jogador), 1, arq);
            if (teste)
            {
                if(jogador.ganhou == 1) { aux[0] = 's'; aux[1] = 'i'; aux[2] = 'm'; aux[3] = '\0';}
                else { aux[0] = 'n'; aux[1] = 'a'; aux[2] = 'o'; aux[3] = '\0';}

                printf("%dº - NOME\tPONTOS\t\tGANHOU?\n", i);
                printf("%s\t\t%6d\t\t%6s\n\n", jogador.nome, jogador.pontos, aux);
            }
            i++;
        }
    }else
        printf("Erro ao abrir arquivo.");

    fclose(arq);

    system("PAUSE");
}

// -------------------------------------------

// MENU PRINCIPAL DO MENU RANKING

void menuRanking()
{
    system("CLS");

    int opcao, continua;

    printf("\tAUTORES: Filipe Pacheco de Fraga e Marcelo Audibert Chaves\n\n\n%38d!\n\n\n\t1 - Exibir Ranking\n\n\t2 - Resetar Ranking\n\n\t3 - Salvar Ranking\n\n\t0 - Voltar\n\n\t%44s\n%40s", 1024, "Qual a opção desejada, jogador?", "OPÇÃO: ");

    //Loop para pegar a entrada correta do usuário
    do
    {
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 3)
            printf("%58s\n%40s", "Desculpe, mas esta opção é inválida...", "OPÇÃO: ");
        else
            continua = 0;
    }while (continua);

    system("CLS");
    //Switch em cima do retorno da função do menu, que retorna a entrada do usuário direcionando-o para o respectivo menu
    switch(opcao)
    {
        case 0: menuPrincipal();
            break;
        case 1: imprimeRanking(); // Exibir Ranking
                menuRanking();
            break;
        case 2: resetRanking(); // Resetar Ranking
                menuRanking();
            break;
        case 3: salvaRanking(); // Salvar Ranking
                menuRanking();
            break;
    }
}


// -------------------------------------------

