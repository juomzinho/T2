
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formas.h"

typedef struct f{
    int id;
    double raio, x, y, w, h;
    char corb[20], corp[20], texto[50],forma;
}formasStruct;

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
    formasStruct* circ = (formasStruct*) malloc(sizeof(formasStruct));

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
    formasStruct* ret = (formasStruct*) malloc(sizeof(formasStruct));

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
    formasStruct* txt = (formasStruct*) malloc(sizeof(formasStruct));
    
    txt->id = id;
    txt->x = x;
    txt->y = y;
    strcpy(txt->corb, corb);
    strcpy(txt->corp, corp);
    strcpy(txt->texto, text);
    txt->forma = 't';

    return txt;
}

int getIdF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->id;
}

char getForma(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->forma;
}

double getXF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->x;
}

double getYF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->y;
}

double getWF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->w;
}

double getHF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->h;
}

double getRaioF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->raio;
}

char *getFillF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->corp;
}

char *getStrokeF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->corb;
}

char *getTextoF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->texto;
}

void imprimeListaF(Lista l,char saida[]){
    No node = getFirst(l), aux = getLast(l);
    Info elemento;
    char forma;
    formasStruct def;

    do{
        elemento = getInfo(node);
        forma = getForma(elemento);

        if (forma=='c'){
            def.x = getXF(elemento);
            def.y = getYF(elemento);
            def.raio = getRaioF(elemento);
            strcpy(def.corb,getStrokeF(elemento));
            strcpy(def.corp,getFillF(elemento));

            imprimeCirculo(def.raio, def.x, def.y, def.corb, def.corp, saida);
        }
        if (forma=='r'){
            def.x = getXF(elemento);
            def.y = getYF(elemento);
            def.w = getWF(elemento);
            def.h = getHF(elemento);
            strcpy(def.corb,getStrokeF(elemento));
            strcpy(def.corp,getFillF(elemento));

            imprimeRetangulo(def.w, def.h, def.x, def.y, def.corb, def.corp, saida);
        }
        if (forma=='t'){
            def.x = getXF(elemento);
            def.y = getYF(elemento);
            strcpy(def.corb,getStrokeF(elemento));
            strcpy(def.corp,getFillF(elemento));
            strcpy(def.texto,getTextoF(elemento));

            imprimeTexto(def.x, def.y,def.corb, def.corp, def.texto, saida);
        }

        node = getNext(node);
    } while (node!=getNext(aux));
    
}