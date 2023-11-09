#include "stdio.h"
#include "stdlib.h" 

int print_sequel(int inf,int sup,int interval){
	if(interval == 0) return -1;  //Return -1 if the interval is invalid 
	if(inf == sup || sup-inf < interval){
		printf("%d",inf);
		return 0; 				  //Return 0 if the interval is valid
	}
	printf("%d ",inf);
	print_sequel(inf+interval, sup,interval);
}

int main(){
	int inf = -10, sup = 81;
	print_sequel(inf,sup,0);
	return 0;
}
