#ifndef _HIDRANTE_H_
#define _HIDRANTE_H_

typedef void* Hidrante;

/*Esta funcao imprime um hidrante no arquivo svg */
void imprimeHidrante(char id[], double x, double y, char fill[], char stroke[], char strokeWidth[], char saida[]);

Hidrante hidranteLista(char id[], double x, double y, char fill[], char stroke[], char sw[]);

char *getIdHidrante(Hidrante info);


#endif