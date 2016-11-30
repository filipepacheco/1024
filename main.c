//#include <stdio.h>
#include <locale.h> //Include para possibilitar o uso de acentuação
#include <conio2.h>
#include <windows.h>

#include "bloco.h"
#include "classico.h"
#include "header.h"
#include "personalizado.h"

int main()
{
    SetConsoleTitle("1024 O JOGO! - Por Filipe Pacheco de Fraga e Marcelo Audibert Chaves.");
    setlocale(LC_ALL, "Portuguese");

    textcolor(WHITE);
    menuPrincipal();

    return 0;
}
