#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H

void jogar(ESTADO *e, COORDENADA c,FILE *ficheiro);
ERROS verifica_jogada (ESTADO *e, COORDENADA c);
int fim_jogo(ESTADO *e);

#endif //PROJETOLI2_LOGICA_H
