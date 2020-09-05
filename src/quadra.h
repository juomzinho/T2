#ifndef _QUADRA_H_
#define _QUADRA_H_

typedef void* Quadra;

void imprimeQuadra(char cep[], double x, double y, double w, double h, char fill[], char stroke[], char strokeWidth[], char saida[]);

Quadra quadraLista(char cep[], double x, double y, double w, double h, char fill[], char strk[], char sw[]);

char *getCep(Quadra info);

#endif