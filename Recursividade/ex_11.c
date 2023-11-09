#include "stdio.h"
#include "stdlib.h" 
int mdc(int n, int m){
	if(n%m ==0) return m;
	return mdc(m,n%m);
}

int main(){
	int x = 7 ,y = 10;
	printf("%d",mdc(x,y));
	return 0;
}