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
