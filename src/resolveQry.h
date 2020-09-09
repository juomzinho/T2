#ifndef _RESOLVEQRY_H_
#define _RESOLVEQRY_H_
#include "cidade.h"

/* esta funcao aloca memoria e armazena os dados de um circulo
ela recebe dos dados do circulo e a lista por parametro 
no fim ela insere o circulo na lista*/
void criaCirculo(Lista l, double raio, double x, double y);

/* esta funcao aloca memoria e armazena os dados de uma linha
ela recebe dos dados da linha e a lista por parametro 
no fim ela insere a linha na lista*/
void criaLinha(double x, double y, char cep[], Cidade listas);

/* esta funcao aloca memoria e armazena os dados de um retangulo
ela recebe dos dados do retangulo e a lista por parametro 
no fim ela insere o retangulo na lista*/
void criaRetanguloQry(double x, double y, double w, double h, char sw[], Lista lista);

/* esta funcao aloca memoria e armazena os dados de um retangulo com a borda tracejada ou linha cheia
ela recebe dos dados do retangulo e a lista por parametro 
no fim ela insere o retangulo na lista*/
void criaRetFormasQry(double x, double y, double w, double h, char sw[], Lista lista, char forma);

/* esta funcao resolve o comando car
ela recebe como parametro a lista que contem as listas, os dados lidos do comando car
e o nome arquivo do txt junto ao seu diretório*/
void car(Cidade listas, double x, double y, double w, double h, char txtArq[]);

/* esta funcao resolve o comando crd
ela recebe como parametro a lista que contem as listas, os dados lidos do comando crd
e o nome arquivo do txt junto ao seu diretório*/
void crd(Cidade listas, char id[], char txtArq[]);

/* esta funcao resolve o comando cbq
ela recebe como parametro a lista que contem as listas, os dados lidos do comando cbq
e o nome arquivo do txt junto ao seu diretório*/
void cbq(Cidade listas, double x, double y, double raio, char cstrk[], char txtarq[]);

/* esta funcao resolve o comando del
ela recebe como parametro a lista que contem as listas, os dados lidos do comando del
e o nome arquivo do txt junto ao seu diretório*/
void del(Cidade listas, char id[], char txtarq[]);

/* esta funcao resolve o comando dq
ela recebe como parametro a lista que contem as listas, os dados lidos do comando dq
e o nome arquivo do txt junto ao seu diretório*/
void dq(Cidade listas, char id[], double r, bool verifica, char txtarq[]);

/* esta funcao retorna o maior valor, recebido
ele rebece dois valores double por paremetro*/
double max(double x1, double x2);

/* esta funcao retorna o menor valor, recebido
ele rebece dois valores double por paremetro*/
double min(double x1, double x2);

/* esta funcao retorna a distancia entre dois pontos,
ele rebece os dados dos pontos por paremetro*/
double dist(double x1, double y1, double x2, double y2);

/* esta funcao retorna se um ponto é ou nao interno de um circulo,
ele rebece os dados do ponto e do circulo por paremetro*/
bool PontoInterno(double x1, double y1, double x2, double y2, double raio);

/* esta funcao retorna se um ponto é ou nao interno de um retangulo,
ele rebece os dados do ponto e do retangulo por paremetro*/
bool PontoInternoRet(double px, double py, double x, double y, double h, double w);

/* esta funcao percorre a lista de qrys,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir o respectivo elemento passando
essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeQry(Lista l, char saida[]);

/* esta funcao imprime uma linha e o cep no arquivo svg
ela recebe como parametro os dados do linha e o cep
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeLinha(double x, double y, char cep[], char saida[]);

/* esta funcao imprime uma linha e a area no arquivo svg
ela recebe como parametro os dados do linha e a area
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeLinhaD(double x, double y, double area, char saida[]);

/* esta funcao imprime um circulo no arquivo svg
ela recebe como parametro os dados do circulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeCirculoQry(double x, double y, double raio, char saida[]);

/* esta funcao imprime uma quadra com as bordas arredondadas no arquivo svg
ela recebe como parametro os dados do quadra
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeQuadraQRY(double x, double y, double w, double h, char sw[], char saida[]);

/* esta funcao imprime uma retangulo com as borda tracejada no arquivo svg
ela recebe como parametro os dados do retangulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeRetT(double x, double y, double w, double h, char sw[], char saida[]);


/* esta funcao imprime uma retangulo com as borda cheia no arquivo svg
ela recebe como parametro os dados do retangulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeRet(double x, double y, double w, double h, char sw[], char saida[]);

/* esta funcao resolve o comando o?
ela recebe como parametro a lista, os dados lidos do comando o?
e o nome arquivo do txt junto ao seu diretório*/
void oFormas(int j, int k, Lista lista, char txt[]);

/* esta funcao resolve o comando i?
ela recebe como parametro a lista, os dados lidos do comando i?
e o nome arquivo do txt junto ao seu diretório*/
void iFormas(int j, double x, double y, Lista lista, char txt[]);

/* esta funcao resolve o comando pnt
ela recebe como parametro a lista, os dados lidos do comando pnt
e o nome arquivo do txt junto ao seu diretório*/
void pnt(int j, char stroke[], char fill[], Lista lista, char txt[]);

/* esta funcao resolve o comando pnt*
ela recebe como parametro a lista, os dados lidos do comando pnt*
e o nome arquivo do txt junto ao seu diretório*/
void pntplus(int j, int k, char stroke[], char fill[], Lista lista, char txt[]);

/* esta funcao resolve o comando delf
ela recebe como parametro a lista, os dados lidos do comando delf
e o nome arquivo do txt junto ao seu diretório*/
void delf(int j, Lista lista, char txt[]);

/* esta funcao resolve o comando delf*
ela recebe como parametro a lista, os dados lidos do comando delf*
e o nome arquivo do txt junto ao seu diretório*/
void delfplus(int j, int k, Lista lista, char txt[]);

#endif