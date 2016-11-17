// PROT�TIPOS DE STRUCTS -----------------------

typedef struct blocoStruct
{
    int cor; // Cor do bloco
    int valor; // Valor que o bloco possui
    int x;
    int y;
} Bloco;

// -------------------------------------------

// PROT�TIPOS DE FUN��ES ----------------------

void hideCursor(); // Apaga o cursor

void printSquare(Bloco bloco);// Fun��o principal que imprime o quadrado

void eraseSquare(int x, int y); // Apaga o �ltimo quadrado

int canMove(int x, int y, int modX, int modY); // Verifica se o quadrado pode mover-se

void getModXY(char key, int *modX, int *modY); // Pega o deslocamento do quadrado

int whileGetKey(); // Loop para pegar entrada do usu�rio

char getKey(); // Fun��o para pegar entrada do usu�rio

void whileMain(); // Comanda a entrada do usu�rio direcionando as setas

// -------------------------------------------
