#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quadra.h"
#include "lista.h"

typedef struct quadra{
    char cep[20], fill[10], v[10], stroke[10], strokeWidth[10];
    double x, y, w, h;
} QStuct;

void imprimeQuadra(char cep[], double x, double y, double w, double h, char fill[], char stroke[], char strokeWidth[], char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");
    if (arq==NULL){
        printf("Erro ao abrir SVG em Quadra!");
        exit(1);
    }
    fprintf(arq,"\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>", x,y,w,h, fill, stroke, strokeWidth);

    fclose(arq);
}

void imprimeQuadraQRY(double x, double y, double w, double h, char sw[], char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"beige\" stroke=\"olive\" stroke-width=\"%s\" rx=\"20\"/>\n", x, y, w, h, sw);

    fclose(arq);
}


Quadra quadraLista(char cep[], double x, double y, double w, double h, char v[], char fill[], char strk[], char sw[]){
    QStuct* quadra = (QStuct*) malloc(sizeof(QStuct));

    strcpy(quadra->cep,cep);
    quadra->x = x;
    quadra->y = y;
    quadra->w = w;
    quadra->h = h;
    strcpy(quadra->v,v);
    strcpy(quadra->fill,fill);
    strcpy(quadra->stroke,strk);
    strcpy(quadra->strokeWidth,sw);

    return quadra;
}

char *getCep(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->cep;
}

double getXQ(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->x;
}


char *getTipoQ(Quadra elemento){
    QStuct* quadra = (QStuct*) elemento;
    return quadra->v;
}

double getYQ(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->y;
}

double getWQ(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->w;
}

double getHQ(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->h;
}

char *getFillQ(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->fill;
}

char *getStrokeQ(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->stroke;
}

char *getSWQ(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->strokeWidth;
}

double getAreaQuadra(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return (quadra->w * quadra->h);
}

void setStokeQ(char strk[],Quadra elemento){
    QStuct* quadra = (QStuct*) elemento;
    strcpy(quadra->stroke,strk);
}

void setFillQ(char fill[],Quadra elemento){
    QStuct* quadra = (QStuct*) elemento;
    strcpy(quadra->fill,fill);
}

void setTipoQ(char v[], Quadra elemento){
    QStuct* quadra = (QStuct*) elemento;
    strcpy(quadra->v, v);
}

void imprimeListaQ(Lista l, char saida[]){
    No node = getFirst(l), aux = getLast(l);
    Info elemento;
    QStuct def;

    node = getNext(node);
    node = getPrevious(node);
    
    do{
        elemento = getInfo(node);

        strcpy(def.cep,getCep(elemento));
        def.x = getXQ(elemento);
        def.y = getYQ(elemento);
        def.h = getHQ(elemento);
        def.w = getWQ(elemento);
        strcpy(def.v,getTipoQ(elemento));
        strcpy(def.stroke,getStrokeQ(elemento));
        strcpy(def.fill,getFillQ(elemento));
        strcpy(def.strokeWidth,getSWQ(elemento));

        if (strcmp(def.v,"normal")==0){
            imprimeQuadra(def.cep, def.x, def.y, def.w, def.h, def.fill, def.stroke, def.strokeWidth,saida);
        }else{
            imprimeQuadraQRY(def.x, def.y, def.w, def.h, def.strokeWidth,saida);
        }
        
        
        node = getNext(node);
    } while (node!=getNext(aux));
    
}