#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas de nó e lista fornecidas
 * Você pode implementar funções auxiliares além das fornecidas,
 * para isso, coloque o cabeçário da função no arquivo .h e sua
 * implementação aqui, no arquivo .c. Não altere assinaturas de
 * funções, caso contrário seu código receberá nota 0,0 (zero).
 */

// Estrutura de nó duplamente encadeado
struct no {
	tipo 		 info;		//Informação (dado) armazenada no nó
	struct no	*ant;		//Ponteiro para o nó anterior
	struct no	*prx;		//Ponteiro para o próximo nó
};

//Estrutura de lista duplamente encadeada com nós
struct lista {
	no_t 		*cabeca;	//Ponteiro para a cabeça da lista (primeiro)
	no_t 		*cauda;		//Ponteiro para a cauda da lista (último)
	int 		tamanho;	//Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções

lista_t*	lista_cria				(){//DONE
    lista_t* nova = (lista_t*)malloc(sizeof(lista_t));
    if(!nova) return NULL;
    nova->cabeca = NULL;
    nova->cauda = NULL;
    return nova;
}



void		lista_destroi			(lista_t **l){//DONE
    if(!l || !*l){
        return;
    }else{
        no_t *temp;
        while ((*l)->cabeca != NULL){
            temp = (*l)->cabeca;
            (*l)->cabeca = (*l)->cabeca->prx;
            free(temp);
        }
        free(*l);
        *l = NULL;
    }
}

int 		lista_inicializada		(lista_t *l){//DONE
    if(!l) return 0;
    return 1;
}



int 		lista_tamanho			(lista_t *l){//DONE
    if(!l) return -1;
    return l->tamanho;

}


int 		lista_info_cabeca  		(lista_t *l, int *dado){//DONE
    if(!l) return -1; //NULL
    if(!dado) return -1;
    if(l->tamanho==0) return 0; //Empty

    *dado = l->cabeca->info;
    return 1;
}


int 		lista_info_cauda 		(lista_t *l, int *dado){//DONE
    if(!l) return -1; //NULL
    if(!dado) return -1;
    if(l->tamanho==0) return 0; //Empty


    *dado = l->cauda->info;
    return 1;
}


int 		lista_info_posicao 		(lista_t *l, int *dado, int pos){//DONE
    if(!l) return -1;
    if(!dado) return -1;
    if(l->tamanho==0) return 0;

    if(pos<0 || pos>=l->tamanho) return 0;

    no_t* local = caminha_lista(l,pos);
    *dado  = local->info;
    return 1;
}


int			lista_insere_cabeca		(lista_t *l, tipo dado){
    if(!l) return -1;
    no_t *n = cria_no();
    if(!n) return -1;

    n->info = dado;
    if(l->tamanho==0){
        l->cabeca = n;
        l->cauda = n;
        n->ant = NULL;
        n->prx = NULL;
    }

    if(l->tamanho>0){
        n->prx = l->cabeca;
        l->cabeca = n;
        n->ant = NULL;
    }

    l->tamanho++;
    return 1;
}


int			lista_insere_cauda		(lista_t *l, tipo dado){
    if(!l) return -1;

    if(l->tamanho==0) {
        lista_insere_cabeca(l,dado);
    }else{
        no_t *n = cria_no();
        if(!n) return -1;

        n->info = dado;
        l->cauda->prx = n;
        n->ant = l->cauda;
        n->prx = NULL;
        l->cauda = n;
        l->tamanho++;
    }

    return 1;
}


int			lista_insere_posicao	(lista_t *l, tipo dado, int pos){
    if(!l) return -1;
    if(pos<0 || pos > l->tamanho) return 0;

    if(pos == 0){
        lista_insere_cabeca(l,dado);
        return 1;
    }
    if(pos == l->tamanho){
        lista_insere_cauda(l,dado);
        return 1;
    }

    no_t *na_listaF = caminha_lista(l,pos);
    no_t *na_listaB = caminha_lista(l,pos-1);

    no_t *new = cria_no();

    if (!new) return 0;

    new->info = dado;
    new->ant = na_listaF->ant;
    new->prx = na_listaF;
    na_listaF->ant = new;
    na_listaB->prx = new;

    l->tamanho++;

    return 1;


}


int			lista_remove_cabeca		(lista_t *l, tipo *dado){
    if(!l || !dado) return -1;
    if((l->tamanho)==0) return 0;

    if(l->tamanho==1){
        *dado = l->cabeca->info;
        free(l->cabeca);
        l->cauda = NULL;
        l->cabeca = NULL;
        l->tamanho--;
        return 1;
    }
    no_t *temp;
    *dado = l->cabeca->info;
    temp = l->cabeca->prx;
    l->cabeca->prx = NULL;
    free(l->cabeca);
    l->cabeca = temp;
    l->tamanho--;

    return 1;
}//For test


int			lista_remove_cauda		(lista_t *l, tipo *dado){
    if(!l || !dado) return -1;
    if(l->tamanho==0) return 0;

    if(l->tamanho==1){
        int ret = lista_remove_cabeca(l,dado);
        return ret;
    }

    no_t *temp;

    *dado = l->cauda->info;
    temp = l->cauda->ant;
    l->cauda->ant = NULL;
    free(l->cauda);
    l->cauda = temp;
    l->cauda->prx = NULL;

    l->tamanho--;
    return 1;
}//For Test


int			lista_remove_posicao	(lista_t *l, tipo *dado, int pos){
    if(!l) return -1;
    if(!dado) return -1;
    if(pos<0 || pos >= l->tamanho) return 0;


    if(pos == 0){
        int ret = lista_remove_cabeca(l,dado);
        return ret;
    }
    if(pos == l->tamanho-1){
        int ret = lista_remove_cauda(l,dado);
        return ret;
    }
    //PAREI AQUI!
    no_t *temp = cria_no();

    temp = caminha_lista(l,pos);
    *dado = temp->info;

    temp->ant->prx = temp->prx;
    temp->prx->ant = temp->ant;

    free(temp);
    l->tamanho--;
    return 1;
}


int 		lista_remove_primeira	(lista_t *l, tipo dado){
    if(!l) return -1;
    int *temp;

    for(int i=0;i<l->tamanho;i++){
        if(caminha_lista(l,i)->info == dado){
            lista_remove_posicao(l,temp,i);
            l->tamanho--;
            return i;
        }
    }
    return -2;
}


int 		lista_remove_todas		(lista_t *l, tipo dado){
    if(!l) return -1;
    if(l->tamanho==0) return -0;
    int *temp;
    int rep=0;

    for(int i=0;i<l->tamanho;i++){
        if(caminha_lista(l,i)->info == dado){
            if(i==0){
                lista_remove_cabeca(l,temp);
                rep++;
            }
            if(i==l->tamanho-1){
                lista_remove_cauda(l,temp);
                rep++;
                return rep;
            }
            lista_remove_posicao(l,temp,i);
            rep++;
        }
    }
    return rep;
}


int 		lista_busca_info		(lista_t *l, tipo dado){
    if(!l) return -1;
    if(l->tamanho==0) return -1;

    for(int i; i<l->tamanho;i++){
        if(caminha_lista(l,i)->info == dado) return i;
    }
    return -1;
}

int 		lista_frequencia_info	(lista_t *l, tipo dado){
    if(!l) return -1;
    int rep=0;
    for(int i=0;i<l->tamanho;i++){
        if(caminha_lista(l,i)->info == dado) rep++;
    }
    return rep;
}

int			lista_ordenada 			(lista_t *l){
    if(!l) return -1;

    for(int i=0;i<l->tamanho-1;i++){
        if(caminha_lista(l,i)->info > caminha_lista(l,i+1)->info) return 0;
    }
    return 1;
}


int 		lista_insere_ordenado	(lista_t *l, tipo dado){
    if(!l) return -1;
    int i;
    for(i=0;i<l->tamanho;i++){
        if(dado < caminha_lista(l,i)->info){
            lista_insere_posicao(l,dado,i);
            return 1;
        }
    }
    if(i==l->tamanho){
        lista_insere_cauda(l,dado);
    }
    return -1;
}


int 		lista_compara(lista_t *l1, lista_t *l2){
    if(!l1 && !l2) return 1;
    if(l1->tamanho != l2->tamanho) return 0;

    for(int i=0;i<l1->tamanho;i++){
        if(caminha_lista(l1,i) != caminha_lista(l2,i)) return 0;
    }
    return 1;
}



int 		lista_reverte(lista_t *l){
    if(!l) return -1;
    int temp = 0;

    for(int i=0; i<(l->tamanho/2);i++){
        temp = caminha_lista(l,i)->info;
        caminha_lista(l,i)->info = caminha_lista(l,l->tamanho-i-1)->info;
        caminha_lista(l,l->tamanho-i-1)->info = temp;
    }
    return 1;
}


lista_t*	lista_cria_copia(lista_t *l){
    if(!l) return NULL;
    lista_t *new = lista_cria();
    if(!new) return NULL;

    new->tamanho = l->tamanho;
    new->cabeca = l->cabeca;
    new->cauda = l->cauda;

    return new;
}

no_t* caminha_lista(lista_t *l,int pos){
    no_t *temp = l->cabeca;
    int i = 0;
    while(i<pos){
        temp = temp->prx;
        i++;
    }
    return temp;
}

no_t* cria_no(){
    no_t *n = (no_t*)malloc(sizeof(no_t));
    if(!n) return NULL;
    return n;
}

int main (){
	lista_t *t = lista_cria();
    //lista_t *t = NULL;
	int v = -1;
	int *dado = &v;
	printf("%d\n", lista_tamanho(t));
	//lista_insere_cabeca(t,0);
	//lista_insere_cauda(t,111);
    lista_destroi(t);
    printf("%d\n", lista_tamanho(t));
	for(int i=0;i<20;i++){
		lista_insere_posicao(t,i+2,i);
	}
	
	for(int i =0;i<lista_tamanho(t);i++){
		printf("%d ",caminha_lista(t,i)->info);
	}
	printf("\n Remove Posição\n");

   lista_remove_posicao(t,dado,19);
    for(int i =0;i<lista_tamanho(t);i++){
        printf("%d ",caminha_lista(t,i)->info);
    }
    printf("\n");


    lista_insere_cauda(t,8);
    for(int i =0;i<lista_tamanho(t);i++){
        printf("%d ",caminha_lista(t,i)->info);
    }
    printf("\n Remove Primeira\n");

    lista_remove_primeira(t,8);
    for(int i =0;i<lista_tamanho(t);i++){
        printf("%d ",caminha_lista(t,i)->info);
    }
    printf("\n");

    printf("%d\n", lista_insere_ordenado(t,1));
    for(int i =0;i<lista_tamanho(t);i++){
       printf("%d ",caminha_lista(t,i)->info);
    }
    printf("\n");

    printf("%d\n", lista_reverte(t));
    for(int i =0;i<lista_tamanho(t);i++){
        printf("%d ",caminha_lista(t,i)->info);
    }
    printf("\n");

	return 0;
}
