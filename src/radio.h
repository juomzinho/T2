#ifndef _RADIO_H_
#define _RADIO_H_
#include "lista.h"

typedef void* Radio;

/* esta funcao imprime um radio-base no arquivo svg
ela recebe como parametro os dados do radio-base
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeRadio(double x, double y, int raio, char fill[], char stroke[], char strokeWidth[], char saida[]);

/* esta funcao aloca espaço na memoria e armazena os dados do radio-base
e retorna o elemento criado*/
Radio radioLista(char id[], double x, double y, int raio, char fill[], char strk[], char sw[]);

/* esta funcao retorna o id de um radio-base
ela recebe o elemento onde o radio-base esta
armazenado como parametro */
char *getIdR(Info elemento);

/* esta funcao retorna o x de um radio-base
ela recebe o elemento onde o radio-base esta
armazenado como parametro */
double getXR(Info elemento);

/* esta funcao retorna o y de um radio-base
ela recebe o elemento onde o radio-base esta
armazenado como parametro */
double getYR(Info elemento);

/* esta funcao retorna o preenchimento de um radio-base
ela recebe o elemento onde o radio-base esta
armazenado como parametro */
char *getFillR(Info elemento);

/* esta funcao retorna a borda de um radio-base
ela recebe o elemento onde o radio-base esta
armazenado como parametro */
char *getStokeR(Info elemento);

/* esta funcao retorna a espessura da borda de um radio-base
ela recebe o elemento onde o radio-base esta
armazenado como parametro */
char *getSWR(Info elemento);

/* esta funcao percorre a lista de radio-base,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir radio-base passando
essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeListaRB(Lista l, char saida[]);

#endif