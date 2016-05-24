#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"


/**
*@brief: Funcao que imprime todas as mensagens do utilizador pretendido, por ordem de recepcao.
*/
void listNormal(FILA *filas)
{
    int utilizador;
    LINK current;
    char aux;

    utilizador = (((int)getchar())-48);                 /*transforma o caracter relativo ao utilizador num inteiro.*/
    while ((aux = getchar()) != '\n')                   /*ciclo que enquanto nao apanha o \n transforma os caraceteres
                                                        correspontentes ao utilizador num inteiro.*/
        utilizador = utilizador*10 + (((int)aux)-48);   

    if (filas[utilizador].size == 0)                    /*Se nao houver mensagens para o utilizador pretendido, returna NULL.*/
    {
        puts("NULL");
        return;
    }

    current = filas[utilizador].head;                   /*Atribui a um ponteiro auxiliar o endereco da primeira mensagem 
                                                            do utilizador indicado.*/
    imprimeMensagem(current -> mensagem);               /*Imprime a mensagem pretendida.*/
    while (current -> next != NULL)                     /*Ciclo que ira 'percorrer as mensagens existentes do utilizador*/
    {                                                   /*pretendido e imprimir as mesmas.*/
        current = current -> next;
        imprimeMensagem(current -> mensagem);
    }
}

/**
*@brief: Funcao que imprime todas as mensagens do utilizador pretendido, por ordem alfabetica.
*/
void listSorted(FILA *filas)
{
    int utilizador, size, count = 0, i;
    SMS *vec;
    LINK current;
    char aux;


    getchar();                                            /*Comandos utilizados para ler 'istsorted_', dado que*/
    getchar();                                            /*nao serao necessarios no decorrer do programa.*/
    getchar();
    getchar();
    getchar();
    getchar();

    utilizador = (((int)getchar())-48);                    /*transforma o caracter relativo ao utilizador num inteiro.*/
    while ((aux = getchar()) != '\n')                      /*ciclo que enquanto nao apanha o \n transforma os caraceteres
                                                           correspontentes ao utilizador num inteiro.*/
        utilizador = utilizador*10 + (((int)aux)-48);

    size = filas[utilizador].size;                          

    if (size == 0)
    {
        puts("NULL");
        return;
    }

    vec = (SMS*) malloc(sizeof(SMS)*size);                  /*criacao de um vector auxiliar com ponteiros para mensagens.*/
    current = filas[utilizador].head;                       
    while (current->next != NULL)                           /*ciclo while que mete os ponteiros a apontar para as mensagens corres-
                                                            pondentes do vector principal.*/
    {
        vec[count] = current->mensagem;
        current =  current->next;
        count ++;
    }
    vec[count] = current->mensagem;
    insertionSort(vec, 0, size);                           /*organizacao do vector auxiliar.*/
    for ( i = 0; i < (size); i++)                          /*ciclo for para o imprimir.*/
    {
        imprimeMensagem(vec[i]);
    }
    free(vec);
}

/**
*@brief: Funcao insertionSort que vai organizar o vector auxiliar.
*/
void insertionSort(SMS *vec, int l, int r)
{
    int i, j;
    SMS auxiliar;  /**/
    
    for (i = 0; i < r ; ++i)
    {
        auxiliar = vec[i];
        j = i - 1;
        while ((j >= l) && ((strcmp(auxiliar->string, vec[j]->string) < 0) ||/*condicao (ou) extra para garantir que no caso de as */
        ((strcmp(auxiliar->string, vec[j]->string) == 0) &&                  /*strings serem iguais, vai verificar a ordem dos emissores*/
            (auxiliar->emissor < vec[j]->emissor))))                          
        {
            vec[j + 1] = vec[j];
            j --;
        }
        vec[j + 1] = auxiliar;
    }
}

/**
*@brief: Funcao para processar o comando 'list'.
*/
void list(FILA *filas)
{
    char c;

    getchar();                                          /*Comandos utilizados para ler 'ist', dados que*/
    getchar();                                          /*nao seram necessarios no decorrer do programa.*/
    getchar();                                          
    c = getchar();                                      /*Variavel que ira conter um '_' ou um 's'.*/

    if (c == ' ') listNormal(filas);                    /*caso seja um espaco chama o listnormal caso contrario e o listsorted.*/

    else listSorted(filas);
}