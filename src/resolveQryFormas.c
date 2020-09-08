#include <stdio.h>
#include <stdlib.h>
#include "formas.h"
#include "lista.h"
#include "resolveQryFormas.h"

void oFormas(int j, int k, Lista lista){
    No *aux = getFirst(lista), *aux2 = getFirst(lista);
    Info elemento1, elemento2;

    while (aux!=NULL){
        elemento1 = getInfo(aux);

        if (getIdF(elemento1)==j){

             while (aux2!=NULL){
                elemento2 = getInfo(aux);
                    if(k == getIdF(elemento2)){
                        if (getForma(elemento1) == 'c' && getForma(elemento2) == 'c'){
                            /* code */
                        }
                        if (getForma(elemento1) == 'r' && getForma(elemento2) == 'c'){
                            /* code */
                        }
                        if (getForma(elemento1) == 'c' && getForma(elemento2) == 'r'){
                            /* code */
                        }
                        if (getForma(elemento1) == 'r' && getForma(elemento2) == 'r'){
                            /* code */
                        }                        
                    }
                aux2 = getNext(aux2);
            }
        }    

        aux = getNext(aux);
    }
}