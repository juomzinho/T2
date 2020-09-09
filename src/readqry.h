#ifndef _READQRY_H_
#define _READQRY_H_
#include "cidade.h"

/* esta função lê as informações contidas no arquivo qry, e chama uma função
responsável por resolver o comando lido.
ela recebe por parâmetro o nome do arquivo svg junto ao diretório de saida do svg
e do txt, recebe tambem o nome do arquivo qry junto a seu diretório, e recebe tambem
as listas*/
void leituraQRY(char saida[],char arquivotxt[], char qry[], Cidade cidade);

#endif