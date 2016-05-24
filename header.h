/*
*@Nome da pasta .zip: tg012_proj2.zip
*@Files: header.h, menu.c, kill.c, list.c, mensagem.c, node.c, process.c, send.c
*
*@Alunos: Ricardo Rei (78047)
*         Luis Ambrosio Nunes (77940)
*         Luis Santos Henriques (77919)
*
*@Grupo: TG012
*
*@Projecto: segundo projecto de IAED
*/
#ifndef HEADER_H
#define HEADER_H

#define TAMANHO_MAX 501           /*tamanho maximo que o texto de uma mensagem pode ter (contando com o \0).*/


typedef char* TEXTO;              /* ponteiro para o tipo char ou seja a string que vai dar origem ao texto das mensagens.*/
typedef struct MENSAGEM* SMS;     /* ponteiro para a estrutura mensagem.*/
typedef struct NODE* LINK;

/**
*@brief: Estrutura MENSAGEM que contem o emissor, o receptor e a respectiva mensagem.
*/
struct MENSAGEM
{
	int emissor;
	int receptor;
	TEXTO string;
};

/**
*@brief: Estrutura NODE que contem um ponteiro para uma mensagem e um ponteiro para o proximo NODE.
*/
struct NODE
{
	SMS mensagem;
	LINK next;
};

/** 
*@brief: Estrutura FILA que vai guardar o endereco do primeiro elemento da lista ligada de NOS e do ultimo.
*/
typedef struct
{
	LINK head;
	LINK tail;
	int size;
} FILA;

/*Declaracao das funcoes do ficheiro mensagem.c*/
TEXTO recebeTexto();
void imprimeTexto(TEXTO);
SMS criaMensagem(int, int, TEXTO);
void imprimeMensagem(SMS msg);
void deleteTexto(TEXTO txt);
void deleteMensagem(SMS msg);

/*Declaracao das funcoes do ficheiro node.c*/
LINK criaNode(SMS);
void acrecentaNode(LINK *, FILA *, int, LINK );
void apagaPrimeiroNode(LINK *, FILA *, int);

/*Declaracao das funcoes do ficheiro process.c*/
void process(LINK *, FILA *);

/*Declaracao das funcoes do ficheiro kill.c*/							
void kill(LINK *, FILA *);								
void quit(LINK *, FILA *, int);						

/*Declaracao das ficheiro do comando send.c*/
void send(LINK *, FILA *);
void inicializa(LINK *, FILA *, int);

/*Declaracao das funcoes do ficheiro do list.c*/
void list(FILA *);
void listNormal(FILA *);
void insertionSort(SMS *, int , int );
void listSorted(FILA *);

#endif