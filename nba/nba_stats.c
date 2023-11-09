#include "nba_stats.h"

//Coloque aqui a implementação das funções.

/**
 * @brief 	Leitura do cabeçario do arquivo
 * @details Lê o cabeçario de arquivo, ou seja, o número inteiro que especifica o número
 * 			de jogadores total que é armazenado no arquivo
 *
 * @param nome 	Uma string contendo o nome do arquivo
 * @return 		Retorna -1 se a string for nula (1); 0 se o arquivo não existe (2); O número de
 * 				jogadores contindo no arquivo, se conseguir fazer a leitura
 */
int 		le_cabecario				(char *nome){//DONE
    if(!nome) return -1; //Look for null string (1)
    FILE *arq = fopen("jogadores.dat","r"); //Try open file, if succeful -> make arq point to data, else return null
    if(arq==NULL) return 0; //Check for condition (2)

    int num= 0;
    fseek(arq,0,0); //Set head of file pointer to begin (just for safety) :,)
    fread(&num, sizeof(int), 1, arq);
    fclose(arq);
    return num;
}

/**
 * @brief   Faz a leitura dos jogadores armazenados no arquivo
 * @details Lê os jogadores armazenados no arquivo. A função cria um vetor do dinâmico
 *          onde os jogadores lidos são armazenados. Ao final, o ponteiro deste vetor
 *          é retornado pela função
 *
 * @param nome  	 O nome do arquivo a partir de onde a leitura deve ser feita
 * @param njogadores Parâmetro passado por referência para armazenar o número de jogadores
 *
 * @return 			 Se nome ou njogadores forem nulos, a função irá retornar NULL. Se o
 * 					 nome do arquivo é válido, mas o arquivo não existe, a função retorna
 * 					 NULL. A função retorna um vetor alocado dinamicamente que contém as
 * 					 informações dos jogadores, lidas do arquivo e seta njogadores
 */
jogador_t* 	le_jogadores				(char *nome, int *njogadores){//DONE....I think...
    *njogadores = le_cabecario(nome);

    if(nome==NULL||njogadores==NULL) return NULL;
    FILE *arq = fopen(nome,"r");
    if(arq==NULL) return NULL;

    fseek(arq,1*sizeof(int),SEEK_SET);
    jogador_t *data =(jogador_t*)malloc(sizeof(jogador_t)*(*njogadores));

    fread(data,sizeof(jogador_t),*njogadores,arq);
    fclose(arq);
    return data;
}

/**
 * @brief   Estatísticas referentes ao maior número de cestas
 * @details Esta função retorna o índice do jogador que possui o maior número de
 *          arremessos de um determinado tipo
 *
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de arremesso ao qual a estatística se refere, conforme abaixo:
 * 					 '2' : considerar arremessos de 2 pontos (a2)
 * 					 '3' : considerar arremessos de 3 pontos (a3)
 * 					 'T' : considerar os valores totais      (aT)
 * 					 'L' : considerar lances livres          (aL)
 *
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos,
 * 					 retorna -2. Retorna o índice do jogador que mais fez arremessos do tipo
 * 					 especificado, se os parâmetros estiverem corretamente especificados.
 * 					 Caso haja empates, retorna o menor índice que satisfaz a condição.
 */
int 		statj_mais_arremessos		(jogador_t *jogadores, int njogadores, char tipo){//DONE;UNTESTED
    if(jogadores==NULL) return -1;
    if(tipo!='2'&&tipo!='3'&&tipo!='T'&&tipo!='L') return -2;

    int mjr_index = 0;
    int mjr;

    if(tipo == '2'){
        mjr = jogadores[0].a2.arremessos;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].a2.arremessos){
                mjr = jogadores[i].a2.arremessos;
                mjr_index = i;
            }
        }
    }

    if(tipo == '3'){
        mjr = jogadores[0].a3.arremessos;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].a3.arremessos){
                mjr = jogadores[i].a3.arremessos;
                mjr_index = i;
            }
        }
    }

    if(tipo == 'T'){
        mjr = jogadores[0].aT.arremessos;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].aT.arremessos){
                mjr = jogadores[i].aT.arremessos;
                mjr_index = i;
            }
        }
    }

    if(tipo == 'L'){
        mjr = jogadores[0].aL.arremessos;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].aL.arremessos){
                mjr = jogadores[i].aL.arremessos;
                mjr_index = i;
            }
        }
    }
    return mjr_index;
}


/**
 * @brief   Estatísticas referentes ao maior número de cestas
 * @details Esta função retorna o índice do jogador que possui o maior número de
 *          cestas de um determinado tipo
 *
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de cestas ao qual a estatística se refere, conforme abaixo:
 * 					 '2' : considerar cestas de 2 pontos     (a2)
 * 					 '3' : considerar cestas de 3 pontos     (a3)
 * 					 'T' : considerar os valores totais      (aT)
 * 					 'L' : considerar lances livres          (aL)
 *
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos,
 * 					 retorna -2. Retorna o índice do jogador que mais fez cestas (tipo) se
 * 					 os parâmetros estiverem corretamente especificados. Caso haja empa-
 * 					 tes, retorna o menor índice que satisfaz a condição.
 */
int 		statj_mais_cestas			(jogador_t *jogadores, int njogadores, char tipo){//DONE;UNSTESTED


    if(jogadores==NULL) return -1;
    if(tipo!='2'&&tipo!='3'&&tipo!='T'&&tipo!='L') return -2;

    int mjr_index = 0;
    int mjr;

    if(tipo == '2'){
        mjr = jogadores[0].a2.cestas;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].a2.cestas){
                mjr = jogadores[i].a2.cestas;
                mjr_index = i;
            }
        }
    }

    if(tipo == '3'){
        mjr = jogadores[0].a3.cestas;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].a3.cestas){
                mjr = jogadores[i].a3.cestas;
                mjr_index = i;
            }
        }
    }

    if(tipo == 'T'){
        mjr = jogadores[0].aT.cestas;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].aT.cestas){
                mjr = jogadores[i].aT.cestas;
                mjr_index = i;
            }
        }
    }

    if(tipo == 'L'){
        mjr = jogadores[0].aL.cestas;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].aL.cestas){
                mjr = jogadores[i].aL.cestas;
                mjr_index = i;
            }
        }
    }
    return mjr_index;
}

/**
 * @brief   Estatísticas referentes ao melhor percentual de cestas/arremessos
 * @details Esta função retorna o índice do jogador que possui o melhor percentual
 * 			cestas/arremessos
 *
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de percentual ao qual a estatística se refere, conforme abaixo:
 * 					 '2' : considerar percentual de 2 pontos      (a2)
 * 					 '3' : considerar percentual de 3 pontos      (a3)
 * 					 'T' : considerar percentual total            (aT)
 * 					 'L' : considerar percentual de lances livres (aL)
 *
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos,
 * 					 retorna -2. Retorna o índice do jogador com melhor percentual (tipo) se
 * 					 os parâmetros estiverem corretamente especificados. Caso haja empa-
 * 					 tes, retorna o menor índice que satisfaz a condição.
 */
int 		statj_melhor_percentual		(jogador_t *jogadores, int njogadores, char tipo){//DONE;UNSTESTED
    if(jogadores==NULL) return -1;
    if(tipo!='2'&&tipo!='3'&&tipo!='T'&&tipo!='L') return -2;

    int mjr_index = 0;
    float mjr;

    if(tipo == '2'){
        mjr = jogadores[0].a2.percentual;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].a2.percentual){
                mjr = jogadores[i].a2.percentual;
                mjr_index = i;
            }
        }
    }

    if(tipo == '3'){
        mjr = jogadores[0].a3.percentual;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].a3.percentual){
                mjr = jogadores[i].a3.percentual;
                mjr_index = i;
            }
        }
    }

    if(tipo == 'T'){
        mjr = jogadores[0].aT.percentual;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].aT.percentual){
                mjr = jogadores[i].aT.percentual;
                mjr_index = i;
            }
        }
    }

    if(tipo == 'L'){
        mjr = jogadores[0].aL.percentual;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].aL.percentual){
                mjr = jogadores[i].aL.percentual;
                mjr_index = i;
            }
        }
    }
    return mjr_index;

}

/**
 * @brief   Estatísticas referentes ao número de jogos
 * @details Esta função retorna o jogador com maior ou menor número de jogos, dependendo
 * 	        do tipo específicado
 *
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com maior número de jogos
 * 					 '-' : retorna o índice do jogados com menor número de jogos
 *
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos,
 * 					 retorna -2. Retorna o índice do jogador com maior/menor número de jogos.
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int 		statj_jogos					(jogador_t *jogadores, int njogadores, char tipo){//DONE;UNSTESTED
    if(jogadores==NULL) return -1;
    if(tipo!='+'&&tipo!='-') return -2;

    int mjr_index = 0;
    int mjr;

    if(tipo == '+'){
        mjr = jogadores[0].jogos;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].jogos){
                mjr = jogadores[i].jogos;
                mjr_index = i;
            }
        }
    }

    if(tipo == '-'){
        mjr = jogadores[0].jogos;
        for(int i=1;i<njogadores;i++){
            if(mjr>jogadores[i].jogos){
                mjr = jogadores[i].jogos;
                mjr_index = i;
            }
        }
    }

    return mjr_index;
}

/**
 * @brief   Estatísticas referentes à idade
 * @details Esta função retorna o jogador com maior ou menor idade, dependendo
 * 	        do tipo específicado
 *
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com maior idade
 * 					 '-' : retorna o índice do jogados com menor idade
 *
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos,
 * 					 retorna -2. Retorna o índice do jogador com maior/menor idade.
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int 		statj_idade					(jogador_t *jogadores, int njogadores, char tipo){
    if(jogadores==NULL) return -1;
    if(tipo!='+'&&tipo!='-') return -2;

    int mjr_index = 0;
    int mjr;

    if(tipo == '+'){
        mjr = jogadores[0].idade;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].idade){
                mjr = jogadores[i].idade;
                mjr_index = i;
            }
        }
    }

    if(tipo == '-'){
        mjr = jogadores[0].idade;
        for(int i=1;i<njogadores;i++){
            if(mjr>jogadores[i].idade){
                mjr = jogadores[i].idade;
                mjr_index = i;
            }
        }
    }

    return mjr_index;
}

/**
 * @brief   Estatísticas referentes à minutos jogados
 * @details Esta função retorna o jogador com mais ou menos minutos jogados, dependendo
 * 	        do tipo específicado
 *
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com mais minutos
 * 					 '-' : retorna o índice do jogados com menos minutos
 *
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos,
 * 					 retorna -2. Retorna o índice do jogador com mais/menos minutos.
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int 		statj_minutos				(jogador_t *jogadores, int njogadores, char tipo){
    if(jogadores==NULL) return -1;
    if(tipo!='+'&&tipo!='-') return -2;

    int mjr_index = 0;
    int mjr;

    if(tipo == '+'){
        mjr = jogadores[0].minutos;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].minutos){
                mjr = jogadores[i].minutos;
                mjr_index = i;
            }
        }
    }

    if(tipo == '-'){
        mjr = jogadores[0].minutos;
        for(int i=1;i<njogadores;i++){
            if(mjr>jogadores[i].minutos){
                mjr = jogadores[i].minutos;
                mjr_index = i;
            }
        }
    }

    return mjr_index;

}

/**
 * @brief   Estatísticas referentes à pontos
 * @details Esta função retorna o jogador com mais ou menos pontos, dependendo
 * 	        do tipo específicado
 *
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com mais pontos
 * 					 '-' : retorna o índice do jogados com menos pontos
 *
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos,
 * 					 retorna -2. Retorna o índice do jogador com mais/menos pontos.
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int 		statj_pontos				(jogador_t *jogadores, int njogadores, char tipo){
    if(jogadores==NULL) return -1;
    if(tipo!='+'&&tipo!='-') return -2;

    int mjr_index = 0;
    int mjr;

    if(tipo == '+'){
        mjr = jogadores[0].pontos;
        for(int i=1;i<njogadores;i++){
            if(mjr<jogadores[i].pontos){
                mjr = jogadores[i].pontos;
                mjr_index = i;
            }
        }
    }

    if(tipo == '-'){
        mjr = jogadores[0].pontos;
        for(int i=1;i<njogadores;i++){
            if(mjr>jogadores[i].pontos){
                mjr = jogadores[i].pontos;
                mjr_index = i;
            }
        }
    }

    return mjr_index;
}

/**
 * @brief   Soma de pontos dos jogadores de um time
 * @details Retorna a soma de pontos feita por os jogadores de um time
 *
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @return           Se jogadores ou time forem nulos, retorna -1. Retorna a soma de pontos
 *                   feita pelos jogadores do time especificado. Se o nome do time for in-
 *                   válido (time sem jogadores), retorna 0.
 */
int 		statt_soma_pontos			(jogador_t *jogadores, int njogadores, char* time){//DONE;UNTESTED
    if(jogadores==NULL||time==NULL) return -1;
    float num_time=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].time, time) == 0){
            num_time++;
        }
    }

    if(num_time==0) return 0;

    float sum=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].time, time) == 0){
            sum = sum + jogadores[i].pontos;
        }
    }
    return sum;
}


/**
 * @brief   Média de pontos dos jogadores de um time
 * @details Retorna a média de pontos feita por os jogadores de um time
 *
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @return           Se jogadores ou time forem nulos, retorna -1. Retorna a média de pontos
 *                   feita pelos jogadores do time especificado. Se o nome do time for in-
 *                   válido (time sem jogadores), retorna 0.
 */
float 		statt_media_pontos			(jogador_t *jogadores, int njogadores, char* time){//DONE; UNTESTED
    if(jogadores==NULL||time==NULL) return -1;
    float num_time=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].time, time) == 0){
            num_time++;
        }
    }

    if(num_time==0) return 0;

    float sum=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].time, time) == 0){
            sum = sum + jogadores[i].pontos;
        }
    }
    return sum/num_time;
}

/**
 * @brief   Média de idade dos jogadores de um time
 * @details Retorna a média de idade dos jogadores de um time
 *
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @return           Se jogadores ou time forem nulos, retorna -1. Retorna a média de idade
 *                   dos jogadores do time especificado. Se o nome do time for inválido
 *                   (time sem jogadores), retorna 0.
 */
float 		statt_media_idade			(jogador_t *jogadores, int njogadores, char* time){
    if(jogadores==NULL||time==NULL) return -1;
    float num_time=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].time, time) == 0){
            num_time++;
        }
    }

    if(num_time==0) return 0;

    float sum=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].time, time) == 0){
            sum = sum + jogadores[i].idade;
        }
    }
    return sum/num_time;
}

/**
 * @brief   Número de jogadores de uma posição no time
 * @details Retorna o número de jogadores de uma determinada posição que o time possui
 *
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @param posicao	 String com o nome da posição
 * @return           Se jogadores, time ou posição forem nulos, retorna -1. Retorna o número
 * 					 de jogadores de uma dada posição que o time possui. Se o nome do time
 * 					 ou posição forem inválidos (não estiverem no arquivo), retorna 0.
 */
int 		statt_posicao				(jogador_t *jogadores, int njogadores, char *time, char* posicao){
    if(jogadores==NULL||time==NULL||posicao==NULL) return -1;
    int num_time=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].time, time) == 0){
            num_time++;
        }
    }




    int sum=0;
    for(int i=0;i<njogadores;i++){
        if(strcmp(jogadores[i].posicao, posicao) == 0){
            sum++;
        }
    }

    if(num_time==0||sum==0) return 0;

    return sum;
}
