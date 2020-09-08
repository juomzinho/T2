#ifndef _RADIO_H_
#define _RADIO_H_
#include "lista.h"

typedef void* Radio;

void imprimeRadio(double x, double y, char fill[], char stroke[], char strokeWidth[], char saida[]);

Radio radioLista(char id[], double x, double y, char fill[], char strk[], char sw[]);

char *getIdR(Info elemento);

double getXR(Info elemento);

double getYR(Info elemento);

char *getFillR(Info elemento);

char *getStokeR(Info elemento);

char *getSWR(Info elemento);

void imprimeListaRB(Lista l, char saida[]);

#endif