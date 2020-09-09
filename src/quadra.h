#ifndef _QUADRA_H_
#define _QUADRA_H_
#include "lista.h"

typedef void* Quadra;

/* esta funcao imprime uma quadra no arquivo svg
ela recebe como parametro os dados da quadra
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeQuadra(char cep[], double x, double y, double w, double h, char fill[], char stroke[], char strokeWidth[], char saida[]);

/* esta funcao aloca espaço na memoria e armazena os dados da quadra
e retorna o elemento criado*/
Quadra quadraLista(char cep[], double x, double y, double w, double h, char v[], char fill[], char strk[], char sw[]);

/* esta funcao retorna o cep de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
char *getCep(Quadra info);

/* esta funcao retorna o x de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
double getXQ(Quadra info);

/* esta funcao retorna o y de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
double getYQ(Quadra info);

/* esta funcao retorna o width de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
double getWQ(Quadra info);

/* esta funcao retorna o height de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
double getHQ(Quadra info);

/* esta funcao retorna o preenchimento de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
char *getFillQ(Quadra info); 

char *getTipoQ(Quadra elemento);

/* esta funcao retorna o borda de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
char *getStrokeQ(Quadra info);

/* esta funcao retorna o espessura da borda de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
char *getSWQ(Quadra info);

/* esta funcao retorna o area de uma quadra
ela recebe o elemento onde a quadra esta
armazenado como parametro */
double getAreaQuadra(Quadra info);

/* esta funcao altera a borda de uma quadra
ela recebe o elemento onde a quadra esta
armazenado e o novo valor borda como parametro*/
void setStokeQ(char cstrk[], Quadra elemento);

/* esta funcao altera a preenchimento de uma quadra
ela recebe o elemento onde a quadra esta
armazenado e o novo valor preenchimento como parametro*/
void setFillQ(char fill[],Quadra elemento);

/* esta funcao altera a tipo de uma quadra para borda arredondada
ela recebe o elemento onde a quadra esta
armazenado e o novo valor preenchimento como parametro*/
void setTipoQ(char v[], Quadra elemento);

/* esta funcao percorre a lista de quadras,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir quadras passando
essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeListaQ(Lista l, char saida[]);

#endif