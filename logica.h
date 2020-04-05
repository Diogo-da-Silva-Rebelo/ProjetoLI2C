/**
\brief Estrutura Lógica
*/
#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H

int jogar(ESTADO *e, COORDENADA c,FILE *ficheiro);
int verifica_jogada (ESTADO *e, COORDENADA c);
int fim_jogo(ESTADO *e);

#endif //PROJETOLI2_LOGICA_H
