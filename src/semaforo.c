#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"
#include "lista.h"

typedef struct semaforo{
    char id[20], fill[10], stroke[10], sw[10];
    double x,y,w,h;
}semaforoInfos;

void imprimeSemaforo(double x, double y, int w, int h, char fill[], char stroke[], char strokeWidth[],char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");
    if (arq==NULL){
        printf("Erro ao abrir SVG em Semaforo!");
        exit(1);
    }

    fprintf(arq,"\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />", x,y,w,h,fill, stroke, strokeWidth);

    fclose(arq);
}

Semaforo semaforoLista(char id[], double x, double y, int w, int h, char fill[], char strk[], char sw[]){
    semaforoInfos* semaforo = (semaforoInfos*) malloc(sizeof(semaforoInfos));

    strcpy(semaforo->id,id);
    semaforo->x = x;
    semaforo->y = y;
    semaforo->w = w;
    semaforo->h = h;
    strcpy(semaforo->fill,fill);
    strcpy(semaforo->stroke,strk);
    strcpy(semaforo->sw,sw);

    return semaforo;
}

char *getIdS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->id;
}

double getXS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->x;
}

double getYS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->y;
}

char *getFillS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->fill;
}

char *getStrokeS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->stroke;
}

char *getSWS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->sw;
}

int getWS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->w;
}

int getHS(Info elemento){
    semaforoInfos* info = (semaforoInfos*) elemento;
    return info->h;
}

void imprimeListaS(Lista l, char saida[]){
    No node = getFirst(l), aux = getLast(l);
    Info elemento;
    semaforoInfos def;

    do{
        elemento = getInfo(node);

        def.x = getXS(elemento);
        def.y = getYS(elemento);
        def.w = getWS(elemento);
        def.h = getHS(elemento);
        strcpy(def.fill, getFillS(elemento));
        strcpy(def.stroke, getStrokeS(elemento));
        strcpy(def.sw, getSWS(elemento));
        imprimeSemaforo(def.x,def.y,def.w,def.h, def.fill,def.stroke,def.sw,saida);

        node = getNext(node);  
    } while (node!=getNext(aux));
    

}