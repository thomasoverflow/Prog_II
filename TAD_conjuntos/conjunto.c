#include "conjunto_privado.h"

// Coloque aqui a implementacao das funcoes

/*
 * Retorna um ponteiro para conjunto recem criado com espaco para armazenar inicialmente 10 elementos
 * Pre-condicao: o sistema deve ter memoria para alocar o novo conjunto
 * Pos-condicao: o novo conjunto eh retornado
 */
conjunto_t *conjunto_cria(void){ //UNDONE precisa implentar a pre-condicao
	conjunto_t *conjunto = (conjunto_t*) malloc(sizeof(conjunto_t));
	if(conjunto==NULL) return NULL;
	conjunto -> vetor = (elem_t*) malloc(sizeof(elem_t)*ELEMENTOS);
	conjunto -> numero = 0;
	conjunto -> capacidade = ELEMENTOS;
	return conjunto;
}

/*
 * Destroi o conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao: o conjunto passado por parametro nao eh mais valido, nao podera mais ser utilizado e devera apontar para NULL
 */
void conjunto_destroi(conjunto_t **a){//DONE
	if(!a||!(*a)) return;
	if((*a) -> vetor != NULL){
		free((*a) -> vetor);
	}
	free(*a);
	*a = NULL;
}

/*
 * Retorna o numero de elementos que estao no conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao:
 */
int conjunto_numero_elementos(conjunto_t *a){//DONE
	if(a!= NULL) return a -> numero;
}

/*
 * Recebe um conjunto como parametro e o inicializa como conjunto vazio
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "a" passara a ser um conjunto vazio
 */
void conjunto_inicializa_vazio(conjunto_t *a){//DONE
	if(a==NULL) return;
	a -> numero = 0;
	return;
}

/*
 * Recebe os conjuntos "a e "b" e retorna a uniao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a uniao entre os conjuntos "a" e "b"
 */
void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){//DONE
	if(a == NULL || b == NULL || c ==NULL) return;
	c -> vetor = realloc(c->vetor, sizeof(int)*(a->capacidade + b->capacidade));
	c -> numero = 0; //if vector is aready with numero >0
	c -> capacidade = a->capacidade + b->capacidade;
	int i;
	for(i=0; i< a->numero; i++){ //add itens from de a struct to c
		c -> vetor[i] = a -> vetor[i];
		c -> numero++;
	}
	//now we need to run a check of what number repeats to not add in the list
	int rep = 0;
	for(i=0;i<b->numero;i++){
		for(int j=0;j<a->numero;j++){
			if(b->vetor[i] == a->vetor[j]){
				rep++;
			}
		}
		if(rep==0){
			c->vetor[c->numero] = b->vetor[i];
			c -> numero++;
		}
		rep = 0;
	}
}


/*
 * Recebe os conjuntos "a e "b" e retorna a interseccao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a interseccao entre os conjuntos "a" e "b"
 */
void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){//DONe
	if(a == NULL || b == NULL || c ==NULL) return;
	c -> vetor = realloc(c->vetor, sizeof(int)*(a->capacidade + b->capacidade));
	c->capacidade = a->capacidade + b->capacidade;
	conjunto_inicializa_vazio(c);


	for(int i=0;i< a->numero;i++){
		for(int j=0;j< b->numero;j++){
			if(a->vetor[i] == b->vetor[j]){
				c->vetor[c->numero] = a->vetor[i];
				c -> numero++;
			}
		}
	}
}

/*
 * Recebe os conjuntos "a" e "b" e retorna a diferenca entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos, criados pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "c" contera a diferenca entre os conjuntos "a" e "b"
 */
void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){//DONE
	if(a == NULL || b == NULL || c ==NULL) return;
	c -> vetor = realloc(c->vetor,sizeof(int)* (a->capacidade + b->capacidade));
	c -> capacidade = a->capacidade + b->capacidade;
	c -> numero = 0; //if vector is aready with numero >0

	int i;
	int rep =0;
	for(i=0;i< a->numero;i++){
		for(int j =0;j< b->numero;j++){
			if(a->vetor[i] == b->vetor[j] ) rep++;
		}
		if(rep ==0){
			c->vetor[c->numero] = a->vetor[i];
			c->numero++;
		}
		rep=0;
	}

	for(int k=0;k< b->numero;k++){
		for(int j =0;j< a->numero;j++){
			if(a->vetor[j] == b->vetor[k] ) rep++;
		}
		if(rep ==0){
			c->vetor[c->numero] = b->vetor[k];
			i++;
			c->numero++;
		}
		rep=0;
	}

}

/*
 * Retorna 1 se o elemento "x" pertence ao conjunto "a", 0 caso contrario
 * Pre-condicao: o conjunto A deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o valor retornado sera 0 ou 1
 */
int conjunto_membro(elem_t x, conjunto_t *a){//DONE
	if( a!=NULL){
		for(int i =0;i< a->numero;i++){
			if(x == a->vetor[i]) return 1;
		}
		return 0;
	}

	return 0;
}

/*
 * Insere o elemento "x" no conjunto "a". Se "x" ja pertencer a "a" nao faz nada (retorna 1 nesse caso). Retorna 1 caso inseriu corretamente, 0 caso contrario.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o elemento "x" passara a pertencer ao conjunto "a"
 */
int conjunto_insere_elemento(elem_t x, conjunto_t *a){//DONE
	if(a!= NULL){
		if( conjunto_membro(x,a)==0){
			//Check is if FULL
			if(a->capacidade == a->numero){//Need to change size
				a -> capacidade++;
                a ->vetor = realloc(a->vetor,sizeof(int)*(a->capacidade));
				a ->vetor[a->numero] = x;
				a->numero++;
			}else{//if have free space
				a ->vetor[a->numero] = x;
				a->numero++;
			}
		}
		return 1;
	}
	return 0;
}

/*
 * Remove o elemento "x" no conjunto "a". Se "x" nao pertencer a "a", nao faz nada
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "a" passara a nao ter mais o elemento "x"
 */
void conjunto_remove_elemento(elem_t x, conjunto_t *a){//DONE
	if (a!= NULL){
		if(conjunto_membro(x,a)==1){
			int i =0;
			elem_t temp;
			while(a->vetor[i] !=x)  i++;
			a->vetor[i] = 0;
			while(i<a->numero){
					temp = a->vetor[i];
					a->vetor[i] = a->vetor[i+1];
					a->vetor[i+1] = temp;
					i++;
				}
			a->numero--;
			return;
		}
	}
}

/*
 * Atribui o conjunto "a" ao "b" (b = a)
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao:
 */
void conjunto_atribui(conjunto_t *a, conjunto_t *b){//DONE
	if(a != NULL && b != NULL){
		if(b->capacidade < a->capacidade){
				b -> vetor = (elem_t*)realloc(b->vetor,sizeof(int)*(a->capacidade));
				b->capacidade = a->capacidade;
		}
		for(int i=0;i<a->numero;i++){
				b->vetor[i] = a->vetor[i];
		}
		b->numero = a->numero;
		return;
	}
}

/*
 * Retorna 1 caso o conjunto "a" seja igual ao conjunto "b", 0 caso contrario
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao:
 */
int conjunto_igual(conjunto_t *a, conjunto_t *b){
	if( a!= NULL && b != NULL){
		if(a->numero != b->numero) return 0;
		for(int i=0;i<a->numero;i++){
			if(conjunto_membro(b->vetor[i],a)  == 0) return 0;
		}
		return 1;
	}
	return 0;
}

/*
  * Retorna o valor minimo dentro do conjunto "a", retorne ELEM_MAX caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao:
 */
elem_t conjunto_minimo(conjunto_t *a){
	if( a == NULL) return ELEM_MAX;
	elem_t minor = a->vetor[0];
	for(int i=1;i<a->numero;i++){
			if(a->vetor[i] < minor) minor= a->vetor[i];
	}
	return minor;
}

/*
 * Retorna o valor maximo dentro do conjunto "a", retorne ELEM_MIN caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao:
 */
elem_t conjunto_maximo(conjunto_t *a){
	if( a == NULL) return ELEM_MIN;
	elem_t major = a->vetor[0];
	for(int i=1;i<a->numero;i++){
			if(a->vetor[i] > major) major= a->vetor[i];
	}
	return major;
}

/*
 * Imprime o conjunto "a", sendo os elementos separados por espaço. Se for o ultimo elemento, nao deve ser impresso o ultimo espaco. Quebra de linha no final.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao:
 */
void conjunto_imprime(conjunto_t *a){
	if(a!=NULL){
		int i;
		if(a->numero == 1){
			printf("%d\n",a->vetor[0]);
		}else{
			for(i=0;i<(a->numero -1 );i++){
					printf("%d  ",a->vetor[i]);
				}
				printf("%d\n", a->vetor[i]);
		}
	}
}

int main(){
	conjunto_t *a = conjunto_cria();
    conjunto_t *b = conjunto_cria();
    conjunto_t *c = conjunto_cria();
	a->numero = 5;
    for(int i=0; i<a->numero; i++){
        a->vetor[i] = i+3;
    }
	b->numero = 10;
    for(int i=0; i<b->numero; i++){
        b->vetor[i] = i+4;
    }
	
	conjunto_insere_elemento(10,a);
	conjunto_insere_elemento(15,a);
	conjunto_insere_elemento(18,a);
	conjunto_insere_elemento(16,a);
	conjunto_insere_elemento(20,a);
	conjunto_insere_elemento(20,a);
	conjunto_remove_elemento(15,a);
	conjunto_insere_elemento(25,a);
	conjunto_imprime(a);
	conjunto_imprime(b);
	conjunto_diferenca(a,b,c);
	conjunto_imprime(c);
	/*printf("%d\n",conjunto_igual(a,b));
	conjunto_interseccao(a,b,c);
    printf("Interseccao a e b: ");
    conjunto_imprime(c);
    printf("b: ");
    conjunto_imprime(b);
	conjunto_atribui(a,b);
	conjunto_imprime(b);
	printf("Valor mínimo: %d valor máximo: %d\n",conjunto_minimo(a),conjunto_maximo(a));
	printf("%d",conjunto_igual(a,b));
	//conjunto_destroi(&a);
	conjunto_destroi(&b);
	//conjunto_destroi(&c);
	//printf("c: ");
    //conjunto_imprime(c);*/
	/*conjunto_destroi(&a);
    conjunto_destroi(&b);
    conjunto_destroi(&c);
	conjunto_t *d = NULL;
	conjunto_imprime(d);
	conjunto_numero_elementos(d);
	conjunto_imprime(d);
	conjunto_inicializa_vazio(d);
	conjunto_imprime(d);
	conjunto_uniao(a,b,d);
	conjunto_imprime(d);
	conjunto_interseccao(a,b,d);
	conjunto_imprime(d);
	conjunto_interseccao(a,d,b);
	conjunto_imprime(d);
	conjunto_diferenca(a,b,d);
	conjunto_imprime(d);
	conjunto_diferenca(a,d,b);
	conjunto_imprime(d);
	conjunto_membro(3,d);
	conjunto_imprime(d);
	conjunto_insere_elemento(5,d);
	conjunto_imprime(d);
	conjunto_remove_elemento(5, d);
	conjunto_imprime(d);
	conjunto_atribui(a, d);
	conjunto_imprime(d);
	conjunto_igual(a, d);
	conjunto_imprime(d);
	printf("%d",conjunto_minimo(d));
	conjunto_imprime(d);
	printf("%d",conjunto_maximo(d));
	conjunto_imprime(d);
	conjunto_imprime(d);
	conjunto_destroi(&d);
	conjunto_imprime(d);*/
	return 0;
}
