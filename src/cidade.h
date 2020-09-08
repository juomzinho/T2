#ifndef _CIDADE_H_
#define _CIDADE_H_
#include "lista.h"

typedef void* Cidade;

/*Inicia e retorna as listas do programa iniciadas
Lista hidrantes, lista quadras, lista formas, lista semaforos
e lista radio*/
Cidade iniciaCidade();

Lista getListaQuadra(Cidade listas);

Lista getListaFormas(Cidade listas);

Lista getListaSemaforo(Cidade listas);

Lista getListaRadio(Cidade listas);

Lista getListaHidrante(Cidade listas);

Lista getListaQRY(Cidade listas);

void removeListas(Cidade cidade);

#endif