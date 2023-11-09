#include "stdio.h"
#include "stdlib.h" 

int return_sum_until(int n){
	if(n == 0) return 0; //Deal with input problem when trying to sum "nothing with nothing"
	if(n == 1) return 1;
	return n + return_sum_until(n-1);
}

int  main(){
	int lim = 20; //Change to the desired ceiling
	printf("%d\n",return_sum_until(lim));
	return 0;
}
