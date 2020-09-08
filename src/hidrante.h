#ifndef _HIDRANTE_H_
#define _HIDRANTE_H_
#include "lista.h"

typedef void* Hidrante;

/*Esta funcao imprime um hidrante no arquivo svg 
ela recebe como parametro as informções a serem imprimidas no arquivo svg
recebe tambem o endereço de saida do arquivo gerado*/
void imprimeHidrante(double x, double y, char fill[], char stroke[], char strokeWidth[], char saida[]);

Hidrante hidranteLista(char id[], double x, double y, char fill[], char stroke[], char sw[]);

/*Esta funcao recebe os dados de um hidrante armazenado na lista de hidrantes
e retorna o Id do hidrante armazenado naquela posicao da lista */
char *getIdHidrante(Hidrante info);

double getXH(Hidrante info);

double getYH(Hidrante info);

char *getFillH(Hidrante info);

char *getStrokeH(Hidrante info);

char *getSWH(Hidrante info);

void imprimeListaH(Lista l,char saida[]);

#endif