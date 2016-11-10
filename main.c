#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Include para possibilitar o uso de acentuação

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("AUTORES: Filipe Pacheco de Fraga e Marcelo Audibert Chaves\n");


    return 0;
}
