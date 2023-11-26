#include "abb_privado.h"

/* Coloque abaixo as suas implementações */


abb_t*		abb_cria		(){
    abb_t *new = (abb_t*) malloc(sizeof(abb_t));
    new->raiz = NULL;
    return new;
}

void		abb_destroi		(abb_t **arv){
    if(*arv == NULL) return;

    abb_destroi_rec((*arv)->raiz);
    free(*arv);
    *arv = NULL;
}

int 		abb_insere		(abb_t *arv, elem_t chave){
    if(!arv) return -1;

    //Caso em que a arvore foi inicializada mas esta vazia
    if(arv->raiz == NULL){
       arv-> raiz = cria_no(NULL,NULL,chave);
       return 1;
    }
    no_t *ptr = arv->raiz;

    //Caso onde já temos uma raiz
    while(ptr!=NULL){
        if(chave == ptr->chave) return 0;
        if(chave < ptr->chave){
            if(ptr->esq == NULL){
                ptr->esq = cria_no(NULL,NULL,chave);
                break;
            }
            ptr = ptr->esq;
        }else{
            if(ptr->dir == NULL){
                ptr->dir = cria_no(NULL,NULL,chave);
                break;
            }
            ptr = ptr->dir;
        }
    }
    return 1;
}

int 		abb_remove		(abb_t *arv, elem_t chave){
    if(!arv) return -1;

    no_t **ptr = &(arv->raiz);

    while(*ptr != NULL){
        if(chave < (*ptr)->chave){
            ptr = &((*ptr)->esq);
        }
        else if (chave > (*ptr)->chave){
            ptr = &((*ptr)->dir);
        }
        else{
            //Achamos o nó -> armazenado em ptr
            //1°Caso: Yo soy una FOLHA
            if((*ptr)->esq == NULL && (*ptr)->dir == NULL) {
                free(*ptr);
                *ptr = NULL;
            }else if((*ptr)->esq == NULL){//2a°Caso: Yo soy un nó apenas com un hijo a derecha
                no_t *aux = *ptr;
                *ptr = (*ptr)->dir;
                free(aux);
            }else if((*ptr)->dir == NULL){//2b°Caso: Yo soy un nó apenas com un hijo a esquerda
                no_t *aux = *ptr;
                *ptr = (*ptr)->esq;
                free(aux);
            }else{//3°Caso: Yo tengo two hijoss
                no_t **new = &((*ptr)->dir);
                while((*new)->esq){
                    new = &((*new)->esq);
                }//Chegamos no nó que irá substituir
                if((*new)->dir){
                    no_t *temp;
                    (*ptr)->chave = (*new)->chave;
                    temp = (*new)->dir;
                    (*new)->dir = NULL;
                    free(temp);
                }else{
                    (*ptr)->chave = (*new)->chave;
                    *new = NULL;
                    free(*new);
                }//caso esteja na folha

            }
            return 1;
        }

    }
    return 0;
}//PARA TESTE

int 		abb_busca  		(abb_t *arv, elem_t chave){
    if(!arv) return -1;

    no_t *ptr = arv ->raiz;
    while(ptr!=NULL){
        if(chave == ptr->chave) return 1;
        if(chave < ptr->chave){
            ptr = ptr->esq;
        }else{
            ptr = ptr->dir;
        }
    }
    return 0;
}


int main(){
    abb_t *l = abb_cria();

    abb_insere(l,3);
    abb_insere(l,1);
    abb_insere(l,5);
    abb_insere(l,6);
    abb_insere(l,7);


    abb_destroi(&l);
    return 0;
}