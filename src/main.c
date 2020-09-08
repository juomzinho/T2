#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "readqry.h"
#include "readgeo.h"
#include "lista.h"
#include "cidade.h"

char *tratamento(char arqNome[]){
    int i,x,y;
    char *prefixo, caractere;

    for(i=strlen(arqNome);i>=0;i--) {
		caractere = arqNome[i];
        if(caractere=='/') {
        	y = strlen(arqNome)-i;
        	prefixo = (char*) malloc(y*sizeof(char));
            
        	for(x=0;x<=y;x++){
            	prefixo[x] = arqNome[i+1];
            	i++; 
        	}  
			return strtok(prefixo,".");
        }        
    }
	return strtok(arqNome,".");
}

int main(int argc, char *argv[]){
    char *nomeArq = NULL;
    char *path = NULL;
    char *qry = NULL;
    char *saida = NULL;
    char *geo = NULL;
    char *pgeo = NULL;
    char *pqry = NULL;
    char *parq = NULL;
    char *arqSvg = NULL;
    char *arqTxt = NULL;
    char *arqqry = NULL;

    Cidade cidade = iniciaCidade();

    for(int i = 1; i<argc;i++){
        if (strcmp("-f",argv[i])==0){
            i++;
            if(argv[i]==NULL){
                printf("-f nao recebeu parametros!!\n");
                exit(1);
            }
            nomeArq = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(nomeArq,argv[i]);
        }
        if (strcmp("-o",argv[i])==0){
            i++;
            if(argv[i]==NULL){
                printf("-o nao recebeu parametros!!\n");
                exit(1);
            }
            saida = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(saida,argv[i]);
        }
        if (strcmp("-q",argv[i])==0){
            i++;
            if(argv[i]==NULL){
                printf("-q nao recebeu parametros!!\n");
                exit(1);
            }
            qry = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(qry,argv[i]);
        }
        if (strcmp("-e",argv[i])==0){
            i++;
            if(argv[i]==NULL){
                printf("-e nao recebeu parametros!!\n");
                exit(1);
            }
            path = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(path,argv[i]);
        }
    }

    if(path!=NULL){
        geo = (char *)malloc((strlen(nomeArq)+strlen(path)+2)*sizeof(char));
        sprintf(geo,"%s/%s",path,nomeArq);

        if (qry!=NULL){       
            arqqry = (char *)malloc((strlen(qry)+strlen(path)+2)*sizeof(char));
            sprintf(arqqry,"%s%s",path,qry);
        }
    }
    else{
        geo = (char *)malloc((strlen(nomeArq)+1)*sizeof(char));
        strcpy(geo,nomeArq);

        if (qry!=NULL){        
            arqqry = (char *)malloc((strlen(qry)+1)*sizeof(char));
            strcpy(arqqry,qry);
        }
    }
    
    pgeo = tratamento(nomeArq);

    if (qry != NULL){ pqry = tratamento(qry); }

    arqSvg = (char *) malloc((strlen(saida)+strlen(pgeo)+6)*sizeof(char));
    sprintf(arqSvg,"%s/%s.svg",saida,pgeo);

    leituraGeo(geo,arqSvg,cidade);
    
    if (arqqry!=NULL){

        parq = (char *) malloc((strlen(arqSvg)+strlen(pqry)+6)*sizeof(char));
        sprintf(parq,"%s/%s-%s.svg", saida, pgeo, pqry);

        arqTxt = (char *) malloc((strlen(arqSvg)+strlen(pqry)+6)*sizeof(char));
        sprintf(arqTxt,"%s/%s-%s.txt", saida, pgeo, pqry);

        leituraQRY(parq, arqTxt, arqqry,cidade); 
    }

    removeListas(cidade);
    free(parq);
    free(arqTxt);
    free(arqSvg);
    if(qry != NULL){ free(pqry); }    
    free(pgeo);
    if (arqqry!=NULL){ free(arqqry); }    
    free(geo);
    free(path);
    if (qry!=NULL){ free(qry); }   
    free(saida);
}