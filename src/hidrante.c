#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidrante.h"
#include "lista.h"

typedef struct hidrante{
    char id[20], fill[20], strk[20], sw[10];
    double x, y; 
} infosH;

void imprimeHidrante(double x, double y, char fill[], char stroke[], char strokeWidth[], char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");

    if (arq==NULL){
        printf("Erro ao abrir SVG em Quadra!");
        exit(1);
    }

    fprintf(arq,"\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"4\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>", x,y,fill,stroke,strokeWidth);
    fclose(arq);    
}

Hidrante hidranteLista(char id[], double x, double y, char fill[], char stroke[], char sw[]){
    infosH* hidrante = (infosH*) malloc(sizeof(infosH));

    strcpy(hidrante->id,id);
    hidrante->x = x;
    hidrante->y = y;
    strcpy(hidrante->fill,fill);
    strcpy(hidrante->strk,stroke);
    strcpy(hidrante->sw,sw);

    return hidrante;
}

char *getIdHidrante(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->id;
}