#ifndef _FORMAS_H_
#define _FORMAS_H_

typedef void* Formas;

void imprimeCirculo(int id, double raio, double x, double y, char corb[], char corp[],char saida[]);

void imprimeRetangulo(int id, double width, double heigth, double x, double y, char corb[], char corp[],char saida[]);

void imprimeTexto(int id, double x, double y, char corb[],char corp[], char texto[],char saida[]);

#endif