//#include <stdio.h>
#include <locale.h> //Include para possibilitar o uso de acentuação
#include <conio2.h>

#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "personalizado.h"


int main()
{
    setlocale(LC_ALL, "Portuguese");

    textcolor(WHITE);
    menuPrincipal();

    return 0;
}
