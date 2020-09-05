#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quadra.h"

typedef struct quadra{
    char cep[20], fill[10], stroke[10], strokeWidth[10];
    double x, y, w, h;
} QStuct;

void imprimeQuadra(char cep[], double x, double y, double w, double h, char fill[], char stroke[], char strokeWidth[], char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");
    if (arq==NULL){
        printf("Erro ao abrir SVG em Quadra!");
        exit(1);
    }

    // double textX, textY;

    // textX = x + (w/2);
    // textY = y + (h/2);

    fprintf(arq,"\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>", x,y,w,h, fill, stroke, strokeWidth);

    fclose(arq);
}

Quadra quadraLista(char cep[], double x, double y, double w, double h, char fill[], char strk[], char sw[]){
    QStuct* quadra = (QStuct*) malloc(sizeof(QStuct));

    strcpy(quadra->cep,cep);
    quadra->x = x;
    quadra->y = y;
    quadra->w = w;
    quadra->h = h;
    strcpy(quadra->fill,fill);
    strcpy(quadra->stroke,strk);
    strcpy(quadra->strokeWidth,sw);

    return quadra;
}

char *getCep(Quadra info){
    QStuct* quadra = (QStuct*) info;
    return quadra->cep;
}