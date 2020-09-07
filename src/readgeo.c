#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"
#include "quadra.h"
#include "semaforo.h"
#include "radio.h"
#include "hidrante.h"
#include "formas.h"
#include "cidade.h"
#include "lista.h"

struct NMAX{
    int i, nq, nh, ns, nr;
};

struct Default{
    char cep[20], id[20];
    double x, y, w, h, r;
};

struct corDef{
    char sw[10], cfill[20], cstrk[20];
};

struct  SW{
    double cw, rw;
};

typedef struct cid{
    Lista listaQ;
    Lista listaS;
    Lista listaH;
    Lista listaRB;
    Lista listaF;
} CidadeStruct;typedef struct quadra{
    char cep[20], fill[10], stroke[10], strokeWidth[10];
    double x, y, w, h;
} QStuct;


/*FORMAS*/
struct formas{
    int id;
    double raio, x, y, w, h;
    char corb[20], corp[20], text[50];
};

void leituraGeo(char geo[],char saida[], Cidade cidade){
    struct NMAX nx, cont;
    char comando[3];
    struct Default def;
    struct corDef ch, cs, cq, cr;
    struct SW sw;
    struct formas forma;
    size_t len = 32;
    char *texto;
    CidadeStruct *listas = (CidadeStruct*) cidade;
    Hidrante hidrante;
    Quadra quadra;
    Semaforo semaforo;
    Radio radio;
    Formas crt;

    nx.i = 1000;
    nx.nh = 1000;
    nx.nq = 1000;
    nx.nr = 1000;
    nx.ns = 1000;

    texto = malloc(len);

    FILE *arq;
    arq = fopen(geo,"r");
    if (arq == NULL){
        printf("Erro ao abrir arquivo geo!!\n");
        exit(0);
    } 

    fscanf(arq,"%s",comando);
    if (strcmp(comando,"nx")==0){
        fscanf(arq,"%d",&nx.i);
        fscanf(arq,"%d",&nx.nq);
        fscanf(arq,"%d",&nx.nh);
        fscanf(arq,"%d",&nx.ns);
        fscanf(arq,"%d",&nx.nr);
    }
    else{
        fseek(arq, 0, SEEK_SET);
    }

    cont.i = 0;
    cont.nh = 0;
    cont.nq = 0;
    cont.nr = 0;
    cont.ns = 0;

    abrirSvg(saida);

    while (!feof(arq)){
        fscanf(arq,"%s",comando);

            if(strcmp("sw",comando)==0){
                fscanf(arq,"%lf %lf", &sw.cw, &sw.rw);
            }

            /* DEFINIÇÃO DAS CORES */
            if(strcmp("cq",comando)==0){
                fscanf(arq,"%s %s %s",cq.sw,cq.cfill,cq.cstrk);
            }
            if(strcmp("cs",comando)==0){
                fscanf(arq,"%s %s %s",cs.sw,cs.cfill,cs.cstrk);
            }
            if(strcmp("ch",comando)==0){
                fscanf(arq,"%s %s %s",ch.sw,ch.cfill,ch.cstrk);
            }
            if(strcmp("cr",comando)==0){
                fscanf(arq,"%s %s %s",cr.sw,cr.cfill,cr.cstrk);
            }
            if(strcmp("q",comando)==0){
                if (cont.nq<nx.nq){
                    fscanf(arq,"%s %lf %lf %lf %lf",def.cep, &def.x, &def.y, &def.w, &def.h);
                    imprimeQuadra(def.cep, def.x, def.y, def.w, def.h, cq.cfill, cq.cstrk, cq.sw, saida);
                    quadra = quadraLista(def.cep, def.x, def.y, def.w, def.h, cq.cfill, cq.cstrk, cq.sw);
                    insere(listas->listaQ,quadra);
                    cont.nq++;
                }
            }
            if(strcmp("h",comando)==0){
                if(cont.nh<nx.nh){
                    fscanf(arq,"%s %lf %lf", def.id, &def.x, &def.y);
                    imprimeHidrante(def.x, def.y, ch.cfill, ch.cstrk, ch.sw, saida);
                    hidrante = hidranteLista( def.id, def.x, def.y, ch.cfill, ch.cstrk, ch.sw);
                    insere(listas->listaH,hidrante);
                    cont.nh++;
                }
            }
            if(strcmp("s",comando)==0){
                if(cont.ns<nx.ns){
                    fscanf(arq,"%s %lf %lf", def.id, &def.x, &def.y);
                    imprimeSemaforo( def.x, def.y, cs.cfill, cs.cstrk, cs.sw, saida);
                    semaforo = semaforoLista(def.id, def.x, def.y, cs.cfill, cs.cstrk, cs.sw);
                    insere(listas->listaS,semaforo);
                    cont.ns++;
                }
            }
            if(strcmp("rb",comando)==0){
                if(cont.nr<nx.nr){
                    fscanf(arq,"%s %lf %lf", def.id, &def.x, &def.y);
                    imprimeRadio(def.x, def.y, cr.cfill, cr.cstrk, cr.sw, saida);
                    radio = radioLista(def.id, def.x, def.y, cr.cfill, cr.cstrk, cr.sw);
                    insere(listas->listaRB,radio);
                    cont.nr++;
                }
            }

            /* ADICONANDO FORMAS */
            if(strcmp("c",comando)==0){
                if(cont.i<nx.i){
                    fscanf(arq,"%d %lf %lf %lf %s %s",&forma.id, &forma.raio, &forma.x, &forma.y, forma.corb, forma.corp); 
                    imprimeCirculo(forma.raio, forma.x, forma.y, forma.corb, forma.corp, saida);
                    crt = circuloLista(forma.id, forma.raio, forma.x, forma.y, forma.corb, forma.corp);
                    insere(listas->listaF,crt);
                    cont.i++;
                }
            }
            if(strcmp("r",comando)==0){
                if(cont.i<nx.i){
                    fscanf(arq,"%d %lf %lf %lf %lf %s %s",&forma.id, &forma.w, &forma.h, &forma.x, &forma.y, forma.corb, forma.corp);
                    imprimeRetangulo(forma.w, forma.h, forma.x, forma.y, forma.corb, forma.corp, saida);
                    crt = retanguloLista(forma.id, forma.w, forma.h, forma.x, forma.y, forma.corb, forma.corp);
                    insere(listas->listaF,crt);
                    cont.i++;
                }
            }
            if(strcmp("t",comando)==0){
                if(cont.i<nx.i){
                    fscanf(arq,"%d %lf %lf %s %s",&forma.id, &forma.x, &forma.y, forma.corb, forma.corp);
                    getline(&texto,&len,arq);
                    imprimeTexto(forma.x, forma.y, forma.corb, forma.corp, forma.text, saida);
                    crt = textoLista(forma.id, forma.x, forma.y, forma.corb, forma.corp, forma.text);
                    insere(listas->listaF,crt);
                    cont.i++;
                }
            }
            
    }
    
        
    fecharSvg(saida);
    free(texto);
}