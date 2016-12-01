#include "bloco.h"
#include "classico.h"
#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

// FUNÇÃO PARA CADASTRAR JOGADOR NO ARQUIVO BINARIO

int cadastraJogador(Jogador usuario)
{
    int retorno = 1, teste; // Variável de retorno e controle de erros

    size_t size = sizeof(Jogador);

    FILE *arq; // Declaração e abertura do arquivo

    arq = fopen("jogadores", "ab");

    if(arq)
    {
        teste = fwrite(&usuario, size, 1, arq);
        if(!teste) // Se a escrita deu errado
        {
            retorno = 0;
            printf("Erro ao escrever no arquivo.\n");
        }
    }
    else
        printf("Erro na abertura do arquivo.");

    fclose(arq);
    return retorno;
}

// ----------------------------------------------------------
