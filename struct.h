/* Definição das estruturas */
#ifndef HEADER_FILE 
#define HEADER_FILE 

#define MAXN 100

 /* Definição do colaborador */

typedef struct{
    int identificador;
    char nome[MAXN];
    char email[MAXN];
    char tele[MAXN];
    char afinidade [MAXN];
} COLABORADOR;

/* Definição do tarefa */

typedef struct{
    int identificador;
    char descricao[MAXN];
    char tipo [MAXN];
    char subtipo[MAXN];
    char datainicio[MAXN];
    char datafim[MAXN];
} TAREFA;

#endif
