//#include <stdio.h>
#include <locale.h> //Include para possibilitar o uso de acentuação
#include "header.h"

#define SQUARE_WIDTH 5
#define SQUARE_HEIGHT 3

int main()
{
    setlocale(LC_ALL, "Portuguese");

    menuPrincipal();

    return 0;
}
