#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidrante.h"
#include "lista.h"

typedef struct hidrante{
    char id[20], fill[20], strk[20], sw[10];
    double x, y;
    int raio; 
} infosH;

void imprimeHidrante(double x, double y, int raio, char fill[], char stroke[], char strokeWidth[], char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");

    if (arq==NULL){
        printf("Erro ao abrir SVG em Quadra!");
        exit(1);
    }

    fprintf(arq,"\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>", x,y,raio,fill,stroke,strokeWidth);
    fclose(arq);    
}

Hidrante hidranteLista(char id[], double x, double y, int raio, char fill[], char stroke[], char sw[]){
    infosH* hidrante = (infosH*) malloc(sizeof(infosH));

    strcpy(hidrante->id,id);
    hidrante->x = x;
    hidrante->y = y;
    hidrante->raio = raio;
    strcpy(hidrante->fill,fill);
    strcpy(hidrante->strk,stroke);
    strcpy(hidrante->sw,sw);

    return hidrante;
}

char *getIdHidrante(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->id;
}

double getXH(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->x;
}

double getYH(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->y;
}

int getRaioH(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->raio;
}

char *getFillH(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->fill;
}

char *getStrokeH(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->strk;
}

char *getSWH(Hidrante info){
    infosH* hidrante = (infosH*) info;
    return hidrante->sw;
}


void imprimeListaH(Lista l,char saida[]){
    No node = getFirst(l), aux = getLast(l);
    Info elemento = getInfo(node);
    infosH def;

    do{
        elemento = getInfo(node);

        strcpy(def.id, getIdHidrante(elemento));
        def.x = getXH(elemento);
        def.y = getYH(elemento);
        def.raio = getRaioH(elemento);
        strcpy(def.fill, getFillH(elemento));
        strcpy(def.strk, getStrokeH(elemento));
        strcpy(def.sw, getSWH(elemento));

       // printf("%lf %lf %d %s %s %s %s\n",def.x, def.y, def.raio, def.fill, def.strk, def.sw,saida);

        imprimeHidrante(def.x, def.y, def.raio, def.fill, def.strk, def.sw, saida);
        
        node = getNext(node);
    } while (node!=getNext(aux));
    
}