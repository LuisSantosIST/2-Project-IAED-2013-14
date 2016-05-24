#include <stdio.h>
#include <stdlib.h>
#include "header.h"



/**
*@brief: Funcao que devolve um novo ponteiro para uma estrutura NODE.
*/
LINK criaNode(SMS msg) 
{
    LINK new_node = (LINK) malloc(sizeof(struct NODE)); /*Reserva espaco para um novo node apontado pelo ponteiro new_node.*/
    new_node -> mensagem = msg;                         /*Coloca o ponteiro do tipo SMS (do novo node) a apontar para a mensagem.*/
    new_node -> next = NULL;                            /*Coloca o ponteiro next (do novo node) a apontar para NULL pois este 
                                                        sera acrescentado no final da fila de nodes.*/
    return new_node;
}

/**
* @brief: Funcao que liga uma estrutura do tipo NODE as ja existentes, ou no caso de nao existirem estruturas na fila vai introduzir 
*         esta em primeiro lugar. Tambem e feita a actualizacao do vector que contem as estruturas FILA correspondente a cada utilizador.
*/
void acrecentaNode(LINK *vec, FILA *filas, int receptor, LINK new)
{
    if (vec[receptor] == NULL)                          /*Se o primeiro ponteiro estiver 'vazio' iremos mete-lo a apontar para a 
                                                        mesma estrutura que o new.*/
    {
        vec[receptor] = new;                            
        filas[receptor].tail = vec[receptor];           /*Atualiza a posicao do ultimo node do receptor pretendido.*/
        filas[receptor].head = vec[receptor];           /*Atualiza a posicao do primeiro node do receptor pretendido.*/
    }
    else
    {
        filas[receptor].tail -> next = new;             /*Coloca o ponteiro 'next' do ultimo node a apontar para o node apontado pelo 
                                                        new.*/
        filas[receptor].tail = new;                     /*Atualiza o ultimo node do receptor pretendido.*/
    }
    filas[receptor].size ++;                            /*Incrementa o numero de mensagens do receptor pretendido.*/
}

/**
*@brief: Funcao que apaga o primeiro node do utilizador pretendido.
*/
void apagaPrimeiroNode(LINK *vec, FILA *filas, int utilizador)
{
	vec[utilizador] = vec[utilizador] -> next;              
    deleteMensagem(filas[utilizador].head -> mensagem);
    free(filas[utilizador].head);
    filas[utilizador].head = vec[utilizador];      
    filas[utilizador].size --;
}