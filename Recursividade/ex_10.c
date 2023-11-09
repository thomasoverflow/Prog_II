#include "stdio.h"
#include "stdlib.h" 

//Faça uma função recursiva que multiplique dois números. Use somente a operação de soma.

int multiplica(int n, int m){
	if(m<=0) return 0;
	return n+ multiplica(n,m-1);
}

int main(){
	int num1 = 4, num2 = 6;
	printf("%d",multiplica(num1,num2));
	return 0;
}