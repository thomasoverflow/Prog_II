
#ifndef PROG_II_PILHA_H
#define PROG_II_PILHA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct vector{
    int *vetor;
    int tamanho;
    int capacidade;
};

struct branch{
    struct vector **vetores;
    int tamanho;
};

typedef struct branch branch_t;
typedef struct vector vector_t;

/**
 * @brief Cria um braço que armazenará todas as pilhas.
 * @details Verifica se o número é válido.
 *
 * @param n -> O número de pilhas que haverá
 * @return Retorna NULL -> se o número for inválido\n
 * Retorna NULL -> se não foi possivel alocar memória\n
 * Retorna ponteiro do braço -> se tudo estiver certo.
 */
branch_t* cria_branch(int n);

/**
 * @brief Destroiu um braço que armazenará todas as pilhas.
 * @details Verifica se a lista é válida.
 *
 * @param l -> Endereço da branch.
 */
void destroi_branch(branch_t **l);

vector_t *cria_vector(int capacidade);

void destroi_vector(vector_t **v);

#endif //PROG_II_PILHA_H
