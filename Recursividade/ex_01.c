#include <stdlib.h>
#include <stdio.h>

int fatorial(unsigned int n){
	if(n==1 || n==0) return 1;
	return n*fatorial(n-1);
}

int main(){
	for(int i=0;i<15;i++){
		printf("%d\n",fatorial(i));
	}
	return 0;
}
