#include "stdio.h"
#include "stdlib.h" 
#include "string.h"

int fib(int n){
	if (n<=1) return n;
	return fib(n-1) + fib(n-2);
}

int main(){
	int num = 10;
	printf("%d",fib(num));
	return 0;
}