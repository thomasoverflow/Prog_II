#include <stdio.h>
#include <stdlib.h>
#include "nba_stats.h"

int main() {
    //char time = "MIA";
	printf("Use e abuse tos testes.\n");
	//printf("%d",le_cabecario("jogadores.dat"));
	int i = 0;
	jogador_t *test = le_jogadores("players.dat",&i);
	printf("Numero de jogadores %d\n",i);
    printf("Posição %d",statt_posicao(test,i,"CHI","PF"));
	return 0;
}

