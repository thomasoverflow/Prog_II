#include "stdio.h"
#include "stdlib.h" 

int power(int n, int exp){
	if(exp==0) return 1;
	return n * power(n, exp-1);
}

int main(){
	int base = 15, exp = 2; //Change for de disered values
	printf("%d\n",power(base,exp));
	return 0;	
}
