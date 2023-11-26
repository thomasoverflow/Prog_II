#include "funcao.h"
#include <ctype.h>
#include <stdlib.h>

//Implemente suas funcoes aqui

/* Ordena
 *		Implementa um algoritmo de ordenacao qualquer (voce escolhe).
 *			Retorna 1, caso seja possivel ordenar o vetor
 *			Retorna 0, caso o vetor (v == NULL) ou tamanho seja invalido (t == 0)
 *		Ao final o vetor v, de tamanho t, estara ordenado.
 */
int ordena(int *v, unsigned int t){
    if(!v) return 0;
    if(t==0) return 0;

    int temp;

    for (int i =1; i<t; i++){
        temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > temp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }
    return 1;
}

int main(){
    int v[6] = {0,5,7,4,9,10};

    int k = ordena(v,6);

    return 0;
}