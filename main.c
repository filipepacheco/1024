//#include <stdio.h>
#include <locale.h> //Include para possibilitar o uso de acentuação
#include "header.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //Switch em cima do retorno da função do menu, que retorna a entrada do usuário direcionando-o para o respectivo menu
    switch(menuPrincipal())
    {
        case 1: //Clássico
            break;
        case 2: //Fácil
            break;
        case 3: //Personalizado
            break;
        case 4: //Rank
            break;
    }

    return 0;
}
