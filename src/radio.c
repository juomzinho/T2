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