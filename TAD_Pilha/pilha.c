//
// Created by thomas on 13/11/23.
//
#include "pilha.h"


branch_t* cria_branch(int n){
    branch_t *t = (branch_t*) malloc(sizeof(branch_t));
    if(!t) return NULL;
    t->tamanho = n;
    t->vetores = (vector_t **) malloc(sizeof(vector_t*)*n);

    for (int i = 0; i <= n; i++) {
        t->vetores[i] = cria_vector(n);
    }
    for(int i = 0; i <= n; i++){
        t->vetores[i]->vetor[0] = i;
    }
    return t;
}

vector_t *cria_vector(int capacidade){
    vector_t *t = (vector_t *)malloc(sizeof(vector_t));
    if(t == NULL) return NULL;
    t->vetor = (int*) malloc(sizeof(int)*capacidade);
    if (t->vetor == NULL) {
        free(t);
        return NULL;
    }
    t->capacidade = capacidade;
    t->tamanho = 1;
    return t;
}

void destroi_branch(branch_t **l){
    if(!(*l)) return;
    for (int i = 0; i < (*l)->tamanho; i++) {
        destroi_vector(&((*l)->vetores[i]));
    }
    free((*l)->vetores);
    free(*l);
    *l = NULL;
}


void destroi_vector(vector_t **v) {
    if (*v == NULL) return;
    free((*v)->vetor);
    free(*v);
    *v = NULL;
}

void find_data(branch_t *b, int valor, int *i, int *j) {
    for (*i = 0; *i < b->tamanho; (*i)++) {
        for (*j = 0; *j < b->vetores[*i]->tamanho; (*j)++) {
            if (b->vetores[*i]->vetor[*j] == valor) return;
        }
    }
    *j--;
}