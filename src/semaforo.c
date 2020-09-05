#include <stdio.h>
#include <stdlib.h>
#include "semaforo.h"

typedef struct semaforo{
    char id[20], fill[10], stroke[10], sw[10];
    double x,y;
}semaforoInfos;

void imprimeSemaforo(char id[], double x, double y, char fill[], char stroke[], char strokeWidth[],char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");
    if (arq==NULL){
        printf("Erro ao abrir SVG em Semaforo!");
        exit(1);
    }

    fprintf(arq,"\n\t<rect x=\"%lf\" y=\"%lf\" width=\"4\" height=\"10\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />", x,y,fill, stroke, strokeWidth);

    fclose(arq);
}

Semaforo semaforoLista(char id[], double x, double y, char fill[], char strk[], char sw[]){
    semaforoInfos* semaforo = (semaforoInfos*) malloc(sizeof(semaforoInfos));

    strcpy(semaforo->id,id);
    semaforo->x = x;
    semaforo->y = y;
    strcpy(semaforo->fill,fill);
    strcpy(semaforo->stroke,strk);
    strcpy(semaforo->sw,sw);

    return semaforo;
}