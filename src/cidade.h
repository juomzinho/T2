#ifndef _CIDADE_H_
#define _CIDADE_H_
#include "lista.h"

typedef void* Cidade;

/*Inicia e retorna as listas do programa iniciadas
Lista hidrantes, lista quadras, lista formas, lista semaforos
e lista radio*/
Cidade iniciaCidade();


Lista getListaQuadra(Cidade listas);

#endif