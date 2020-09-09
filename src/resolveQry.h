#ifndef _RESOLVEQRY_H_
#define _RESOLVEQRY_H_
#include "cidade.h"

void criaCirculo(Lista l, double raio, double x, double y);

void criaLinha(double x, double y, char cep[], Cidade listas);

void criaRetanguloQry(double x, double y, double w, double h, char sw[], Lista lista);

void criaRetFormasQry(double x, double y, double w, double h, char sw[], Lista lista, char forma);

void car(Cidade listas, double x, double y, double w, double h, char txtArq[]);

void crd(Cidade listas, char id[], char txtArq[]);

void cbq(Cidade listas, double x, double y, double raio, char cstrk[], char txtarq[]);

void del(Cidade listas, char id[], char txtarq[]);

void dq(Cidade listas, char id[], double r, bool verifica, char txtarq[]);

bool PontoInterno(double x1, double y1, double x2, double y2, double raio);

bool PontoInternoRet(double px, double py, double x, double y, double h, double w);

void imprimeQry(Lista l, char saida[]);

void imprimeLinha(double x, double y, char cep[], char saida[]);

void imprimeLinhaD(double x, double y, double area, char saida[]);

void imprimeCirculoQry(double x, double y, double raio, char saida[]);

void imprimeQuadraQRY(double x, double y, double w, double h, char sw[], char saida[]);

void imprimeRetT(double x, double y, double w, double h, char sw[], char saida[]);

void imprimeRet(double x, double y, double w, double h, char sw[], char saida[]);

void oFormas(int j, int k, Lista lista, char txt[]);

void iFormas(int j, double x, double y, Lista lista, char txt[]);

void pnt(int j, char stroke[], char fill[], Lista lista, char txt[]);

void pntplus(int j, int k, char stroke[], char fill[], Lista lista, char txt[]);

void delf(int j, Lista lista, char txt[]);

void delfplus(int j, int k, Lista lista, char txt[]);

#endif