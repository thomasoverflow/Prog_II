#include "pilha.h"


int main(){
    char comando1[10], comando2[10];
    int valor, para,n = 10;

    branch_t *l = cria_branch(n);
    for(int i = 0;i<n;i++){
        for(int j=0;j<l->vetores[i]->tamanho;j++) {
            printf("%d ", l->vetores[i]->vetor[j]);
        }
        printf("\n");
    }

    /*scanf("%d", &n);
    scanf("%9s", comando1);
    while(strcmp(comando1,"sair") != 0) {
        scanf("%d %9s %d", &valor, comando2, &para);
        if(strcmp(comando1,"mova")==0){
            //RUN PROGRAM TO MOVER
        }else{
            //RUN PROGRAM TO EMPILHAR
        }

    }
    */
    destroi_branch(&l);
    return 0;
}