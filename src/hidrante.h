#ifndef _HIDRANTE_H_
#define _HIDRANTE_H_
#include "lista.h"

typedef void* Hidrante;

/*Esta funcao imprime um hidrante no arquivo svg 
ela recebe como parametro as informções a serem imprimidas no arquivo svg
recebe tambem o endereço de saida do arquivo gerado*/
void imprimeHidrante(double x, double y, char fill[], char stroke[], char strokeWidth[], char saida[]);

Hidrante hidranteLista(char id[], double x, double y, char fill[], char stroke[], char sw[]);

/*Esta funcao recebe os dados de um hidrante armazenado na lista de hidrantes
e retorna o Id do hidrante armazenado naquela posicao da lista */
char *getIdHidrante(Hidrante info);

/*Esta funcao recebe os dados de um hidrante armazenado na lista de hidrantes
e retorna o x do hidrante armazenado naquela posicao da lista */
double getXH(Hidrante info);

/*Esta funcao recebe os dados de um hidrante armazenado na lista de hidrantes
e retorna o y do hidrante armazenado naquela posicao da lista */
double getYH(Hidrante info);

/*Esta funcao recebe os dados de um hidrante armazenado na lista de hidrantes
e retorna o preenchimento do hidrante armazenado naquela posicao da lista */
char *getFillH(Hidrante info);

/*Esta funcao recebe os dados de um hidrante armazenado na lista de hidrantes
e retorna o borda do hidrante armazenado naquela posicao da lista */
char *getStrokeH(Hidrante info);

/*Esta funcao recebe os dados de um hidrante armazenado na lista de hidrantes
e retorna o espessura da borda do hidrante armazenado naquela posicao da lista */
char *getSWH(Hidrante info);

/* esta funcao percorre a lista de hidrantes,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir hidrantes passando
essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeListaH(Lista l,char saida[]);

#endif