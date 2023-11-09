#include "stdio.h"
#include "stdlib.h" 
#include "string.h"


int is_palindromo(char *vector, int point, int size){	 
    if (point>= size/ 2)
        return 1;
    else if (vector[point] != vector[size - point - 1])
        return 0;
    else
        return is_palindromo(vector, point + 1,size);
}

int main(){
	char *palavra = "tenet";
	int size = strlen(palavra);
	if(is_palindromo(palavra, 0,size)){
		printf("É um palindromo\n");
	}else{
		printf("Não é palindromo\n");
	}
	return 0;
}