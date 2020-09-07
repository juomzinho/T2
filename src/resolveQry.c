#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "resolveQry.h"
#include "lista.h"
#include "cidade.h"
#include "quadra.h"

void crd(Cidade listas, char id[], char txtArq[]){
    Lista l;
    bool verifica = false;

    FILE *txt;
    txt = fopen(txtArq,"a");

    l = getListaQuadra(listas);
    No node = getFirst(l), aux = getLast(l);
    Info elemento = getInfo(node);

    do{
        node = getNext(node);
        elemento = getInfo(node);
        if (strcmp(getCep(elemento),id)==0){
            printf("%s %s\n", getCep(elemento),id);
            printf("Quadra\n\n");   
            verifica = true;
            break;   
        }
    } while(node!=aux);
    
    if (verifica == false){
        l = getListaHidrante(listas);
        node = getFirst(l);
        aux = getLast(l);
        elemento = getInfo(node);


    }
    
    fclose(txt);
}