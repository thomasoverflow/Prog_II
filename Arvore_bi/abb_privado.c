#include "abb_privado.h"

/* Coloque abaixo as suas implementações */

void		abb_destroi_rec		(no_t *n){
    if(!n) return;

    abb_destroi_rec(n->esq);
    abb_destroi_rec(n->dir);

    free(n);
    return;
}//PARA TESTE

no_t* cria_no(no_t* esq, no_t* dir, elem_t chave){
    no_t *new_no = (no_t*)malloc(sizeof(no_t));

    new_no->esq = esq;
    new_no->dir = dir;
    new_no->chave = chave;

    return new_no;
}

no_t* remove_rec(no_t* n,elem_t chave){
    if (n == NULL){
        return n;
    }//Caso que quebra a recursividade
    if (n->chave > chave) {
        n->esq = remove_rec(n->esq, chave);
        return n;
    }else if (n->chave < chave) {
        n->dir = remove_rec(n->dir, chave);
        return n;
    }

    if (n->esq == NULL) {//Nó vazio esquerda
        no_t* temp = n->dir;
        free(n);
        return temp;
    }else if (n->dir == NULL) {//Nó vazio direita
        no_t* temp = n->esq;
        free(n);
        return temp;
    }else {
        no_t *p_s = n; //pai sucessor
        no_t *s = n->dir; //sucessor
        while (s->esq != NULL) {
            p_s = s;
            s = s->esq;
        }
        if (p_s != n){
            p_s->esq = s->dir;
        }else {
            p_s->dir = s->dir;
        }
        n->chave = s->chave;
        free(s);
        return n;
    }//Nó é uma subarvore e ocorre recursão
}

