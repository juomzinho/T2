#ifndef _FORMAS_H_
#define _FORMAS_H_

typedef void* Formas;

void imprimeCirculo(double raio, double x, double y, char corb[], char corp[],char saida[]);

void imprimeRetangulo(double width, double heigth, double x, double y, char corb[], char corp[],char saida[]);

void imprimeTexto(double x, double y, char corb[],char corp[], char texto[],char saida[]);

Formas circuloLista(int id, double raio, double x, double y, char corb[], char corp[]);

Formas retanguloLista(int id, double w, double h, double x, double y, char corb[], char corp[]);

Formas textoLista(int id, double x, double y, char corb[], char corp[], char text[]);

#endif