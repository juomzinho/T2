#ifndef _LISTA_H_
#define _LISTA_H_

typedef void* Lista;
typedef void* No;
typedef void* Info;

Lista create();

void insere(Lista l, Info info);

No getFirst(Lista lista);

No getLast(Lista lista);

No getNext(No elemento);

No getInfo(No elemento);

void remove(Lista l, Info info);

#endif