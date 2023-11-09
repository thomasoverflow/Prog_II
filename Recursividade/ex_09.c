#include "stdio.h"
#include "stdlib.h" 

/*Faça uma função recursiva que recebe um vetor como parâmetro e reverte a ordem de seus 
	elementos, sem usar outro vetor. Você só pode usar uma variável temporária adicional */

int reverse_vector(int * vector, int size){
	if(size <= 1) return 0;
	int aux =  *(vector + size -1);
	 *(vector + size -1) = *(vector);
	 *(vector) = aux;
	 reverse_vector(vector+1,size-2);
}

int main(){
	int vec[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(vec)/sizeof(vec[0]);
	reverse_vector(vec, size);
	return 0;
}