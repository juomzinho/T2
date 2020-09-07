#ifndef _READGEO_H_
#define _READGEO_H_
#include "cidade.h"

/* Esta funcao e resposavel pela leitura do arquivo .geo
ela lê o arquivo, gera um arquivo .svg e armazenda os dados
lidos em listas
para realizar isto ela recebe como parametro o nome do arquivo
a ser lido, o local de saida do arquivo gerado e as listas */
void leituraGeo(char geo[],char saida[], Cidade cidade);

#endif