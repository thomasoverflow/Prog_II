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
//free(*v);
    *v = NULL;
}

void empilha(vector_t *v, int *elem){
    if(!v) return;
    if(v->tamanho == v->capacidade) return;

    v->vetor[v->tamanho] = *elem;
    v->tamanho++;
}

void desempilha(vector_t *v, int *elem) {
    if (!v) return;
    if (!elem) return;
    if (v->tamanho == 0) return;

    *elem = v->vetor[v->tamanho - 1];
    v->tamanho--;
}


void encontra(branch_t *l, vector_t **pilha, int *j, int valor) {
    int i = 0;
    int h;
    *j = 0;
    *pilha = NULL;  // Initialize to NULL to avoid potential issues

    while (l->vetores[i] != NULL) {
        h = 0;
        while (h < l->vetores[i]->tamanho && l->vetores[i]->vetor[h] != valor) {
            h++;
        }
        if (h < l->vetores[i]->tamanho) {
            *j = h;
            *pilha = l->vetores[i];
            break;
        }
        i++;
    }
}