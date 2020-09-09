#ifndef _SVG_H_
#define _SVG_H_

/* esta funcao cria um arquivo Svg
e imprime no arquivo o comando para
inicializar o arquivo svg
ela recebe como parametro o local de
o nome do arquivo e o local onde ele
sera colocado */
void abrirSvg(char saida[]);

/* esta funcao encerra um arquivo Svg
e imprime no arquivo o comando para
finalizar o arquivo svg
ela recebe como parametro o local de
o nome do arquivo e o local onde ele
sera colocado */
void fecharSvg(char saida[]);

#endif