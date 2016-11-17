// PROTÓTIPOS DE STRUCTS -----------------------



// -------------------------------------------

// PROTÓTIPOS DE FUNÇÕES ----------------------

void hideCursor(); // Apaga o cursor

void forSquare(int x, int y); // Loop for que pinta o quadrado na tela

void printSquare(int x, int y, int color); // Função principal que imprime o quadrado

void eraseSquare(int x, int y); // Apaga o último quadrado

int canMove(int x, int y, int modX, int modY); // Verifica se o quadrado pode mover-se

void getModXY(char key, int *modX, int *modY); // Pega o deslocamento do quadrado

int whileGetKey(); // Loop para pegar entrada do usuário

char getKey(); // Função para pegar entrada do usuário

void whileMain(); // Comanda a entrada do usuário direcionando as setas

// -------------------------------------------
