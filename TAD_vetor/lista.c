#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas fornecidas. Você pode 
 * implementar funções auxiliares além das fornecidas, para isso,
 * coloque o cabeçário da função no arquivo .h e sua implementação 
 * aqui, no arquivo .c. Não altere assinaturas de funções, caso 
 * contrário seu código receberá nota 0,0 (zero).
 */

//Estrutura de lista
struct lista {
	tipo 		*dados;		//Vetor que armazena os dados
	int 		capacidade; //Capacidade de armazenamento da lista
 	int 		tamanho;	//Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções

/**
 * @brief Cria e inicializa uma estrutura de lista, retornando seu endereço.
 * 
 * @details Aloca memória para uma estrutura de lista e retorna seu endereço
 * (ponteiro). Inicialmente a lista criada é vazia, ou seja, não contém 
 * nenhum elemento. Caso não seja possível realizar a alocação a fun-
 * ção deve retornar NULL.
 * 
 * @param capacidade define a capacidade de armazenamento da lista. Uma vez
 * definida a capacidade da lista é imutável (fixa).
 * @return Ponteiro para a lista inicializada. Caso falhe, retorna NULL.
 */
lista_t*	lista_cria				(int capacidade){
		lista_t *t = (lista_t*)malloc(sizeof(lista_t));
		if(t == NULL) return NULL;
		t -> dados = (tipo*) malloc(sizeof(tipo)*capacidade);
		 if (t->dados == NULL) {
			free(t);
			return NULL;
		}
		t->capacidade = capacidade;
		t->tamanho = 0;
		return t;
}

/**
 * @brief Destrói uma lista e seta seu ponteiro para NULL.
 *
 * @details Destrói uma lista, desalocando sua memória. Ao final, o 
 * ponteiro da lista é setado para nulo (NULL) --- por este motivo o pon-
 * teiro da lista é passado por referência para a função (ponteiro duplo).
 * 
 * @param l Ponteiro para o ponteiro da lista (l). Ou seja, a lista passada 
 * por referência.
 */
void		lista_destroi			(lista_t **l){
	if(!l||!(*l)) return;
	if((*l) -> dados != NULL){
		free((*l) -> dados);
	}
	free(*l);
	*l = NULL;
}

/**
 * @brief Verifica se a lista está propriamente inicializada.
 * @details Verifica se a lista é diferente de NULL, ou seja, se foi 
 * propriamente inicializada. Verifica também se seu vetor interno é não 
 * nulo (está propriamente inicializado).
 * 
 * @param l A lista a ser verificada
 * @return Retorna 1 se a lista não é nula, e 0 se a lista for nula.
 */
int 		lista_inicializada		(lista_t *l){
	if(l==NULL) return 0;
	if(l->dados ==NULL) return 0;
	return 1;
}


/**
 * @brief Retorna o tamanho da lista (seu número de elementos).
 * @details Retorna a quantidade de elementos armazenados na lista.
 * 
 * @param l A lista para qual o tamanho deve ser determinado.
 * @return Retorna o tamanho da lista, caso ela seja válida. Se a lista 
 * for inválida, retorna -1.
 */
int 		lista_tamanho			(lista_t *l){
	if(l==NULL) return -1;
	return l->tamanho;
}


/**
 * @brief Retorna a capacidade da lista.
 * @details Retorna a capacidade da lista.
 * 
 * @param l A lista para qual a capacidade deve ser determinada.
 * @return Retorna a capacidade da lista, caso ela seja válida. Se a lista 
 * for inválida, retorna -1.
 */
int 		lista_capacidade			(lista_t *l){
	if(l==NULL) return -1;
	return l->capacidade;
}


/**
 * @brief Determina se a lista está cheia.
 * @details Verifica se uma lista ainda pode receber inserções.
 * 
 * @param l A lista.
 * @return Retorna -1 caso a lista seja inválida (NULL), 0 caso não cheia
 * e 1 caso a lista esteja cheia.
 */
int 		lista_cheia 			(lista_t *l){
	if(l==NULL) return -1;
	if(l->tamanho==l->capacidade) return 1;
	return 0;	
}


/**
 * @brief Obtém o dado armazenado na cabeça da lista
 * @details Obtém, se possível, o dado armazenado na cabeça da lista
 * 
 * @param l A lista. Note que a lista não é alterada na função.
 * @param dado Parâmetro passado por referência que conterá o dado da cabeça
 * 
 * @return Retorna 1, caso seja possível obter o dado da cabeça da lista 
 * que, após a chamada da função estará armazenado em dado. Caso a lista 
 * seja inválida retorna -1. Caso seja vazia, retorna 0. Caso dado seja 
 * nulo retorna -1.
 */
int 		lista_info_cabeca  		(lista_t *l, int *dado){
	//Initial Conditions
	if(l==NULL) return -1;
	if(dado==NULL) return -1;
	if(l->tamanho==0) return 0;
	
	//Requested
	*dado = l->dados[0];
	return 1;	
}

/**
 * @brief Obtém o dado armazenado na cauda da lista
 * @details Obtém, se possível, o dado armazenado na cauda da lista
 * 
 * @param l A lista. Note que a lista não é alterada na função.
 * @param dado Parâmetro passado por referência que conterá o dado da cauda
 * 
 * @return Retorna 1, caso seja possível obter o dado da cauda da lista que, 
 * após a chamada da função estará armazenado em dado. Caso a lista seja 
 * inválida retorna -1. Caso seja vazia, retorna 0. Caso dado seja nulo 
 * retorna -1.
 */
int 		lista_info_cauda 		(lista_t *l, int *dado){
	//Initial Conditions
	if(l==NULL) return -1;
	if(dado ==NULL) return -1;
	if(l->tamanho == 0) return 0;
	
	//Requested
	*dado = l->dados[l->tamanho-1];
	return 1;
}

/**
 * @brief Obtém o dado armazenado em uma posição específica da lista
 * @details Obtém, se possível, o dado armazenado na posição pos da lista
 * 
 * @param l A lista. Note que a lista não é alterada na função.
 * @param dado Parâmetro passado por referência que conterá o dado da cauda
 * @param pos A posição consultada. Posições válidas para consulta são: 
 *            0 <= pos < tamanho
 * 
 * @return Retorna 1, caso seja possível obter o dado da posição pos da 
 * lista que após a chamada da função estará armazenado em dado. Caso a 
 * lista seja inválida retorna -1. Caso seja vazia, retorna 0. Caso a 
 * posição seja inválida, retorna 0. Caso dado seja nulo retorna -1.
 */
int 		lista_info_posicao 		(lista_t *l, int *dado, int pos){
	//Initial Conditions
	if(l==NULL) return -1;
	if(dado ==NULL) return -1;
	if(l->tamanho == 0) return 0;
	if(pos > l->tamanho || pos < 0) return 0;
	
	//Requested
	*dado = l->dados[pos];
	return 1;
}

/**
 * @brief Insere um dado na cabeça da lista, isto é, na sua primeira posição.
 * 
 * @details Insere o dado passado como parâmetro na primeira posição da 
 * lista. A lista deve ser válida. Se a lista estiver cheia a inserção não é 
 * realizada.
 * 
 * @param l A lista na qual o dado deve ser inserido.
 * @param dado O dado que deve ser inserido na lista.
 * 
 * @return Caso seja possível realizar a inserção, a função retorna 1. Caso 
 * a lista seja inválida, a função retorna -1. Caso não seja possível 
 * realizar a inserção, a função deve retornar -1.
 */
int			lista_insere_cabeca		(lista_t *l, tipo dado){
	//Initial Conditions
	if(l==NULL) return -1;
	if(l->tamanho == l->capacidade) return -1;

	for(int i=l->tamanho-1;i>=0; i--){//Move all one house up
		l->dados[i+1] = l->dados[i];
	}

	l->dados[0] = dado;
	l->tamanho++;
	return 1;
}

/**
 * @brief Insere um dado na cauda da lista, isto é, na sua última posição.
 * @details Insere o dado passado como parâmetro na última posição da lista.
 * A lista deve ser válida. Se não houver capacidade disponível a inserção
 * não é realizada.
 * 
 * @param l A lista na qual o dado deve ser inserido.
 * @param dado O dado que deve ser inserido na lista.
 * 
 * @return Caso seja possível realizar a inserção, a função retorna 1. Caso 
 * a lista seja inválida, a função retorna -1. Caso não seja possível 
 * realizar a inserção por falta de capacidade, a função deve retornar -1.
 */
int			lista_insere_cauda		(lista_t *l, tipo dado){
	//Initial Conditions
	if(l==NULL) return -1;
	if(lista_cheia(l)) return -1;
	
	l->dados[l->tamanho] = dado;
	l->tamanho++;
	return 1;
}

/**
 * @brief Insere um dado em uma posição específica da lista.
 * 
 * @details Insere um dado em uma posição específica da lista. Posições da 
 * lista são numeradas a partir de zero. Isto é, o primeiro elemento está na 
 * posição zero e o último na posição n-1, onde n é o número de 
 * elementos (tamanho).
 * 
 * @param l A lista na qual o dado deve ser inserido. A lista deve estar pro-
 * priamente inicializada.
 * @param dado O dado que deve ser inserido na lista.
 * @param pos A posição na qual o dado deve ser inserido. Posições válidas 
 * para inserção são: 0 <= pos <= tamanho
 * 
 * @return Caso seja possível realizar a inserção, a função retorna 1. Caso 
 * a lista seja inválida/cheia, a função retorna -1. Se a posição passada 
 * como parâmetro for inválida, a função retorna 0. 
 */
int			lista_insere_posicao	(lista_t *l, tipo dado, int pos){
	//Initial Conditions
	if(!l) return -1;
	if(lista_cheia(l)) return -1;
	if(pos<0 || pos > l->tamanho) return 0;
	
	for(int i=l->tamanho-1;i>=pos; i--){//Move all one house up
		l->dados[i+1] = l->dados[i];
	}
	l->dados[pos] = dado;
	l->tamanho++;
	return 1;
}

/**
 * @brief Remove o elemento da cabeça da lista (primeira posição)
 * @details Retorna o elemento da primeira posição da lista. O dado contido
 * na primeira posição é armazenado no parâmetro dado, que é passado por 
 * referência para a função.
 * 
 * @param l A lista na qual a remoção deve ser realizada.
 * @param dado Parâmetro passado por referência para armazenar o dado 
 * removido.
 * 
 * @return Retorna 1 caso seja possível realizar a remoção. Caso a lista 
 * seja vazia, a função deve retornar 0. Se a lista não estiver 
 * inicializada, a função retorna -1. Os valores retornados nos dois últimos 
 * casos servem para indicar a quem chamou a função que o valor em dado não 
 * corresponde a um valor removido da lista, ou seja, ele continua 
 * inalterado. Caso dado seja nulo retorna -1.
 */
int			lista_remove_cabeca		(lista_t *l, tipo *dado){
	if(l==NULL) return -1;
	if(dado==NULL) return -1;
	if(lista_inicializada(l)==0) return -1;
	if(l->tamanho==0) return 0;
	
	*dado = l->dados[0];
	
	for(int i=0;i<l->tamanho-1; i++){//Move all one house down
		l->dados[i] = l->dados[i+1];
	}
	l->tamanho--;
	return 1;
}

/**
 * @brief Remove o elemento da cauda da lista (última posição)
 * @details Retorna o elemento da última posição da lista. O dado contido na 
 * última posição é armazenado no parâmetro dado, que é passado por 
 * referência para a função.
 * 
 * @param l A lista na qual a remoção deve ser realizada.
 * @param dado Parâmetro passado por referência para armazenar o dado 
 * removido.
 * 
 * @return Retorna 1 caso seja possível realizar a remoção. Caso a lista 
 * seja vazia, a função deve retornar 0. Se a lista não estiver 
 * inicializada, a função retorna -1. Os valores retornados nos dois últimos 
 * casos servem para indicar a quem chamou a função que o valor em dado não 
 * corresponde a um valor removido da lista, ou seja, ele continua 
 * inalterado. Caso dado seja nulo retorna -1.
 */
int			lista_remove_cauda		(lista_t *l, tipo *dado){
	if(l==NULL) return -1;
	if(lista_inicializada(l)==0) return -1;
	if(dado==NULL) return -1;
	if(l->tamanho==0) return 0;
	
	*dado = l->dados[l->tamanho-1];
	l->tamanho--;
	return 1;
}
/**
 * @brief Remove o dado de uma determinada posição da lista
 * @details Remove o dado de uma determinada posição da lista (a posição 
 * deve ser válida). O dado removido é armazenado no parâmetro dado, passado 
 * por referência. A remoção pode não ocorrer, caso a lista não seja válida 
 * ou esteja vazia.
 * 
 * @param l A lista da qual o dado deve ser removido
 * @param dado Parâmetro passado por referência. Caso a remoção ocorra, irá 
 * conter o dado removido da posição solicitada.
 * @pos A posição que que deve ser removida da lista. Posições válidas são 
 * aquelas que satisfazem: 0 <= pos < tamanho
 * 
 * @return Retorna 1 caso seja possível realizar a remoção. Caso a lista 
 * seja vazia, a função deve retornar 0. Se a lista não estiver 
 * inicializada, a função retorna -1. Se a posição passada como parâmetro 
 * for inválida, a função retorna 0. Os valores retornados nos dois últimos 
 * casos servem para indicar a quem chamou a função que o valor em dado não 
 * é corresponde a um valor removido da lista, ou seja, ele continua 
 * inalterado. Caso dado seja nulo retorna -1.
 */
int			lista_remove_posicao	(lista_t *l, tipo *dado, int pos){
	//Initial Conditions
	if(!l) return -1;
	if(dado == NULL) return -1;
	if(l->tamanho==0) return -0;
	if(pos<0 || pos >= l->tamanho) return 0;
	
	 *dado = l->dados[pos]; 
	
	for(int i = pos;i<l->tamanho-1; i++){//Move all one house up
		l->dados[i] = l->dados[i+1];
	}

	l->tamanho--;
	return 1;
}

/**
 * @brief Remove a primeira ocorrência de dado na lisa l
 * @details Remove somente a primeira ocorrência de dado na lista l.
 * 
 * @param l A lista onde a remoção deve ocorrer.
 * @param dado O dado que deve ter a primeira ocorrência removida.
 * 
 * @return Retorna a posição da qual o dado foi removido. Caso a lista seja 
 * inválida, a função retorna -1. Caso o dado não faça parte da lista, a 
 * função retorna -2.
 */
int 		lista_remove_primeira	(lista_t *l, tipo dado){
	if(!l) return -1;
	tipo var = 0;
	tipo *dado_n_valido = &var;
	for(int i = 0;i<l->tamanho;i++){
		if(dado == l->dados[i]){
			lista_remove_posicao(l,dado_n_valido,i);
			return i;
		}
	}
	return -2;
	
}

/**
 * @brief Remove todas as ocorrências do valor dado na lista l
 * @details Todas ocorrências de dado são removidas da lista, caso seja 
 * possível
 *  
 * @param l A lista onde as remoções devem ocorrer.
 * @param dado O dado que deve ser removido da lista.
 * 
 * @return Caso seja possível fazer as remoções, retorna o número de 
 * remoções realizadas. Caso a lista seja inválida, retorna -1.
 */
int 		lista_remove_todas		(lista_t *l, tipo dado){
	if(!l) return -1;
	
	tipo var = 0;
	tipo *dado_n_valido = &var;
	
	int rep=0;
	
	for(int i = 0;i<l->tamanho;i++){
		if(dado == l->dados[i]){
			lista_remove_posicao(l,dado_n_valido,i);
			rep++;
		}
	}
	return rep;
}

/**
 * @brief Busca um dado na lista l
 * @details Busca por um dado em uma lista l, retornando sua posição.
 * 
 * @param l A lista onde a busca deve ser feita.
 * @param dado O dado a ser buscado.
 * 
 * @return Caso encontre, retorna sua posição na lista. Caso a lista seja 
 * inválida, vazia ou não seja possível encontrar o elemento, a função 
 * retorna -1. Se o elemento aparece mais de uma vez, retorna a posição da
 * sua primeira ocorrência.
 */
int 		lista_busca_info		(lista_t *l, tipo dado){
	if(!l) return -1;
	if(l->tamanho ==0) return -1;
	
	for(int i=0;i<l->tamanho;i++){
		if(l->dados[i] == dado)
			return i;
	}
	return -1;
}

/**
 * @brief Determina a frequência de um dado na lista
 * @details Determina quantas vezes dado aparece na lista l.
 * 
 * @param l A lista
 * @param dado O dado que deve ter a frequência determinada.
 * 
 * @return A frequência com que dado aparece na lista. Retorna -1 caso a 
 * lista seja inválida.
 */
int 		lista_frequencia_info	(lista_t *l, tipo dado){
	if(!l) return -1;
	
	int rep=0;
	
	for(int i=0;i<l->tamanho;i++){
		if(l->dados[i] == dado)
			rep++;
	}
	return rep;
}

/**
 * @brief Verifica se uma lista está ordenada em ordem crescente de valores
 * @details Verifica se uma lista está em ordem crescente de valores. A 
 * lista deve ser válida. Uma lista vazia está ordenada.
 * 
 * @param l A lista que deve ser verificada
 * @return Se a lista estiver em ordem, retorna 1. Caso esteja fora de 
 * ordem, a função retorna 0. Para uma lista inválida, retorna -1.
 */
int			lista_ordenada 			(lista_t *l){
	if(!l) return -1;
	
	for (int i=0;i<l->tamanho-1;i++){
		if(l->dados[i] > l->dados[i+1]) return 0;
	}
	return 1;
}

/**
 * @brief Insere um elemento de forma ordenada em uma lista. 
 * 
 * @details Insere um elemento de forma ordenada na lista. A função assume 
 * que a lista está ordenada. Isto é, a função não deve verificar 
 * internamente se a lista está ou não ordenada. Este cuidado deve ser 
 * tomado por quem chama a função.
 * 
 * @param l A lista na qual a inserção deve ocorrer
 * @param dado O dado que deve ser inserido de forma ordenada
 * 
 * @return Retorna 1 caso seja possível realizar a inserção e -1 caso 
 * contrário.
 */
int 		lista_insere_ordenado	(lista_t *l, tipo dado){//FALHOU
	if(!l) return -1;
	if(l->tamanho == l->capacidade) return -1;
	int i ;
	for(i =0; i<l->tamanho; i++){
		if(dado < l->dados[i]) {
			lista_insere_posicao(l,dado,i);
			return 1;
		}
	}
	if (i == l->tamanho) {
        lista_insere_posicao(l, dado, i);
        return 1;
    }
	return -1;
}

/**
 * @brief Compara as listas l1 e l2 quanto à sua igualdade.
 * @details Compara se duas listas são iguais. Duas listas são iguais se e 
 * somente se possuem o mesmo número de elementos e seus elementos são 
 * iguais, para cada uma de suas posições.
 * 
 * @param l1 A lista l1
 * @param l2 A lista l2
 * 
 * @return Retorna: 1 caso as listas sejam iguais, 0 cao sejam diferentes. 
 * Duas listas não inicializadas são iguais.
 */
int 		lista_compara(lista_t *l1, lista_t *l2){
	//if(!l1 || !l2) return -1;
	if(lista_inicializada(l1) == 0 && lista_inicializada(l2)==0) return 1;
	if(lista_inicializada(l1) == 0 || lista_inicializada(l2)==0) return 0;
	
	if(l1->tamanho == l2->tamanho){
		for(int i=0;i<l1->tamanho;i++){
			if(l2->dados[i] != l1->dados[i]) return 0;
		}
		return 1;
	}
	return 0;
	
}

/**
 * @brief Reverte a ordem dos elementos de uma lista
 * @details Reverte a ordem dos elementos de uma lista. Ao final, a lista 
 * estará revertida. 
 * Exemplo: l antes <1, 4, 666, 7>; l depois <7, 666, 4, 1>.
 * 
 * @param l A lista a ser revertida.
 * @return Retorna 1 caso seja possível fazer a reversão. Caso l seja 
 * inválida retorna -1.
 */

int 		lista_reverte(lista_t *l){
	if(!l) return -1;
	tipo temp = 0;
	
	for(int i=0; i<(l->tamanho/2);i++){
		temp = l->dados[i];
		l->dados[i] = l->dados[l->tamanho-1-i];
		l->dados[l->tamanho-1-i] = temp;
	}
	return 1;
}

/**
 * @brief Cria uma cópia da lista l
 * @details Cria uma nova lista que conterá uma cópia da lista l. A lista 
 * cópia é retornada pela função. A lista original não deve ser alterada. Ou 
 * seja, l continuará válida após a chamada da função. 
 * 
 * @param l A lista a ser copiada.
 * @return Uma nova lista, que é uma cópia de l. Retorna NULL caso não seja 
 * possível fazer a cópia.
 */

lista_t*	lista_cria_copia(lista_t *l){
	if(!l) return NULL;
	lista_t* nova = lista_cria(l->capacidade);
	if(!nova) return NULL;
	nova->tamanho = l->tamanho;
	for(int i = 0; i<l->tamanho;i++){
		nova->dados[i] = l->dados[i];
	}
	return nova;
}



int main(){
	/*lista_t *t = lista_cria(10);
	int d;
	
	for(int j=0;j<9;j++){
		d = lista_insere_cabeca(t,j+1);
		for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
		}
		printf(" %d", d);
		printf("\n");
	}
	
	printf("Test 1 -> ");
	int y = lista_insere_posicao(t,5,9);
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf("  %d\n", y);
	
	int value = 3;  // Integer value you want to store
	int *ptr = &value;
	lista_t *j = NULL;
	int z = lista_remove_cabeca(j,ptr);
	
	for(int i= 0; i<t->capacidade;i++){
			printf("%d ", t->dados[i]);
	}
	printf("%d",z);/~
	
	printf("Test 1.1 -> ");
	int h = lista_remove_todas(t,5);
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf("  %d\n", h);
	
	
	printf("Test 2 -> ");
	int z = lista_remove_cauda(t,ptr);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",z);
	
	printf("Test 3 -> ");
	z = lista_remove_posicao(t,ptr,5);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",z);
	
	printf("Test 4 -> ");
	z = lista_remove_primeira(t,7);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",z);
	
	printf("Test 5-> ");
	d = lista_busca_info(t,10);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",d);
	
	printf("Test 5-> ");
	lista_insere_cabeca(t,6);
	lista_insere_cauda(t,6);
	d = lista_frequencia_info(t,6);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",d);
	
	printf("Test 6-> ");
	lista_insere_cabeca(t,6);
	lista_insere_cauda(t,6);
	d = lista_ordenada(t);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",d);
	
	t->tamanho=0;
	for(int j=0;j<10;j++){
		d = lista_insere_cauda(t,j+1);
	}
	printf("------Nova lista (0-10) ordenada------\n");
	printf("Test ordenada-> ");
	
	d = lista_ordenada(t);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",d);
	
	printf("Test insere_ordenado-> ");
	
	d = lista_insere_ordenado(t,8);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf(" %d\n",d);
	
	printf("Test compara-> ");
	
	lista_t* t2 = lista_cria(10);
	
	for(int j=0;j<t2->capacidade;j++){
		d = lista_insere_cauda(t2,j+2);
	}
	
	d = lista_compara(t,t2);
	
	for(int i= 0; i<t->tamanho;i++){
			printf("%d ", t->dados[i]);
	}
	printf("\n");
	for(int i= 0; i<t2->tamanho;i++){
			printf("%d ", t2->dados[i]);
	}
	printf(" %d\n",d);
	*/
	int d;
	lista_t* t2 = lista_cria(10);
	
	for(int j=0;j<t2->capacidade-3;j++){
		d = lista_insere_cauda(t2,j+1);
	}
	for(int i= 0; i<t2->capacidade;i++){
			printf("%d ", t2->dados[i]);
	}
	printf("\n");
	
	printf("Test insere_ordenado-> ");
	
	d = lista_insere_ordenado(t2,8);
	
	for(int i= 0; i<t2->tamanho;i++){
			printf("%d ", t2->dados[i]);
	}
	printf(" %d\n",d);
	/*
	printf("Test reverte-> ");
	
	d = lista_reverte(t2);
	for(int i= 0; i<t2->capacidade;i++){
			printf("%d ", t2->dados[i]);
	}
	printf(" %d\n",d);
	
	printf("Test copiada-> ");
	
	lista_t* n = lista_cria_copia(t2);
	
	for(int i= 0; i<n->tamanho;i++){
			printf("%d ", n->dados[i]);
	}
	*/
	free(t2);
	//free(n);
	
	
	return 0;
}