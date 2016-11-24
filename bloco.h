
// PROTÓTIPOS DE STRUCTS -----------------------

typedef struct blocoStruct
{
    int cor; // Cor do bloco
    int valor; // Valor que o bloco possui
    int x;
    int y;
    int colidiu;
} Bloco;

// -------------------------------------------

// PROTÓTIPOS DE FUNÇÕES ----------------------

int moveBloco(char key, Bloco matriz[][4], int *pontos); // Função principal que é executada num while pegando entrada do usuário e movendo o tabuleiro

void hideCursor(); // Apaga o cursor

void printSquare(Bloco bloco);// Função principal que imprime o quadrado

void eraseSquare(int x, int y); // Apaga o último quadrado

int canMove(int x, int y, int modX, int modY); // Verifica se o quadrado pode mover-se

void getModXY(char key, int *modX, int *modY); // Pega o deslocamento do quadrado

int whileGetKey(); // Loop para pegar entrada do usuário

char getKey(); // Função para pegar entrada do usuário

void whileMain(); // Comanda a entrada do usuário direcionando as setas

// -------------------------------------------
