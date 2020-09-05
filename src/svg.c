#include <stdio.h>
#include <stdlib.h>
#include "svg.h"

void abrirSvg(char saida[]){
    FILE *arq;
    arq = fopen(saida,"w");
    
    if (arq==NULL){
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq,"<svg>"); 
    fclose(arq);   
}

void fecharSvg(char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");
    
    if (arq==NULL){
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq,"\n</svg>");
    fclose(arq);
}