
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formas.h"

typedef struct circulo{
    int id;
    double raio, x, y;
    char corb[20], corp[20], forma;
}circuloStruct;

typedef struct retangulo{
    int id;
    double w, h, x, y;
    char corb[20], corp[20], forma;
}retanguloStruct;

typedef struct texto{
    int id;
    double x, y;
    char corb[20], corp[20], texto[50], forma;
}textoStruct;

void imprimeCirculo(double raio, double x, double y, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um circulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" />", x, y, raio, corp, corb);

    fclose(arqsvg);    
}

void imprimeRetangulo(double width, double heigth, double x, double y, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Retangulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" />", x, y, width, heigth, corp, corb);

    fclose(arqsvg);
}

void imprimeTexto(double x, double y, char corb[],char corp[], char texto[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Texto!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\">%s</text>", x, y,corp, corb, texto);

    fclose(arqsvg);
}

Formas circuloLista(int id, double raio, double x, double y, char corb[], char corp[]){
    circuloStruct* circ = (circuloStruct*) malloc(sizeof(circuloStruct));

    circ->id = id;
    circ->raio = raio;
    circ->x = x;
    circ->y = y;
    strcpy(circ->corb,corb);
    strcpy(circ->corp,corp);
    circ->forma = 'c';

    return circ;
}

Formas retanguloLista(int id, double w, double h, double x, double y, char corb[], char corp[]){
    retanguloStruct* ret = (retanguloStruct*) malloc(sizeof(retanguloStruct));

    ret->id = id;
    ret->x = x;
    ret->y = y;
    ret->w = w;
    ret->h = h;
    strcpy(ret->corb,corb);
    strcpy(ret->corp,corp);
    ret->forma = 'r';

    return ret;
}

Formas textoLista(int id, double x, double y, char corb[], char corp[], char text[]){
    textoStruct* txt = (textoStruct*) malloc(sizeof(textoStruct));
    
    txt->id = id;
    txt->x = x;
    txt->y = y;
    strcpy(txt->corb, corb);
    strcpy(txt->corp, corp);
    strcpy(txt->texto, text);
    txt->forma = 't';

    return txt;
}