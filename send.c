#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/**
*@brief: Funcao para colocar os ponteiros contidos no vector 'vec' a apontar inicialmente para NULL, assim como inicializar
*        o tamanho das estruturas FILA a 0 e a head e tail a apontar para NULL.
*/
void inicializa(LINK *vec, FILA *filas, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
    	vec[i] = NULL;
    	filas[i].size = 0;
    	filas[i].head = vec[i];
    	filas[i].tail = vec[i];
    }
}

/**
*@brief: Cria uma nova mensagem e acrescenta essa mensagem na posicao final do vector de utilizadores.
*/
void send(LINK *vec, FILA *filas)
{
    int e, r;
    TEXTO string;
    SMS msg;
    LINK node;
    char aux;

    getchar();
    getchar();								/*4 comandos para ler 'end_', dados que nao seram*/
    getchar();								/*necessarios na continuidade do programa.*/
    getchar();

    e = (((int)getchar())-48);				/*transforma o caracter relativo ao utilizador num inteiro.*/
    while ((aux = getchar()) != ' ')		/*ciclo que enquanto nao apanha o \n transforma os caraceteres
                                            correspontentes ao utilizador num inteiro.*/
        e = e*10 + (((int)aux) - 48);	

    r = (((int)getchar())-48);				/*transforma o caracter relativo ao utilizador num inteiro.*/
    while ((aux = getchar()) != ' ')		/*ciclo que enquanto nao apanha o \n transforma os caraceteres
                                            correspontentes ao utilizador num inteiro.*/
        r = r*10 + (((int)aux) - 48);		

    string = recebeTexto();					/*Le o texto correspondente a mensagem.*/
    msg = criaMensagem(e, r, string);		/*Cria um ponteiro para uma estrutura MENSAGEM, que comtem o 
    										emissor, o receptor .*/
    node = criaNode(msg);
    acrecentaNode(vec, filas, r, node);	
}