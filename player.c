#include "bloco.h"
#include "classico.h"
#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int cadastraJogador(Jogador usuario)
{
    int retorno = 1, teste; // Variável de retorno e controle de erros

    FILE *arq; // Declaração e abertura do arquivo
    arq = fopen("jogadores", "ab");

    if(arq){ // Se abriu com sucesso
        teste = fwrite(&usuario, sizeof(usuario), 1, arq);
        if(!teste) // Se a escrita deu errado
        {
            retorno = 0;
            printf("Erro ao escrever no arquivo.\n");
        }
    }else{ // Se a abertura deu errado
        retorno = 0;
        printf("Erro ao abrir arquivo.\n");
    }

    fclose(arq);

    return retorno;
}
