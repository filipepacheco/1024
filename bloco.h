#define WIDTH 6 // Largura de impress�o do quadrado
#define HEIGHT 4 // Altura de impress�o do quadrado

#define iWIDTH 7 // Largura de inicializa��o do quadrado para imprimir os espa�os entre os blocos
#define iHEIGHT 5 // Altura de inicializa��o do quadrado para imprimir os espa�os entre os blocos

#define COLOR 0x44

#define VEL 1 // Velocidade que os blocos se movimentam

#define CONSOLEX 80 // Suposi��o da largura do console
#define CONSOLEY 25 // Suposi��o da altura do console

#define SLEEP 20 // Constante que define o tempo dos delays

// PROT�TIPOS DE STRUCTS -----------------------

typedef struct blocoStruct
{
    int cor; // Cor do bloco
    int valor; // Valor que o bloco possui
    int x;
    int y;
    int colidiu;
} Bloco;

typedef struct structPlayer
{
    char nome[50];
    int pontos;
    int ganhou;
}Jogador;

// -------------------------------------------

// PROT�TIPOS DE FUN��ES ----------------------

int moveBloco(char key, Bloco matriz[][6], int TAM, Jogador *usuario, int *ganhou); // Fun��o principal que � executada num while pegando entrada do usu�rio e movendo o tabuleiro

void hideCursor(); // Apaga o cursor

void printSquare(Bloco bloco);// Fun��o principal que imprime o quadrado

int whileGetKey(); // Loop para pegar entrada do usu�rio

char getKey(); // Fun��o para pegar entrada do usu�rio

void whileMain(); // Comanda a entrada do usu�rio direcionando as setas

void inicializaTabuleiro(Bloco matriz[][6], int TAM); // Inicializa o tabuleiro zerado e com seus respectivos dados

int tabuleiroCheio(Bloco matriz[][6], int TAM); // Verifica se o tabuleiro est� cheio

void imprimeTabuleiro(Bloco matriz[][6], int TAM); // Imprime bloco por bloco do tabuleiro

int podeMexer(Bloco matriz[][6], int TAM); // Verifica se o tabuleiro pode ou n�o realizar movimentos

int podeMexer(Bloco matriz[][6], int TAM); // Insere um bloco aleat�rio no tabuleiro

// -------------------------------------------
