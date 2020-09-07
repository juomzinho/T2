#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "quadra.h"

typedef struct node{
    Info info;
    struct node *anterior;
    struct node *proximo;
} NoStruct;

typedef struct lista{
    NoStruct *primeiro;
    NoStruct *ultimo;
} ListaStruct;


Lista create(){

    ListaStruct* lista = (ListaStruct*) malloc(sizeof(ListaStruct));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;

};

void insere(Lista l, Info info){

    ListaStruct* lista = (ListaStruct*) l;

    NoStruct* no = (NoStruct*) malloc(sizeof(NoStruct));
    no->info = info;

    if(lista->primeiro == NULL){
        no->anterior = NULL;
        lista->primeiro = no;
    }
    else{
        lista->ultimo->proximo = no;
        no->anterior = lista->ultimo;
    }

    no->proximo = NULL;
    lista->ultimo = no;
    
}


void insertAfter(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (aux==posicao){
            no->proximo = aux->proximo;
            no->anterior = aux;
            aux->proximo = no;
        }
        aux = aux->proximo;
    }
    
}


void insertBefore(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (aux==posicao){
            no->anterior = aux->anterior;
            no->proximo = aux;
            aux->anterior = no;   
            if (no->anterior==NULL){
                lista->primeiro = no;
            }
                     
        }
        aux = aux->proximo;
    }
}

int length(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux;
    int i = 0; 
    aux = lista->primeiro;
    while (aux!=NULL){
        i++;
        aux = aux->proximo;
    }
    
    return i;
}

void removeElemento(Lista l, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;
    aux = lista->primeiro;
    
    while (aux!=NULL){
        if(aux->info == info){
            if (aux==lista->primeiro){
                lista->primeiro = aux->proximo;
                lista->primeiro->anterior = NULL;
            }
            if(aux==lista->ultimo){
                lista->ultimo = aux->anterior;
                lista->ultimo->proximo = NULL;
            }

            aux2 = aux->proximo;
            aux2->anterior = aux->anterior;

            if(aux->anterior!=NULL){
                aux->anterior->proximo = aux2;
            }
            free(aux->info);
            free(aux);
            break;
         }
        aux = aux->proximo;
    }  
}

No getFirst(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->primeiro;
}

No getLast(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->ultimo;
}

No getNext(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->proximo;
}

No getPrevious(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->anterior;
}

Info getInfo(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->info;
}

void percorreLista(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro;

    while (aux!=NULL){
        printf("cep = %s\n", getCep(aux->info));
        aux = aux->proximo;
    }
    
}

void removePorCep(Lista l, char cep[]){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro;
    while (aux!=NULL){
        if(strcmp(getCep(aux->info),cep)==0){
            printf("%s %s", cep, getCep(aux->info));
            removeElemento(lista, aux->info);
            break;
        }
        aux = aux->proximo;
    }
    
}

void desalocaLista(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;

    aux = lista->primeiro;

    while (aux!=NULL){
        aux2 = aux->proximo;
        free(aux->info);
        free(aux);
        aux = aux2;
    }   
}

