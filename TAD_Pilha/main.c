#include "pilha.h"


int main(){
    char comando1[10]="oi", comando2[10];
    int valor, para,n, i, j;
    vector_t *pilhaa, *pilhab;
    int elem;



    scanf("%d", &n);
    branch_t *l = cria_branch(n);
    for(int y = 0;y<l->tamanho;y++){
        for(int x=0;x<l->vetores[y]->tamanho;x++){
            printf("%d ",l->vetores[y]->vetor[x]);
        }
        printf("\n");
    }
    //scanf("%9s", comando1);
    while(strcmp(comando1,"sair") != 0) {
        scanf("%9s %d %9s %d", comando1, &valor, comando2, &para);
        if(strcmp(comando1,"mova")==0){
            //RUN PROGRAM TO MOVER
            if(strcmp(comando2,"sobre")==0) {
                encontra(l,&pilhaa,&i,valor);
                encontra(l,&pilhab,&j,para);

                while (pilhaa->tamanho-1 != i) {
                    desempilha(pilhaa, &elem);
                    empilha(l->vetores[elem], &elem);
                }//DESEMPILHA A
                while (pilhab->tamanho-1 != j) {
                    desempilha(pilhab, &elem);
                    empilha(l->vetores[elem], &elem);
                }//DESEMPILHA B

                empilha(pilhab,&pilhaa->vetor[i]);
                desempilha(pilhaa,&elem);

            }
            if(strcmp(comando2,"topo")==0){
            }//IMPLEMENTAR
        }else{
            //RUN PROGRAM TO EMPILHAR
        }
        for(int y = 0;y<l->tamanho;y++){
            for(int x=0;x<l->vetores[y]->tamanho;x++){
                printf("%d ",l->vetores[y]->vetor[x]);
            }
            printf("\n");
        }

    }

    destroi_branch(&l);
    return 0;
}