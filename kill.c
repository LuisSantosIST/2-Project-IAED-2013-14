#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/**
 * @brief: Funcao que apaga todas as mensagens do utilizador pretendido.
 */
void kill(LINK *vec, FILA *filas)
{
	int utilizador;
	char aux;

	getchar();
	getchar();											/*Comandos utilizados para ler 'ill_', dado que*/
	getchar();											/*nao serao necessarios no decorrer do programa.*/
	getchar();

	utilizador = (((int)getchar())-48);					/*transforma o caracter relativo ao utilizador num inteiro.*/
    while ((aux = getchar()) != '\n')					/*ciclo que enquanto nao apanha o \n transforma os caraceteres
                                                        correspontentes ao utilizador num inteiro.*/
        utilizador = utilizador*10 + (((int)aux)-48);	

	while (filas[utilizador].size != 0)					/*Enquanto utilizador pretendido tiver mensagens continuamos*/
	{													/*a apagar as mesmas.*/
		apagaPrimeiroNode(vec, filas, utilizador);
	}
}

/**
 * @brief: Funcao que apaga todas as mensagens de todos os utilizadores e sai do programa.
 */
void quit(LINK *vec, FILA *filas, int nr)
{
	int i;
	for (i = 0; i < nr; i++)							/*Ciclo para percorrer todos os utilizadores.*/
		while (filas[i].size != 0)						/*Enquanto a fila correspondente ao utilizador 'i' nao estiver sem mensagens/nos*/
			apagaPrimeiroNode(vec, filas, i); 			/*continuamos a eliminar as mesmas.*/
}