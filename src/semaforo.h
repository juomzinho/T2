#ifndef _SEMAFORO_H_
#define _SEMAFORO_H_
#include "lista.h"

typedef void* Semaforo;

/* esta funcao imprime um semaforo no arquivo svg
ela recebe como parametro os dados do semaforo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeSemaforo(double x, double y, char fill[], char stroke[], char strokeWidth[],char saida[]);

/* esta funcao aloca espaço na memoria e armazena os dados do semaforo
e retorna o elemento criado*/
Semaforo semaforoLista(char id[], double x, double y, char fill[], char strk[], char sw[]);

/* esta funcao retorna o id de um semaforo
ela recebe o elemento onde o semaforo esta
armazenado como parametro */
char *getIdS(Info elemento);

/* esta funcao retorna o x de um semaforo
ela recebe o elemento onde o semaforo esta
armazenado como parametro */
double getXS(Info elemento);

/* esta funcao retorna o y de um semaforo
ela recebe o elemento onde o semaforo esta
armazenado como parametro */
double getYS(Info elemento);

/* esta funcao retorna o preenchimento de um semaforo
ela recebe o elemento onde o semaforo esta
armazenado como parametro */
char *getFillS(Info elemento);

/* esta funcao retorna a borda de um semaforo
ela recebe o elemento onde o semaforo esta
armazenado como parametro */
char *getStrokeS(Info elemento);

/* esta funcao retorna a espessura da borda de um semaforo
ela recebe o elemento onde o semaforo esta
armazenado como parametro */
char *getSWS(Info elemento);

/* esta funcao percorre a lista de semaforos,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir semaforo passando
essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeListaS(Lista l, char saida[]);

#endif