#ifndef _SEMAFORO_H_
#define _SEMAFORO_H_

typedef void* Semaforo;

void imprimeSemaforo(char id[], double x, double y, char fill[], char stroke[], char strokeWidth[],char saida[]);

Semaforo semaforoLista(char id[], double x, double y, char fill[], char strk[], char sw[]);

#endif