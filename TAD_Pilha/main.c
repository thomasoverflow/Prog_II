#include "pilha.h"


int main(){
    char comando1[10], comando2[10];
    int valor, para,n;
    scanf("%d", &n);
    scanf("%9s", comando1);
    while(strcmp(comando1,"sair") != 0) {
        scanf("%d %9s %d", &valor, comando2, &para);


        branch_t *l = cria_branch(n);
        for (int i = 0; i < l->tamanho; i++) {
            l->vetores[0][i] = i + 2;
        }

        for (int i = 0; i < l->tamanho; i++) {
            printf("%d ", l->vetores[0][i]);
        }
        printf("%d", l->tamanho);
        scanf("%9s", comando1);
    }
    //destroi_branch(&l);
    return 0;
}