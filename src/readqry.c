#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Default{
    double x, y, w, h, r;
    char cstrk[20], cep[20], id[20], verifica[20];
};

void leituraQRY(char saida[], char qry[]){
    char comando[5];
    struct Default def;
    char txtarq[100];

    sprintf(txtarq,"%s.txt",saida);

    /* Abertura arquivo qry */

    FILE *arq;
    arq = fopen(qry,"r");
    if(arq==NULL){
        printf("Erro ao abrir qry!!");
        exit(1);
    }

    /* Abertura arquivo txt */

    FILE *txt;
    txt = fopen(txtarq,"w");
    if (txt==NULL){
        printf("Erro ao abrir arquivo .txt");
        exit(1);
    }
    

    while (!feof(arq)){
        fscanf(arq,"%s",comando);
        printf("\n%s: ", comando);

        /* QRY CEP E EQUIPAMENTOS URBANOS */

        if(strcmp("car",comando)==0){
            fscanf(arq,"%lf %lf %lf %lf",&def.x, &def.y, &def.w, &def.h);
            fprintf(txt,"%s: %lf %lf %lf %lf\n", comando,def.x, def.y, def.w, def.h);
        }

        if(strcmp("crd?",comando)==0){
            fscanf(arq,"%s",def.id);
            fprintf(txt,"%s: %s\n", comando,def.id);
        }

        if(strcmp("cbq",comando)==0){
            fscanf(arq,"%lf %lf %lf %s", &def.x, &def.y, &def.r, def.cstrk);
            fprintf(txt,"%s: %lf %lf %lf %s\n",comando, def.x, def.y, def.r, def.cstrk);
        }

        if(strcmp("del",comando)==0){
            fscanf(arq,"%s",def.id);
            fprintf(txt,"%s: %s", comando,def.id);
        }

        if(strcmp("dq",comando)==0){
            fscanf(arq,"%s",def.verifica);
            if(strcmp("#",def.verifica)==0){
                fscanf(arq,"%s %lf",def.id, &def.r);
                fprintf("%s: %s %s %lf", comando, def.verifica, def.id, def.r);
            }
            else{
                fscanf(arq,"%lf",&def.r);
                fprintf(txt,"%s: %s %lf", comando, def.verifica, def.r);
            }
        }

        /* QRY FORMAS */

    }

    fclose(arq);
}