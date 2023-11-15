//
// Created by thomas on 13/11/23.
//
#include "pilha.h"


branch_t* cria_branch(int n){
    branch_t *t = (branch_t*) malloc(sizeof(branch_t));
    if(!t) return NULL;
    t->tamanho = n;
    t->vetores = (int**) malloc(sizeof(int*)*n);

    for (int i = 0; i < n; i++) {
        t->vetores[i] = (int *) malloc(n * sizeof(int));
    }

    return t;
}

void destroi_branch(branch_t **l){
    if(!(*l)) return;
    for (int i = 0; i < (*l)->tamanho; i++) {
        free((*l)->vetores[i]);
    }
    free((*l)->vetores);
    free(*l);
    *l = NULL;
}