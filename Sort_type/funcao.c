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

    for(unsigned int i = 0;i<t-1;i++){
        for(unsigned int j= 0; j<t-i-1;j++){
            if(v[j+1]<v[j]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    return 1;
}