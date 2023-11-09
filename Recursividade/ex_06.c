#include "stdio.h"
#include "stdlib.h" 

int sum_vector(int *vector, int size){
	if(size==0) return 0;
	return vector[size-1] + sum_vector(vector,size-1);
	
}

int main(){
	int vec[] = {8,9,7,5};
	int size = 4;
	printf("%d",sum_vector(vec,size));
	return 0;	
}