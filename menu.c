#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/**
 * @brief: Funcao main 
 * @return: Codigo de estado de saida do programa.
 */
int main()
{
	char comando;
    int utilizadores;
    LINK *vec;
    FILA *filas;

    scanf("%d", &utilizadores);
    getchar();                                        /*getchar para apanhar o \n do enter a seguir ao scanf()*/
    
    vec = (LINK*) malloc(sizeof(LINK)*utilizadores);  /*criacao de um vector de apontadores para nos com o tamanho dos utilizadores*/
    filas = (FILA*) malloc(sizeof(FILA)*utilizadores);/*criacao de um vector de estruturas do tipo fila com o tamanho dos utilizadores*/

    inicializa(vec, filas, utilizadores);             /*inicializacao dos ponteiros do vec assim como das filas*/

    while ((comando = getchar()) != 'q')              /*le a primeira letra do comando*/
    {
        switch(comando)
        {
            case 's':
                send(vec, filas);                     /*se for s entra dentro da funcao send*/
                break;
            case 'p':
                process(vec, filas);                  /*caso p entra na funcao process*/
                break;
            case 'l':
                list(filas);                          /*caso l entra dentro da funcao list, que se divide na listsorted e na listnormal*/
                break;
            case 'k':
                kill(vec, filas);                     /*caso k entra na funcao kill */
                break;
            default:
                printf("comando desconhecido\n");     /*se o comando for desconhecido limpa a memoria e sai do programa*/
                quit(vec, filas, utilizadores);
                free(filas);
                free(vec);
                return EXIT_FAILURE;         
        }
    }

    quit(vec, filas, utilizadores);                   /*limpa a memoria do utilizada*/
    free(filas);
    free(vec);

    return EXIT_SUCCESS;                              /*acaba o programa com sucesso!*/
}