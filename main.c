#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "init.h"


int main(){
    int opcao;
    TAREFA tarefas[100];
    int counter =(int) malloc(sizeof(int));
    counter =0;//guarda o número de tarefas 

    do {
        printf("\n1 - Criar Tarefa\n");
        printf("2 - Alterar Tarefa\n");
        printf("3 - Eliminar Tarefa\n");
        printf("4 - Consultar Tarefa\n\n");
        printf("Introduza o valor que pretende:  \n");
        scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            tarefas[counter] = criaTarefa();//criar a tarefa naquela posição
            counter++;
            break;
        case 2:
            alteraTarefa(tarefas, counter);
            break;
        case 3:
            eliminaTarefa(tarefas, counter);
            counter--;
            break;
        case 4: 
            consultaTarefa(tarefas, counter);
            break;
        default:
            printf("Opção Inválida\n");
        }
    } while (opcao != 5);
    return 0;
}   
