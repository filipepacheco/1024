#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>

void salvaRanking() // Função para salvar o ranking de arquivo binário em arquivo txt.
{
    system("CLS");

    FILE *arqBin; // Declaração dos ponteiros dos arquivos
    FILE *arqTxt;

    Jogador usuario;// Inicializa struct para ler do arquivo binário e escrever no txt

    int flag = 1;
    int cont = 0;
    int teste, i;
    char nome[50]; // Inicializa variáveis para arquivo txt
    size_t itemSize = sizeof(Jogador);

    arqBin = fopen("jogadores", "rb+"); // Abertura do arquivo binário

    if (arqBin) // Se abriu binário com sucesso
    {
        //teste = fread(&data2, itemSize, 1, arqBin);
        while (!feof(arqBin))
        {
            if (teste)
                cont++;

            //teste = fread(&data2, itemSize, 1, arqBin);
        }

        rewind(arqBin);

        printf("Informe o nome do arquivo onde deseja salvar: ");
        fflush(stdin);
        gets(nome);

        arqTxt = fopen(nome, "w"); // Abertura do arquivo txt

        if (arqTxt) // Se abriu com sucesso
        {

            for(i = 0; i < cont; i++)
            {
                teste = fread(&usuario + i, itemSize, 1, arqBin); // Lê o arquivo binário
                if(teste) // Se leu com sucesso
                {
                    teste = fprintf(arqTxt, "Nome: %s; Pontuação: %d; Ganhou: %d;\n", usuario.nome, usuario.pontos, usuario.ganhou); // Imprime no arquivo txt
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

void imprimeRanking()
{
    FILE *arq;

    Jogador jogador;

    int teste;

    arq = fopen("jogadores", "r");

    if (arq)
    {
        while(!feof(arq))
        {
            teste = fread(&jogador, sizeof(jogador), 1, arq);
            if (teste)
                printf("Nome: %s; Pontos: %d; Ganhou? %d;\n", jogador.nome, jogador.pontos, jogador.ganhou);
        }
    }//else
        //erro

    fclose(arq);

    system("PAUSE");
}

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
            break;
        case 2: // Resetar Ranking
            break;
        case 3: salvaRanking(); // Salvar Ranking
                menuRanking();
            break;
    }

}
