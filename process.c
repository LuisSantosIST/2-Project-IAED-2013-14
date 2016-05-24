#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
*@brief: Funcao que imprime a proxima mensagem do utilizador pretendido e apaga essa mesma mensagem.
*/
void process(LINK *vec, FILA *filas)
{
	int utilizador;
	char aux;

	getchar();
	getchar();
	getchar();												/*Comandos utilizados para ler 'rocess_', dado*/
	getchar();												/*nao seram necessarios no decorrer do programa.*/
	getchar();
	getchar();
	getchar();

	utilizador = (((int)getchar())-48);						/*transforma o caracter relativo ao utilizador num inteiro.*/
    while ((aux = getchar()) != '\n')						/*ciclo que enquanto nao apanha o \n transforma os caraceteres
                                                            correspontentes ao utilizador num inteiro.*/
        utilizador = utilizador*10 + (((int)aux)-48);		

    if (filas[utilizador].size == 0)						/*Se nao houver mensagens para o utilizador pretendido, returna NULL.*/
    {
        puts("NULL");
        return;
    } 

    imprimeMensagem(filas[utilizador].head -> mensagem);	/*Imprime a primeira mensagem do utilizador pretendido.*/
    apagaPrimeiroNode(vec, filas, utilizador);				/*Apaga essa mesma mensagem.*/
}