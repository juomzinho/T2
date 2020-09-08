#ifndef _QUADRA_H_
#define _QUADRA_H_
#include "lista.h"

typedef void* Quadra;

void imprimeQuadra(char cep[], double x, double y, double w, double h, char fill[], char stroke[], char strokeWidth[], char saida[]);

Quadra quadraLista(char cep[], double x, double y, double w, double h, char fill[], char strk[], char sw[]);

char *getCep(Quadra info);

double getXQ(Quadra info);

double getYQ(Quadra info);

double getWQ(Quadra info);

double getHQ(Quadra info);

char *getFillQ(Quadra info);

char *getStrokeQ(Quadra info);

char *getSWQ(Quadra info);

double getAreaQuadra(Quadra info);

void setStokeQ(char cstrk[], Quadra elemento);

void imprimeListaQ(Lista l, char saida[]);

#endif