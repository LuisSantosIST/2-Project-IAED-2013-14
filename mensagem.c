#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/**
*@brief: Funcao para receber texto e devolve um ponteiro para esse texto.
*/
TEXTO recebeTexto()
{
	char msg[TAMANHO_MAX], c;
	int i = 0, count = 0;
	TEXTO txt;

	while (((c = getchar()) != '\n') && (i < TAMANHO_MAX))  /*ciclo para guardar os caracteres todos que apanha num vector com tamanho
	                                                        maximo de 500 caracteres mais o \0, parando apenas no \n.*/
	{
		msg[i] = c;
		i++; 
	}
	msg[i] = '\0';                                          /*colocacao do \0 no final.*/

	
	txt = (TEXTO) malloc(sizeof(char)*(strlen(msg)+1));     /*criacao de um ponteiro com espaco reservado apenas para o numero de 
	                                                         caracteres lidos.*/

	while (msg[count] != '\0')                              /*ciclo para guardar os caracteres do vector de caracteres(string) na 
	                                                        memoria apontada pelo txt.*/
	{
		txt[count] = msg[count];
		count++;
	}
	txt[count] = msg[count];
	return txt;
}

/**
* @brief: Funcao que recebe um ponteiro do tipo TEXTO e imprime os caracteres apontados por este.
*/
void imprimeTexto(TEXTO txt)
{
	int N = strlen(txt), i;
	for (i = 0; i < N; i++)
		printf("%c", txt[i]);
	puts("");
}

/**
 *@brief: Funcao que recebe dois inteiros e um ponteiro do tipo TEXTO e devolve um ponteiro do tipo SMS (ou seja para uma mensagem).
*/
SMS criaMensagem(int e, int r, TEXTO txt)
{
	SMS msg = (SMS) malloc(sizeof(struct MENSAGEM)); /*reserva de memoria para uma estrutura mensagem apontada pelo ponteiro msg.*/
	msg -> emissor = e;
	msg -> receptor = r;
	msg -> string = txt;
	return msg;
}

/**
*@brief: Funcao que recebe um ponteiro para uma mensagem e imprime os valores relativos ao receptor e emissor, assim como o texto apontado
*        por esta.
*/
void imprimeMensagem(SMS msg)
{
	printf("%d %d ", msg->receptor, msg->emissor);
	imprimeTexto(msg->string);
}

/**
*@brief: Funcao que recebe um apontador para a estrutura mensagem e liberta a memoria alocada para esta mensagem.
*/
void deleteMensagem(SMS msg)
{
	free(msg->string);
	free(msg);
}