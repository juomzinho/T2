#ifndef _FORMAS_H_
#define _FORMAS_H_
#include "lista.h"

typedef void* Formas;

void imprimeCirculo(double raio, double x, double y, char corb[], char corp[],char saida[]);

void imprimeRetangulo(double width, double heigth, double x, double y, char corb[], char corp[],char saida[]);

void imprimeTexto(double x, double y, char corb[],char corp[], char texto[],char saida[]);

Formas circuloLista(int id, double raio, double x, double y, char corb[], char corp[]);

Formas retanguloLista(int id, double w, double h, double x, double y, char corb[], char corp[]);

Formas textoLista(int id, double x, double y, char corb[], char corp[], char text[]);

int getIdF(Info elemento);

char getForma(Info elemento);

double getXF(Info elemento);

double getYF(Info elemento);

double getWF(Info elemento);

double getHF(Info elemento);

double getRaioF(Info elemento);

char *getFillF(Info elemento);

char *getStrokeF(Info elemento);

char *getTextoF(Info elemento);

void imprimeListaF(Lista l,char saida[]);

#endif