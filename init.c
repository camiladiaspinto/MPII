#include <stdio.h>
#include <string.h>

#include "init.h"
#include "struct.h"

/*Funcao que cria uma tarefa*/
TAREFA criaTarefa(){
    TAREFA tar;

    printf("Identificador: ");
    scanf("%d", &(tar.identificador));

    printf("Descrição: ");
    scanf("%s", tar.descricao);

    printf("Tipo: ");
    scanf("%s", tar.tipo);

    printf("Subtipo: ");
    scanf("%s", tar.subtipo);

    printf("Data de Início: ");
    scanf("%s", tar.datainicio);

    printf("Data de Fim: ");
    scanf("%s", tar.datafim);

    return tar;
}

/* Função que consulta uma tarefa*/ 
void consultaTarefa(TAREFA* tarefas, int counter){
    printf ("Introduza a data da tarefa a que pretende aceder(formato:AAAAMMDD-HHmm)\n");
    char data[13];
    scanf("%s", data);
       
    if(counter == 0)
        printf("Não encontra nenhuma tarefa\n");
    else {
        for(int i = 0; i < counter; i++){
            if(strcmp(data, tarefas[i].datainicio) == 0){
                printf("Identificador: %d\n", tarefas[i].identificador);
                printf("Descrição: %s\n", tarefas[i].descricao);
                printf("Tipo: %s\n", tarefas[i].tipo);
                printf("Subtipo: %s\n", tarefas[i].subtipo);
                printf("Data do início: %s\n", tarefas[i].datainicio);
                printf("Data do fim: %s\n", tarefas[i].datafim);
                break; 
            }
            else{
                printf("Não encontra nenhuma tarefa\n");
                break; //impede de dar print o resto das n vezes do for
            }
        }
    }
} 
/*Função que retorna o valor da data de inicio, contido na struct */
char *datai(TAREFA* tarefas, int index){
    return tarefas[index].datainicio;
}

/* Funcao que elimina uma tarefa*/
void eliminaTarefa(TAREFA* tarefas, int counter) {

    printf ("\nIntroduza a data da tarefa que pretende eliminar(formato:AAAAMMDD-HHmm)\n");
    char data[13];
    scanf("%s", data);
     int idx;
    //Descobre o index da tarefa a eliminar
    for(int i = 0; i < counter; i++) {
        if(strcmp(datai(tarefas,i),data)==0) { 
            idx = i;
            break;
        }
    }

    //Salta um caracter para a frente no index da tarefa que é para eliminar
    for(int j = idx; j < counter; j++) {
        tarefas[j] = tarefas[j+1];
    }
}

/* Função que altera os parâmetros da tarefa*/
void alteraTarefa(TAREFA* tarefas, int counter) {
    printf ("\nIntroduza a data da tarefa que pretende alterar (formato:AAAAMMDD-HHmm)\n");
    char data[13];
    scanf("%s", data);

    int index;

    //Descobre o index da tarefa a alterar
    for(int i = 0; i < counter; i++) {
        if(strcmp (data,tarefas[i].datainicio)==0) {
            index = i;
            break;
        }
    }
    int flag = 1;
    while(flag) { //ciclo infinito

        printf("\n1 - Identificador\n");
        printf("2 - Descrição\n");
        printf("3 - Tipo\n");
        printf("4 - Subtipo\n");
        printf("5 - Data de Inicio\n");
        printf("5 - Data de Fim\n");
        printf("\nIntroduza o valor que pretende alterar: ");
        int opcao;
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                 printf("Indentificador: ");
                 scanf("%d",&(tarefas[index].identificador));            
                break;
            case 2:
                printf("Descrição: ");
                scanf("%s",tarefas[index].descricao);
                break;
            case 3:
                printf("Tipo: ");
                scanf("%s", tarefas[index].tipo);
                break;
            case 4:
                printf("Subtipo: ");
                scanf("%s",tarefas[index].subtipo);
                break;
            case 5:
                printf("Data do início: ");
                scanf("%s",tarefas[index].datainicio);
                break;
            case 6:
                printf("Data do fim: ");
                scanf("%s",tarefas[index].datafim);
                break;
            default:
                printf("Opção invalida");
                break;
        }
    
        char resposta[1];
        printf("Pretende alterar mais algum valor? S/N ");
        scanf("%s", resposta);
        if(strcmp(resposta, "N") == 0){ 
            flag = 0;
            break; //para não continuar
        }
        else{
            flag = 1;//volta a iterar
        }
    }
}
