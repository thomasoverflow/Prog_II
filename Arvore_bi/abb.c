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
    no_t **p = NULL;

    while(*ptr != NULL){
        if(chave < (*ptr)->chave){
            p = ptr;
            ptr = &((*ptr)->esq);
        }
        else if (chave > (*ptr)->chave){
            p = ptr;
            ptr = &((*ptr)->dir);
        }
        else{
            //Achamos o nó -> armazenado em ptr
            //1°Caso: Yo soy una FOLHA
            if((*ptr)->esq == NULL && (*ptr)->dir == NULL) {
                if((*p)->dir == NULL){
                    free(*ptr);
                    (*p)->esq = NULL;
                }else{
                    free(*ptr);
                    (*p)->dir = NULL;
                }
            }else if((*ptr)->esq == NULL){//2a°Caso: Yo soy un nó apenas com un hijo a derecha (MUDAR)[
                no_t *aux = (*ptr)->dir;
                free(*ptr);
                (*p)->dir = aux;
            }else if((*ptr)->dir == NULL){//2b°Caso: Yo soy un nó apenas com un hijo a esquerda (MUDAR)
                no_t *aux = (*ptr)->esq;
                if((*ptr)->chave == (*p)->esq->chave){
                    free(*ptr);
                    (*p)->esq = aux;
                }else{
                    free(*ptr);
                    (*p)->dir = aux;
                }

            }else{//3°Caso: Yo tengo two hijoss
                no_t **new = &((*ptr)->esq);

                while((*new)->dir){
                    p = new;
                    new = &((*new)->dir);
                }//Chegamos no nó que irá substituir
                if((*new)->dir){
                    (*ptr)->chave = (*new)->chave;
                    (*new)->chave = (*new)->dir->chave;
                    free((*new)->dir);
                    (*new)->dir = NULL;
                }else{
                    (*ptr)->chave = (*new)->chave;
                    free(*new);
                    (*ptr)->esq = NULL;
                    //(*p)->esq = NULL;
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

    /*abb_insere(l,37);
    abb_insere(l,59);
    abb_insere(l,13);
    abb_insere(l,42);
    abb_insere(l,43);
    abb_insere(l,27);
    abb_insere(l,21);
    abb_insere(l,60);
    abb_insere(l,4);
    abb_insere(l,3);
    abb_insere(l,5);*/
    abb_insere(l,10);
    abb_insere(l,21);
    abb_insere(l,5);
    abb_insere(l,15);
    abb_insere(l,23);
    abb_insere(l,30);
    abb_insere(l,3);
    abb_insere(l,7);
    abb_insere(l,1);
    abb_insere(l,6);





    int t = abb_busca(l,60);
    int k = abb_remove(l,10);
    //printf("%d\n",k);
     //k = abb_remove(l,1);
    //printf("%d\n",k);
     //k = abb_remove(l,60);
    printf("%d",k);


    abb_destroi(&l);
    return 0;
}