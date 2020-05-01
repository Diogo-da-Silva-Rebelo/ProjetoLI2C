/**
\brief Estruturas de Dados.
*/
#ifndef ___DADOS_H___
#define  ___DADOS_H___
#define BUF_SIZE 1024

/**
\brief Tipo de dados para a casa.
*/
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

/**
\brief Tipo de dados para as coordenadas.
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Tipo de dados para a jogada.
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas.
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado.
*/

typedef struct {
    /** O tabuleiro. */
    CASA tab[9][9];
    /** As jogadas. */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt. */
    int num_jogadas;
    /** O jogador atual. */
    int jogador_atual;
    /** O nº de comando, usado no prompt. */
    int num_comando;
    /** A coordenada da última jogada. */
    COORDENADA ultima_jogada;
} ESTADO;


void altera_comando(ESTADO *e, int cmd);
void armazena_jogada(COORDENADA c1, COORDENADA c2, int i, ESTADO *estado);
ESTADO *inicializar_estado();
int obter_comando(ESTADO *e);
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
COORDENADA obter_ultima_jogada(ESTADO *estado);
COORDENADA obter_x_jogada(ESTADO *e,int i,int jogador);
void refresh_board (ESTADO *e, COORDENADA c);
void str_to_casa (char *linha, ESTADO *estado, int l);

#endif //___DADOS_H___