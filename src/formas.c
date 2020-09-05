
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formas.h"

typedef struct circulo{
    int id;
    double raio, x, y;
    char corb[20], corp[20], corl[20], forma;
}circuloStruct;

void imprimeCirculo(int id, double raio, double x, double y, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um circulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" />", x, y, raio, corp, corb);

    fclose(arqsvg);    
}

void imprimeRetangulo(int id, double width, double heigth, double x, double y, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Retangulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" />", x, y, width, heigth, corp, corb);

    fclose(arqsvg);
}

void imprimeTexto(int id, double x, double y, char corb[],char corp[], char texto[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Texto!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\">%s</text>", x, y,corp, corb, texto);

    fclose(arqsvg);
}

