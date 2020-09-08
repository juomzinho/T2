#ifndef _SEMAFORO_H_
#define _SEMAFORO_H_
#include "lista.h"

typedef void* Semaforo;

void imprimeSemaforo(double x, double y, char fill[], char stroke[], char strokeWidth[],char saida[]);

Semaforo semaforoLista(char id[], double x, double y, char fill[], char strk[], char sw[]);

char *getIdS(Info elemento);

double getXS(Info elemento);

double getYS(Info elemento);

char *getFillS(Info elemento);

char *getStrokeS(Info elemento);

char *getSWS(Info elemento);

void imprimeListaS(Lista l, char saida[]);

#endif