// PROTÓTIPOS DE STRUCTS -----------------------

typedef struct blocoStruct
{
    int cor; // Cor do bloco
    int valor; // Valor que o bloco possui
    int x;
    int y;
} Bloco;

// -------------------------------------------

// PROTÓTIPOS DE FUNÇÕES ----------------------

void hideCursor(); // Apaga o cursor

void printSquare(Bloco bloco);// Função principal que imprime o quadrado

void eraseSquare(int x, int y); // Apaga o último quadrado

int canMove(int x, int y, int modX, int modY); // Verifica se o quadrado pode mover-se

void getModXY(char key, int *modX, int *modY); // Pega o deslocamento do quadrado

int whileGetKey(); // Loop para pegar entrada do usuário

char getKey(); // Função para pegar entrada do usuário

void whileMain(); // Comanda a entrada do usuário direcionando as setas

// -------------------------------------------
