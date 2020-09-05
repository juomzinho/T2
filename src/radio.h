#ifndef _RADIO_H_
#define _RADIO_H_

typedef void* Radio;

void imprimeRadio(char id[], double x, double y, char fill[], char stroke[], char strokeWidth[], char saida[]);

Radio radioLista(char id[], double x, double y, char fill[], char strk[], char sw[]);

#endif