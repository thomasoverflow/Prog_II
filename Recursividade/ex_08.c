#include "stdio.h"
#include "stdlib.h" 

void print_direct(int *vetor, int size){ //Operation is done using pointers for reduse the need for a auxiliary value
	if(size > 0) {
		printf("%d\n", *(vetor+size-1));
		print_direct(vetor,size-1);
	}
}

int main(){
	int vet[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(vet)/sizeof(vet[0]); //Calculate the total size in bytes of the vector and dividing for the size of a interger(datatype of number in vector)
	print_direct(vet,size);
	return 0;
}