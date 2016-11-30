#define WIDTH 6 // Largura de impressão do quadrado
#define HEIGHT 4 // Altura de impressão do quadrado

#define iWIDTH 7 // Largura de inicialização do quadrado para imprimir os espaços entre os blocos
#define iHEIGHT 5 // Altura de inicialização do quadrado para imprimir os espaços entre os blocos

#define COLOR 0x44

#define VEL 1 // Velocidade que os blocos se movimentam

#define CONSOLEX 80 // Suposição da largura do console
#define CONSOLEY 25 // Suposição da altura do console

#define SLEEP 20 // Constante que define o tempo dos delays

// PROTÓTIPOS DE STRUCTS -----------------------

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

// PROTÓTIPOS DE FUNÇÕES ----------------------

int moveBloco(char key, Bloco matriz[][6], int TAM, Jogador *usuario, int *ganhou); // Função principal que é executada num while pegando entrada do usuário e movendo o tabuleiro

void hideCursor(); // Apaga o cursor

void printSquare(Bloco bloco);// Função principal que imprime o quadrado

int whileGetKey(); // Loop para pegar entrada do usuário

char getKey(); // Função para pegar entrada do usuário

void whileMain(); // Comanda a entrada do usuário direcionando as setas

void inicializaTabuleiro(Bloco matriz[][6], int TAM); // Inicializa o tabuleiro zerado e com seus respectivos dados

int tabuleiroCheio(Bloco matriz[][6], int TAM); // Verifica se o tabuleiro está cheio

void imprimeTabuleiro(Bloco matriz[][6], int TAM); // Imprime bloco por bloco do tabuleiro

int podeMexer(Bloco matriz[][6], int TAM); // Verifica se o tabuleiro pode ou não realizar movimentos

int podeMexer(Bloco matriz[][6], int TAM); // Insere um bloco aleatório no tabuleiro

// -------------------------------------------
