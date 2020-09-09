#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "resolveQry.h"
#include "lista.h"
#include "cidade.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "formas.h"
#include "radio.h"

typedef struct novas
{
    char tipo, cep[20], sw[10];
    double x, y, w, h, raio;
} structQry;

double getYQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->y;
}

double getXQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->x;
}

double getWQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->w;
}

double getHQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->h;
}

double getRaioQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->raio;
}

char *getCepQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->cep;
}

char getTipoQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->tipo;
}

char *getSWQRY(Info elemento)
{
    structQry *info = (structQry *)elemento;
    return info->sw;
}

void criaCirculo(Lista l, double raio, double x, double y)
{
    structQry *circulo = (structQry *)malloc(sizeof(structQry));

    circulo->x = x;
    circulo->raio = raio;
    circulo->y = y;
    circulo->tipo = 'c';

    insere(l, circulo);
}

void criaLinha(double x, double y, char cep[], Cidade listas)
{
    structQry *linha = (structQry *)malloc(sizeof(structQry));
    Lista l = getListaQRY(listas);

    linha->x = x;
    linha->y = y;
    strcpy(linha->cep, cep);
    linha->tipo = 'l';

    insere(l, linha);
}

void criaRetanguloQry(double x, double y, double w, double h, char sw[], Lista lista)
{
    structQry *quadra = (structQry *)malloc(sizeof(structQry));
    ;

    quadra->x = x;
    quadra->y = y;
    quadra->w = w;
    quadra->h = h;
    strcpy(quadra->sw, sw);
    quadra->tipo = 'q';

    insere(lista, quadra);
}

void crd(Cidade listas, char id[], char txtArq[])
{
    Lista l;
    bool verifica = false;

    FILE *txt;
    txt = fopen(txtArq, "a");

    fprintf(txt, "crd?: %s\n", id);

    l = getListaQuadra(listas);
    No node = getFirst(l), aux = getLast(l);
    Info elemento;

    do
    {
        elemento = getInfo(node);

        if (strcmp(getCep(elemento), id) == 0)
        {
            fprintf(txt, "\tx: %lf y: %lf Quadra\n\n", getXQ(elemento), getYQ(elemento));
            verifica = true;
            break;
        }

        node = getNext(node);
    } while (node != aux);

    if (verifica == false)
    {
        l = getListaHidrante(listas);
        node = getFirst(l);
        aux = getLast(l);

        do
        {
            elemento = getInfo(node);

            if (strcmp(getIdHidrante(elemento), id) == 0)
            {
                fprintf(txt, "\tx: %lf y: %lf Hidrante\n\n", getXH(elemento), getYH(elemento));
                verifica = true;
                break;
            }

            node = getNext(node);
        } while (node != aux);
    }

    if (verifica == false)
    {
        l = getListaSemaforo(listas);
        node = getFirst(l);
        aux = getLast(l);

        do
        {
            elemento = getInfo(node);

            if (strcmp(getIdS(elemento), id) == 0)
            {
                fprintf(txt, "\tx: %lf y: %lf Semaforo\n\n", getXS(elemento), getYS(elemento));
                verifica = true;
                break;
            }

            node = getNext(node);
        } while (node != aux);
    }

    if (verifica == false)
    {
        l = getListaRadio(listas);
        node = getFirst(l);
        aux = getLast(l);

        do
        {
            elemento = getInfo(node);

            if (strcmp(getIdR(elemento), id) == 0)
            {
                fprintf(txt, "\tx: %lf y: %lf Radio Base\n\n", getXR(elemento), getYR(elemento));
                verifica = true;
                break;
            }

            node = getNext(node);
        } while (node != aux);
    }

    if (verifica == false)
    {
        fprintf(txt, "\tCep ou Id nao localizado\n\n");
    }

    fclose(txt);
}

void del(Cidade listas, char id[], char txtarq[])
{
    Lista l;
    bool verifica = false;
    double x, y;

    FILE *txt;
    txt = fopen(txtarq, "a");

    fprintf(txt, "del: %s\n", id);

    l = getListaQuadra(listas);
    No node = getFirst(l), aux = getLast(l);
    Info elemento;

    do
    {
        elemento = getInfo(node);

        if (strcmp(getCep(elemento), id) == 0)
        {
            fprintf(txt, "\tcep: %s x: %lf y: %lf w: %lf h: %lf Fill: %s Stroke: %s SW: %s\n\n", getCep(elemento), getXQ(elemento), getYQ(elemento), getWQ(elemento), getHQ(elemento), getFillQ(elemento), getStrokeQ(elemento), getSWQ(elemento));
            x = getXQ(elemento) + (getWQ(elemento) / 2);
            y = getYQ(elemento) + (getHQ(elemento) / 2);
            criaLinha(x, y, getCep(elemento), listas);
            removeElemento(l, elemento);
            verifica = true;
            break;
        }

        node = getNext(node);
    } while (node != aux);

    if (verifica == false)
    {
        l = getListaHidrante(listas);
        node = getFirst(l);
        aux = getLast(l);

        do
        {
            elemento = getInfo(node);

            if (strcmp(getIdHidrante(elemento), id) == 0)
            {
                fprintf(txt, "\tid: %s x: %lf y: %lf Fill: %s Stoke: %s Sw: %s\n\n", getIdHidrante(elemento), getXH(elemento), getYH(elemento), getFillH(elemento), getStrokeH(elemento), getSWH(elemento));
                removeElemento(l, elemento);
                verifica = true;
                break;
            }

            node = getNext(node);
        } while (node != aux);
    }

    if (verifica == false)
    {
        l = getListaSemaforo(listas);
        node = getFirst(l);
        aux = getLast(l);

        do
        {
            elemento = getInfo(node);

            if (strcmp(getIdS(elemento), id) == 0)
            {
                fprintf(txt, "\tid: %s x: %lf y: %lf Fill : %s Stroke: %s SW: %s\n\n", getIdS(elemento), getXS(elemento), getYS(elemento), getFillS(elemento), getStrokeS(elemento), getSWS(elemento));
                removeElemento(l, elemento);
                verifica = true;
                break;
            }

            node = getNext(node);
        } while (node != aux);
    }

    if (verifica == false)
    {
        l = getListaRadio(listas);
        node = getFirst(l);
        aux = getLast(l);

        do
        {
            elemento = getInfo(node);

            if (strcmp(getIdR(elemento), id) == 0)
            {
                fprintf(txt, "\tid: %s x: %lf y: %lf Fill: %s Stroke: %s SW: %s\n\n", getIdR(elemento), getXR(elemento), getYR(elemento), getFillR(elemento), getStokeR(elemento), getSWR(elemento));
                removeElemento(l, elemento);
                verifica = true;
                break;
            }

            node = getNext(node);
        } while (node != aux);
    }

    if (verifica == false)
    {
        fprintf(txt, "\tCep ou Id nao localizado\n\n");
    }

    fclose(txt);
}

void cbq(Cidade listas, double x, double y, double raio, char cstrk[], char txtarq[])
{
    Lista lista = getListaQuadra(listas);
    No node = getFirst(lista);
    Info elemento;
    double x1, x2, y1, y2;

    FILE *txt;
    txt = fopen(txtarq, "a");
    if (txt == NULL)
    {
        printf("erro ao abrir txt!\n");
        exit(0);
    }

    fprintf(txt, "cbq: %lf %lf %lf %s\n", x, y, raio, cstrk);

    while (node != NULL)
    {
        elemento = getInfo(node);

        x1 = getXQ(elemento);
        x2 = getXQ(elemento) + getWQ(elemento);
        y1 = getYQ(elemento);
        y2 = getYQ(elemento) + getHQ(elemento);

        if (PontoInterno(x1, y1, x, y, raio) == true)
        {
            if (PontoInterno(x1, y2, x, y, raio) == true)
            {
                if (PontoInterno(x2, y1, x, y, raio) == true)
                {
                    if (PontoInterno(x2, y2, x, y, raio) == true)
                    {
                        setStokeQ(cstrk, elemento);
                        fprintf(txt, "\tCEP: %s\n\n", getCep(elemento));
                    }
                }
            }
        }
        node = getNext(node);
    }
    fclose(txt);
}

void dq(Cidade listas, char id[], double r, bool verifica, char txtarq[])
{
    Lista l, listaq = getListaQuadra(listas);
    double x, y, x1, x2, y1, y2;
    bool v = false;

    FILE *txt;
    txt = fopen(txtarq, "a");

    if (verifica == true)
    {
        fprintf(txt, "dq: # %s %lf\n", id, r);
    }
    else
    {
        fprintf(txt, "dq: %s %lf\n", id, r);
    }

    l = getListaHidrante(listas);
    No node = getFirst(l), aux = getFirst(listaq);
    Info elemento, elementoq;

    while (node != NULL)
    {
        elemento = getInfo(node);

        if (strcmp(getIdHidrante(elemento), id) == 0)
        {
            x = getXH(elemento);
            y = getYH(elemento);

            if (verifica == true)
            {
                while (aux != NULL)
                {
                    elementoq = getInfo(aux);

                    x1 = getXQ(elementoq);
                    y1 = getYQ(elementoq);
                    x2 = getXQ(elementoq) + getWQ(elementoq);
                    y2 = getYQ(elementoq) + getHQ(elementoq);

                    if (PontoInterno(x1, y1, x, y, r) == true)
                    {
                        if (PontoInterno(x1, y2, x, y, r) == true)
                        {
                            if (PontoInterno(x2, y1, x, y, r) == true)
                            {
                                if (PontoInterno(x2, y2, x, y, r) == true)
                                {
                                    criaRetanguloQry(getXQ(elementoq), getYQ(elementoq), getWQ(elementoq), getHQ(elementoq), getSWQ(elementoq), getListaQRY(listas));
                                    aux = getNext(aux);
                                    fprintf(txt, "\tCep: %s Id: %s X: %lf Y: %lf Fill: %s Stroke: %s\n\n", getCep(elementoq), getIdHidrante(elemento), getXH(elemento), getYH(elemento), getFillH(elemento), getStrokeH(elemento));
                                    removeElemento(listaq, elementoq);
                                    aux = getPrevious(aux);
                                }
                            }
                        }
                    }
                    aux = getNext(aux);
                }
            }
            else
            {
                while (aux != NULL)
                {
                    elementoq = getInfo(aux);

                    x1 = getXQ(elementoq);
                    y1 = getYQ(elementoq);
                    x2 = getXQ(elementoq) + getWQ(elementoq);
                    y2 = getYQ(elementoq) + getHQ(elementoq);

                    if (PontoInterno(x1, y1, x, y, r) == true)
                    {
                        if (PontoInterno(x1, y2, x, y, r) == true)
                        {
                            if (PontoInterno(x2, y1, x, y, r) == true)
                            {
                                if (PontoInterno(x2, y2, x, y, r) == true)
                                {
                                    aux = getNext(aux);
                                    fprintf(txt, "\tCep: %s Id: %s X: %lf Y: %lf Fill: %s Stroke: %s\n\n", getCep(elementoq), getIdHidrante(elemento), getXH(elemento), getYH(elemento), getFillH(elemento), getStrokeH(elemento));
                                    removeElemento(listaq, elementoq);
                                    aux = getPrevious(aux);
                                }
                            }
                        }
                    }
                    aux = getNext(aux);
                }
            }

            v = true;
            break;
        }

        node = getNext(node);
    }

    if (v == false)
    {
        l = getListaRadio(listas);
        node = getFirst(l);

        while (node != NULL)
        {
            elemento = getInfo(node);

            if (strcmp(getIdR(elemento), id) == 0)
            {
                x = getXR(elemento);
                y = getYR(elemento);

                if (verifica == true)
                {
                    while (aux != NULL)
                    {
                        elementoq = getInfo(aux);

                        x1 = getXQ(elementoq);
                        y1 = getYQ(elementoq);
                        x2 = getXQ(elementoq) + getWQ(elementoq);
                        y2 = getYQ(elementoq) + getHQ(elementoq);

                        if (PontoInterno(x1, y1, x, y, r) == true)
                        {
                            if (PontoInterno(x1, y2, x, y, r) == true)
                            {
                                if (PontoInterno(x2, y1, x, y, r) == true)
                                {
                                    if (PontoInterno(x2, y2, x, y, r) == true)
                                    {
                                        criaRetanguloQry(getXQ(elementoq), getYQ(elementoq), getWQ(elementoq), getHQ(elementoq), getSWQ(elementoq), getListaQRY(listas));
                                        aux = getNext(aux);
                                        fprintf(txt, "\tCep: %s Id: %s X: %lf Y: %lf Fill: %s Stroke: %s\n\n", getCep(elementoq), getIdR(elemento), getXR(elemento), getYR(elemento), getFillR(elemento), getStokeR(elemento));
                                        removeElemento(listaq, elementoq);
                                        aux = getPrevious(aux);
                                    }
                                }
                            }
                        }
                        aux = getNext(aux);
                    }
                }
                else
                {
                    while (aux != NULL)
                    {
                        elementoq = getInfo(aux);

                        x1 = getXQ(elementoq);
                        y1 = getYQ(elementoq);
                        x2 = getXQ(elementoq) + getWQ(elementoq);
                        y2 = getYQ(elementoq) + getHQ(elementoq);

                        if (PontoInterno(x1, y1, x, y, r) == true)
                        {
                            if (PontoInterno(x1, y2, x, y, r) == true)
                            {
                                if (PontoInterno(x2, y1, x, y, r) == true)
                                {
                                    if (PontoInterno(x2, y2, x, y, r) == true)
                                    {
                                        aux = getNext(aux);
                                        fprintf(txt, "\tCep: %s Id: %s X: %lf Y: %lf Fill: %s Stroke: %s\n\n", getCep(elementoq), getIdR(elemento), getXR(elemento), getYR(elemento), getFillR(elemento), getStokeR(elemento));
                                        removeElemento(listaq, elementoq);
                                        aux = getPrevious(aux);
                                    }
                                }
                            }
                        }
                        aux = getNext(aux);
                    }
                }
                v = true;
                break;
            }

            node = getNext(node);
        }
    }
    if (v == false)
    {
        l = getListaSemaforo(listas);
        node = getFirst(l);

        while (node != NULL)
        {
            elemento = getInfo(node);

            if (strcmp(getIdS(elemento), id) == 0)
            {
                x = getXS(elemento);
                y = getYS(elemento);

                if (verifica == true)
                {
                    while (aux != NULL)
                    {
                        elementoq = getInfo(aux);

                        x1 = getXQ(elementoq);
                        y1 = getYQ(elementoq);
                        x2 = getXQ(elementoq) + getWQ(elementoq);
                        y2 = getYQ(elementoq) + getHQ(elementoq);

                        if (PontoInterno(x1, y1, x, y, r) == true)
                        {
                            if (PontoInterno(x1, y2, x, y, r) == true)
                            {
                                if (PontoInterno(x2, y1, x, y, r) == true)
                                {
                                    if (PontoInterno(x2, y2, x, y, r) == true)
                                    {
                                        criaRetanguloQry(getXQ(elementoq), getYQ(elementoq), getWQ(elementoq), getHQ(elementoq), getSWQ(elementoq), getListaQRY(listas));
                                        aux = getNext(aux);
                                        fprintf(txt, "\tCep: %s Id: %s X: %lf Y: %lf Fill: %s Stroke: %s\n\n", getCep(elementoq), getIdS(elemento), getXS(elemento), getYS(elemento), getFillS(elemento), getStrokeS(elemento));
                                        removeElemento(listaq, elementoq);
                                        aux = getPrevious(aux);
                                    }
                                }
                            }
                        }
                        aux = getNext(aux);
                    }
                }
                else
                {
                    while (aux != NULL)
                    {
                        elementoq = getInfo(aux);

                        x1 = getXQ(elementoq);
                        y1 = getYQ(elementoq);
                        x2 = getXQ(elementoq) + getWQ(elementoq);
                        y2 = getYQ(elementoq) + getHQ(elementoq);

                        if (PontoInterno(x1, y1, x, y, r) == true)
                        {
                            if (PontoInterno(x1, y2, x, y, r) == true)
                            {
                                if (PontoInterno(x2, y1, x, y, r) == true)
                                {
                                    if (PontoInterno(x2, y2, x, y, r) == true)
                                    {
                                        aux = getNext(aux);
                                        fprintf(txt, "\tCep: %s Id: %s X: %lf Y: %lf Fill: %s Stroke: %s\n\n", getCep(elementoq), getIdS(elemento), getXS(elemento), getYS(elemento), getFillS(elemento), getStrokeS(elemento));
                                        removeElemento(listaq, elementoq);
                                        aux = getPrevious(aux);
                                    }
                                }
                            }
                        }
                        aux = getNext(aux);
                    }
                }

                v = true;
                break;
            }

            node = getNext(node);
        }
    }

    criaCirculo(getListaQRY(listas), r, x, y);

    fclose(txt);
}

bool PontoInterno(double x1, double y1, double x2, double y2, double raio)
{
    double DX, DY, res;

    DX = x2 - x1;
    DY = y2 - y1;

    res = sqrt((DX * DX) + (DY * DY));

    if (raio >= res)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void imprimeQry(Lista l, char saida[])
{
    No node = getFirst(l);
    Info elemento;
    structQry def;

    while (node != NULL)
    {
        elemento = getInfo(node);
        def.tipo = getTipoQRY(elemento);

        if (def.tipo == 'l')
        {
            def.x = getXQRY(elemento);
            def.y = getYQRY(elemento);
            strcpy(def.cep, getCepQRY(elemento));
            imprimeLinha(def.x, def.y, def.cep, saida);
        }
        if (def.tipo == 'c')
        {
            def.x = getXQRY(elemento);
            def.y = getYQRY(elemento);
            def.raio = getRaioQRY(elemento);
            imprimeCirculoQry(def.x, def.y, def.raio, saida);
        }
        if (def.tipo == 'q')
        {
            def.x = getXQRY(elemento);
            def.y = getYQRY(elemento);
            def.h = getHQRY(elemento);
            def.w = getWQRY(elemento);
            strcpy(def.sw, getSWQRY(elemento));
            imprimeQuadraQRY(def.x, def.y, def.w, def.h, def.sw, saida);
        }
        if (def.tipo == 'n')
        {
            def.x = getXQRY(elemento);
            def.y = getYQRY(elemento);
            def.h = getHQRY(elemento);
            def.w = getWQRY(elemento);
            strcpy(def.sw, getSWQRY(elemento));
            imprimeRetT(def.x, def.y, def.w, def.h, def.sw, saida);
        }
        if (def.tipo == 's')
        {
            def.x = getXQRY(elemento);
            def.y = getYQRY(elemento);
            def.h = getHQRY(elemento);
            def.w = getWQRY(elemento);
            strcpy(def.sw, getSWQRY(elemento));
            imprimeRet(def.x, def.y, def.w, def.h, def.sw, saida);
        }

        node = getNext(node);
    }
}

void imprimeLinha(double x, double y, char cep[], char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"0\" stroke=\"black\" stroke-width=\"2\"/>\n", x, y, x);
    x = x + 2;
    fprintf(arq, "\t<text x=\"%lf\" y=\"10\">%s</text>", x, cep);

    fclose(arq);
}

void imprimeCirculoQry(double x, double y, double raio, char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"none\" stroke=\"black\" stroke-width=\"1.0px\"/>", x, y, raio);

    fclose(arq);
}

void imprimeRetT(double x, double y, double w, double h, char sw[], char saida[]){
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"nonde\" stroke=\"black\" stroke-width=\"%s\" stroke-dasharray=\"5\"/>", x, y, w, h, sw);

    fclose(arq);
}

void imprimeRet(double x, double y, double w, double h, char sw[], char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-width=\"%s\" />", x, y, w, h, sw);

    fclose(arq);
}

void imprimeQuadraQRY(double x, double y, double w, double h, char sw[], char saida[])
{
    FILE *arq;
    arq = fopen(saida, "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir SVG!");
        exit(1);
    }

    fprintf(arq, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"beige\" stroke=\"olive\" stroke-width=\"%s\" rx=\"20\"/>", x, y, w, h, sw);

    fclose(arq);
}

/* --------------------- QRY FORMAS -------------- */

double max(x1, x2){
    if (x1 > x2){ return x1; }
    else{ return x2; }
}

double min(x1, x2){
    if (x1 < x2){return x1;  }
    else{ return x2; }
}

double dist(double x1, double y1, double x2, double y2){
    double deltax, deltay, res;
    deltay = y2 - y1;
    deltax = x2 - x1;
    res = sqrt((deltax * deltax) + (deltay * deltay));
    return res;
}

void criaRetFormasQry(double x, double y, double w, double h, char sw[], Lista lista, char forma){
    structQry *quadra = (structQry *)malloc(sizeof(structQry));
    quadra->x = x;
    quadra->y = y;
    quadra->w = w;
    quadra->h = h;
    strcpy(quadra->sw, sw);
    quadra->tipo = forma;
    insere(lista, quadra);
}

bool sobreposicaoCirc(double x1, double y1, double r1, double x2, double y2, double r2, Lista lista){
    double x, y, largura, altura;

    x = min(x1, x2) - max(r1, r2);
    y = min(y1, y2) - max(r1, r2);
    largura = max(x1, x2) - min(x1, x2) + r1 + r2;
    altura = max(y1, y2) - min(y1, y2) + r1 + r2;

    if (dist(x1, y1, x2, y2) <= r1 + r2)
    {
        criaRetFormasQry(x, y, largura, altura, "1.0px", lista, 's');
        return true;
    }
    else
    {
        criaRetFormasQry(x, y, largura, altura, "1.0px", lista, 'n');
        return false;
    }
}

bool sobreposicaoCircRet(double cx, double cy, double rx, double ry, double raio, double w, double h, Lista lista){
    double x, y, largura, altura;

    x = min(rx, cx - raio);
    y = min(ry, cy - raio);
    largura = max(rx + w, cx + raio) - min(rx, cx - raio);
    altura = max(ry + h, cy + raio) - min(ry, cy - raio);

    if (dist(cx, max(rx, min(cx, rx + w)), cy, max(cy, min(cy, ry + h))) < raio)
    {
        criaRetFormasQry(x, y, largura, altura, "1.0px", lista, 's');
        return true;
    }
    else
    {
        criaRetFormasQry(x, y, largura, altura, "1.0px", lista, 'n');
        return false;
    }
}

bool sobreposicaoRet(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2, Lista lista){

    double x, y, largura, altura;

    x = min(x1, x2);
    y = min(y1, y2);
    altura = max(h1 + y1, h2 + y2) - y;
    largura = max(w1 + x1, h2 + x2) - x;

    if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2){
        criaRetFormasQry(x, y, largura, altura, "1.0px", lista, 's');
        return true;
    }
    else {
        criaRetFormasQry(x, y, largura, altura, "1.0px", lista, 'n');
        return false;
    }
}

void oFormas(int j, int k, Lista lista, char txt[]){
    No *aux = getFirst(lista), *aux2 = getFirst(lista);
    Info elemento1, elemento2;
    double x1, x2, y1, y2, r1, r2, w1, w2, h1, h2;

    FILE *fp;
    fp = fopen(txt, "a");
    if (txt == NULL)
    {
        printf("erro ao abrir txt!");
        exit(0);
    }

    fprintf(txt, "o?\n");

    while (aux != NULL){
        elemento1 = getInfo(aux);

        if (getIdF(elemento1) == j){

            while (aux2 != NULL){
                elemento2 = getInfo(aux);
                if (k == getIdF(elemento2)){
                    if (getForma(elemento1) == 'c' && getForma(elemento2) == 'c'){
                        x1 = getXF(elemento1);
                        x2 = getXF(elemento2);
                        y1 = getYF(elemento1);
                        y2 = getYF(elemento2);
                        r1 = getRaioF(elemento1);
                        r2 = getRaioF(elemento2);

                        if (sobreposicaoCirc(x1, y1, r1, x2, y2, r2, lista) == true){
                            fprintf(txt, "\tcirculo circulo Sobrepõe\n\n");
                        }
                        else{
                            fprintf(txt, "\tcirculo circulo Não Sobrepõe\n\n");
                        }
                    }
                    if (getForma(elemento1) == 'r' && getForma(elemento2) == 'c')
                    {
                        x1 = getXF(elemento1);
                        x2 = getXF(elemento2);
                        y1 = getYF(elemento1);
                        y2 = getYF(elemento2);
                        w1 = getRaioF(elemento1);
                        r2 = getRaioF(elemento2);
                        h1 = getHF(elemento1);

                        if (sobreposicaoCircRet(x2, y2, x1, y1, r2, w1, h1, lista) == true)
                        {
                            fprintf(txt, "\tretangulo circulo Sobrepõe\n\n");
                        }
                        else
                        {
                            fprintf(txt, "\tretangulo circulo Não Sobrepõe\n\n");
                        }
                    }
                    if (getForma(elemento1) == 'c' && getForma(elemento2) == 'r')
                    {
                        x1 = getXF(elemento2);
                        x2 = getXF(elemento1);
                        y1 = getYF(elemento2);
                        y2 = getYF(elemento1);
                        w1 = getRaioF(elemento2);
                        r2 = getRaioF(elemento1);
                        h1 = getHF(elemento2);

                        if (sobreposicaoCircRet(x2, y2, x1, y1, r2, w1, h1, lista) == true)
                        {
                            fprintf(txt, "\tcirculo  retanguloSobrepõe\n\n");
                        }
                        else
                        {
                            fprintf(txt, "\tcirculo retanguloNão Sobrepõe\n\n");
                        }
                    }
                    if (getForma(elemento1) == 'r' && getForma(elemento2) == 'r'){
                        x1 = getXF(elemento1);  x2 = getXF(elemento2);
                        y1 = getYF(elemento1);  y2 = getYF(elemento2);
                        w1 = getWF(elemento1);  w2 = getWF(elemento2);
                        h1 = getHF(elemento1);  h2 = getHF(elemento2);

                        if (sobreposicaoRet(x1, y1, w1, h1, x2, y2, w2, h2, lista)==true){
                            fprintf(txt, "\tretangulo retangulo Sobrepõe\n\n");
                        }
                        else{
                                fprintf(txt, "\tretangulo retangulo Não Sobrepõe\n\n"); }
                        
                    }
                }
                aux2 = getNext(aux2);
            }
        }

        aux = getNext(aux);
    }
    fclose(fp);
}