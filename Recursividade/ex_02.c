#include "stdlib.h"
#include "stdio.h"

int print_interval(int inf,int sup){
	if(inf == sup){
		printf("%d",inf);
		return 0;
	}
	printf("%d ",inf);
	print_interval(inf+1, sup);
}

int main(){
	int inf = 1, sup = 80;
	print_interval(inf,sup);
	return 0;
}
