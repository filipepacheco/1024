/*
        INF01202 – ALGORITMOS E PROGRAMAÇÃO – 2016-2
                TRABALHO PRÁTICO

Objetivo:
Exercitar as habilidades e conceitos de programação desenvolvidos ao longo da disciplina pela implementação de uma aplicação em C,
desenvolvida por um grupo de 2 alunos da mesma turma ou de turmas diferentes (C e D). A coordenação de um trabalho em equipe faz
parte da habilidade de programar. O programa deve ser estruturado de forma a receber um conjunto de entradas (no início da execução
ou durante o uso do programa), cuja consistência deve ser verificada, processá-lo, e fornecer uma ou mais saídas.

Produto do trabalho e datas de entrega:
O trabalho será entregue em 3 etapas:
a) Relatório de Andamento: 20 Outubro
Apresentação na aula prática do código do trabalho onde será formalizada a dupla, e
mostrada a tela principal do jogo com a movimentação e soma dos blocos funcionando e as
estruturas de dados necessárias.

b) Entrega do código 01 de Dezembro até às 12 horas pelo Moodle.
Upload no Moodle em tarefa própria de um ÚNICO arquivo compactado cujo nome do
arquivo é o nome dos alunos contendo:

• Programa executável: o programa deve rodar nas máquinas do laboratório das
aulas práticas. Verifique se executará sem exceções naquele local antes de entregar.

• Código documentado (arquivos .c, .cpp). Inclua o nome dos autores no cabeçalho
do programa.

• Bibliotecas adicionais às que estão disponíveis no laboratório, exceto as conio e
curses.

Se houver exceções aos requisitos listados neste enunciado, descreva como comentário no início do arquivo fonte.

Você pode fazer upload de diferentes versões e ir aperfeiçoando o programa. Faça o upload assim que tiver uma versão executável,
de modo a garantir a entrega e precaver-se de problemas com servidor, redes, internet, etc.

c) Apresentação
Programa será apresentado no dia 1º de dezembro na aula prática. O arquivo a ser
apresentado será aquele carregado no Moodle sem alterações. Ambos alunos devem
dominar o código para explicá-lo. A ausência de um dos alunos na apresentação acarretará
decréscimo da nota para o aluno ausente.


Avaliação:

O programa deve atender todos os requisitos listados neste enunciado, não deve apresentar erros de compilação e rodar normalmente,
pontos serão reduzidos caso contrário.

A aplicação desenvolvida deverá demonstrar os seguintes conteúdos que serão avaliados:

1. (2 pontos) Habilidade em estruturar programas pela decomposição da tarefa em
subtarefas, utilizando subprogramação para implementá-las.

2. (2 pontos) Documentação de programas (indentação, utilização de nomes de
variáveis, abstração dos procedimentos para obter maior clareza, uso de comentários no
código).

3. (2 pontos) Domínio na utilização de tipos de dados simples e estruturados (arranjos,
estruturas) e passagem de parâmetros. Uso exclusivo de variáveis locais.

4. (1 ponto) Formatação e controle de entrada e saída, com construção de interfaces
que orientem corretamente o usuário sem instruções ou intervenção adicional do
programador.

5. (1 ponto) Utilização de arquivos binários e de texto.

6. (2 pontos) Atendimento aos requisitos do enunciado do programa: modelo de
estrutura de dados, de interação e de relatórios, ordenação dos dados, opções do programa,
etc.

A nota do trabalho prático corresponderá a 10% da nota final da disciplina. A apresentação do trabalho prático, mesmo que
rodando parcialmente, é pré-requisito para realizar a recuperação.

Contextualização:
Deverá ser desenvolvido o jogo “1024”. Este jogo consiste em uma grade de, no
mínimo, 4x4, onde estão contidos blocos com potências de dois (20, 21, ..., 210, ...). As
ações do jogador consistem em movimentar todos os quadrados para cima, para baixo,
para a esquerda ou para a direita. Cada vez que o jogador realiza um movimento, um
bloco aleatório é colocado em uma posição também aleatória (que está vazia). Quando
dois blocos iguais colidirem, eles se juntarão formando um bloco, cujo valor será a soma
dos dois. O objetivo é somar o máximo de quadrados possível até que um deles tenha
1024 dentro. O jogador perde a partida se não for mais possível movimentar os blocos.


Interface do jogo:
A implementação do espaço do jogo pode ser feita na janela do prompt de comando,
podendo ser alterado seu tamanho. A interface do jogo deve conter o nome do jogo e as
informações atualizadas do jogador, incluindo pelo menos nome, pontuação atual, recorde
e modo de jogo. O local onde as informações do jogador estarão posicionadas é de escolha
dos alunos, porém espera-se que estejam bem posicionadas, alinhadas e com cores de fácil
visualização. O fundo poderá ser personalizado e a tela principal do jogo (“grade”) deverá
ocupar o maior espaço possível. O exemplo abaixo mostra o tamanho mínimo.

 Exemplo de interface:

• Blocos:
a) Os blocos devem conter o número correspondente centralizado e com uma
cor visível. (Obs. Para apresentação final, sugere-se não utilizar a cor vermelha que
tem baixa resolução no projetor.)

b) Locais onde não contém blocos deverão estar claramente identificados com
uma cor diferente e neutra.

c) As cores utilizadas para os blocos deverão seguir uma escala e deverão ser
únicas para cada número, exceto quando não houverem mais cores à disposição.

 • Menu: O menu principal deverá conter pelo menos os seguintes dados e opções:
a) Dados: Nome dos dois alunos e nome do jogo.
b) Opções:
a. Modo Clássico
b. Modo Fácil
c. Modo Personalizado
d. Rank
e. Sair

 • Menu do Rank: O menu do rank deverá conter pelo menos as seguintes opções:
a) Exibir Rank
b) Resetar Rank
c) Salvar Rank (para arquivo texto)
d) Voltar ao Menu Principal

Obs: Em todo o momento do jogo, seja no menu do rank ou no meio de uma partida,
a tecla ESC permite retornar ao menu inicial.

Funcionamento do jogo:
Ao iniciar qualquer modo de jogo, deverá ser perguntado o nome do jogador para que seja possível achar seu
recorde e para que seja possível exibir seu nome na tela do jogo.

Após lido o nome, o jogo será iniciado de acordo com cada modo.

• Modo Clássico:
Após o jogador ter colocado seu nome, um bloco aleatório será criado e será posicionado aleatoriamente. O jogador então poderá movê-lo
para qualquer direção que quiser. Ao mover o bloco para a direita, por exemplo, ele será posicionado noponto mais à direita possível,
e então um novo bloco aparecerá (exemplo ao lado). A partir deste momento, o jogador movimentará os blocos para a direção que quiser,
lembrando que sempre serão movimentados todos os blocos para a mesma direção (e ao mesmo tempo) sempre para a posição mais próxima da
borda. Sempre que houver uma movimentação, um novo bloco aleatório aparecerá. Quando dois blocos iguais colidirem eles se
juntarão e formarão um bloco somando seus números/valores. Ao lado encontra-se um exemplo, onde movimentamos todos os blocos do exemplo
anterior para cima. O jogador ganhará o jogo quando conseguir formar um bloco com o número 1024, então, será perguntado se ele deseja
continuar jogando, ou se ele deseja finalizar o jogo. Se o jogador escolher continuar jogando, o jogo terminará
somente quando o jogador preencher toda a grade e não forem mais possíveis movimentações. Obs: Para este modo de jogo,
o tamanho da grade será de 4 x 4, podendo conter até 16 blocos.

• Modo Fácil:
O Modo Fácil possui as mesmas regras do modo anterior, porém com a possibilidade
de desfazer suas cinco últimas movimentações. Ao desfazer uma movimentação, o jogo
voltará exatamente como estava antes de ser movido. Ao desfazer 5 movimentos
consecutivos, deverá ser exibida uma observação dizendo que não é mais possível utilizar
esta opção. Ao mover novamente, o jogador poderá desfazer sua jogada.

• Modo Personalizado:
Este modo possui as mesmas regras do Modo Clássico, porém o tamanho de sua grade
deverá ser definido pelo usuário, podendo ser de 4 x 4 até 6 x 6. O jogo deverá dar a opção
para que o jogador escolha ou digite o tamanho.
Observações sobre o funcionamento do jogo:

• Blocos aleatórios: blocos aleatórios poderão aparecer em qualquer posição vazia da
grade, podendo conter os números 1 ou 2, cada um com 50% de chance de aparecer.

• Soma dos blocos: se três blocos colidirem, deverão ser somados somente os dois
primeiros. Por exemplo, se três blocos de número dois forem movimentados para a direita,
deverão ser somandos somente os dois mais a direita. Caso existam três blocos na seguinte
ordem: | 4 | 2 | 2 | e eles forem empurrados para a direita, o resultado deverá ser dois
blocos com o número 4, ou seja, o bloco resultante de uma soma não deverá ser utilizado
para realizar outra soma no mesmo movimento, será necessário que o jogador realize outra
movimentação.

Pontuação:
A pontuação de cada jogada deverá começar zerada. A cada soma, deverá ser adicionado à pontuação, o valor resultante desta soma.

Controles:
A movimentação dos blocos deverá ser feita pelas flechas do teclado, não deverão ser
utilizados os botões “W/A/S/D”. No Modo Fácil, fica livre a escolha de um botão para
desfazer a jogada.
Todos os controles deverão ser exibidos para o jogador. Eles poderão ser exibidos
antes da partida iniciar ou poderão estar ao lado da grade dos blocos.

Rank:
O rank deverá armazenar as seguintes informações de cada jogador:
a) Nome
b) Maior Pontuação
c) Ganhou o jogo? (Esta informação deverá ser referente à partida de maior
pontuação do jogador).

Essas informações deverão ficar salvas em um arquivo binário para que o rank não
seja perdido ao fechar o jogo.

 Exibir Rank: na opção de exibir rank, deverão ser exibidos as melhores dez
pontuações em ordem decrescente.

 Resetar Rank: esta opção deverá apagar todos os registros do rank (inclusive
do arquivo binário).

 Salvar Rank: esta opção permite salvar os registros da memória para um
arquivo texto, em ordem decrescente. Caso o nome do jogador ocorra mais de
uma vez no rank, seu registro de maior pontuação deverá ser salvo,
permanecendo apenas uma ocorrência do jogador no arquivo. O programa deve
perguntar ao usuário o nome do arquivo onde deverá salvar os dados em
formato de TEXTO.

Os dados serão salvos com o formato:
“Nome: <nome>; Pontuacao: <pontuação>; Ganhou: <sim/nao>;”
Ex: “Nome: Lucas Hagen; Pontuacao: 28040; Ganhou: sim;”

Dicas úteis:
1. Evite utilizar o comando de limpar tela nas movimentações de jogo. Apague os
elementos do jogo ao plotar o mesmo elemento no lugar com a cor de fundo.

2. Represente cada um dos blocos como um tipo struct com as respectivas
propriedades associadas. O espaço de jogo deve ser representado como uma matriz de
estruturas.

STRUCTS UTEIS
typedef struct {
int x;   
int y;
} COORD;   // Se utilizar a lib  WINDOWS.H, esta estrutura já está definida
typedef struct {
    int valor;    // numero a ser mostrado no espaço de jogo
    int cor; // cor do bloco
} BLOCO;
typedef struct {
      char nome[MAX_STR];   // nome do jogador  
      int pontuacao;     // pontuação a ser acumulada durante o jogo pelo jogador
int  ganhou;        // booleana que controla o final do jogo   
} JOGADOR;
  FUNCOES E DEFINICOES UTEIS DA CONIO2  
*   * Colors which you can use in your application.   
typedef enum
{
    BLACK,            /*< black color
    BLUE,               /**< blue color
    GREEN,            /**< green color
    CYAN,             /**< cyan color
    RED,                /**< red color *
    MAGENTA,          /**< magenta color *
    BROWN,            /**< brown color *
    LIGHTGRAY,        /**< light gray color *
    DARKGRAY,         /*< dark gray color
    LIGHTBLUE,        /**< light blue color
    LIGHTGREEN,       /**< light green color *
    LIGHTCYAN,        /**< light cyan color *
    LIGHTRED,         /**< light red color *
    LIGHTMAGENTA,     /**< light magenta color *
    YELLOW,           /**< yellow color *
    WHITE             /**< white color *
} COLORS
/*  FUNCOES E DEFINICOES UTEIS DA CONIO.H  *
void clrscr(); // limpa a tela
void gotoxy (int x, int y); // posiciona o cursor em (x,y)
void cputsxy (int x, int y, char* str);  //imprime str na posicao x, y  
void putchxy (int x, int y, char ch);  //imprime char na posicao x, y  
void textbackground (int cor); // altera cor de fundo ao escrever na tela
void textcolor (int cor); // altera cor dos caracteres ao escrever na tela
char getch(); // devolve um caractere lido do teclado, sem eco na tela
int   kbhit(); // devolve true se alguma tecla foi pressionada, sem eco na tela
/*  FUNCOES E DEFINICOES UTEIS DA WINDOWS.H  *
void Sleep (int t); // paralisa o programa por t milissegundos 
void GetKeyState (int tecla); // pode ser usada para ler as setas do teclado
Exemplo de uso (trecho):  if (GetKeyState (VK_RIGHT) & 0x80) // se a tecla “seta para direita” está pressionada       (…) 
/*  FUNCOES E DEFINICOES UTEIS DA TIME.H  *
clock();
Exemplo de uso (trecho): 
    double tempo;
    clock_t inicio, fim;
    inicio = clock(); // salva tempo ao iniciar
   (…) // trecho do programa
    fim = clock(); // salva tempo ao terminar
    tempo_total_segundos = (int) ((fim – inicio) / CLOCKS_PER_SEC); /* calcula o número
de segundos decorridos durante a execução do trecho do programa*/ 
   */
