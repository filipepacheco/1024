
#define TAM 4

// ----------- PROTÓTIPOS DE STRUCTS ----------------

typedef struct blocoStruct
{
    int cor; // Cor do bloco
    int valor; // Valor que o bloco possui
    int x;
    int y;
} Bloco;

// ---------------------------------------------------


// -------------- PROTÓTIPOS DE FUNÇÕES --------------

void mainClassico();

void aleatorio(Bloco matriz[][TAM]);

// ---------------------------------------------------
