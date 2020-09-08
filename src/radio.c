#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radio.h"

typedef struct radio{
    char id[20], fill[10], stroke[10], sw[10];
    double x, y;
}radioStruct;

void imprimeRadio(double x, double y, char fill[], char stroke[], char strokeWidth[],char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");
    if (arq==NULL){
        printf("Erro ao abrir SVG em Radio!");
        exit(1);
    }

    fprintf(arq,"\n\t<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"7\" ry=\"7\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />", x,y,fill, stroke, strokeWidth);

    fclose(arq);
}

Radio radioLista(char id[], double x, double y, char fill[], char strk[], char sw[]){
    radioStruct* radio = (radioStruct*) malloc(sizeof(radioStruct));

    strcpy(radio->id,id);
    radio->x = x;
    radio->y = y;
    strcpy(radio->fill,fill);
    strcpy(radio->stroke,strk);
    strcpy(radio->sw,sw);

    return radio;
}

char *getIdR(Info elemento){
    radioStruct* info = (radioStruct*) elemento;
    return info->id;
}

double getXR(Info elemento){
    radioStruct* info = (radioStruct*) elemento;
    return info->x;
}

double getYR(Info elemento){
    radioStruct* info = (radioStruct*) elemento;
    return info->y;
}

char *getFillR(Info elemento){
    radioStruct* info = (radioStruct*) elemento;
    return info->fill;
}

char *getStokeR(Info elemento){
    radioStruct* info = (radioStruct*) elemento;
    return info->stroke;
}

char *getSWR(Info elemento){
    radioStruct* info = (radioStruct*) elemento;
    return info->sw;
}


void imprimeListaRB(Lista l, char saida[]){
    No node = getFirst(l), aux = getLast(l);
    Info elemento;
    radioStruct def;

    do{
        elemento = getInfo(node);

        def.x = getXR(elemento);
        def.y = getYR(elemento);
        strcpy(def.fill, getFillR(elemento));
        strcpy(def.stroke, getStokeR(elemento));
        strcpy(def.sw, getSWR(elemento));
        imprimeRadio(def.x, def.y, def.fill, def.stroke, def.sw, saida);

        node = getNext(node); 
    } while (node != getNext(aux));
    
}