#include "pilha.h"


int main(){
    char comando1[10], comando2[10];
    int valor, para,n,i=0,j=0;

    branch_t *l = cria_branch(10);
    find_data(l,10,&i,&j);

    scanf("%d", &n);
    scanf("%9s", comando1);
    while(strcmp(comando1,"sair") != 0) {
        scanf("%d %9s %d", &valor, comando2, &para);
        if(strcmp(comando1,"mova")==0){
            //RUN PROGRAM TO MOVER
        }else{
            //RUN PROGRAM TO EMPILHAR
        }

    }

    destroi_branch(&l);
    return 0;
}