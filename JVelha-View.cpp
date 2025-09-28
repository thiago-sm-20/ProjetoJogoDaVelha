//proj jvelha
//view cpp

#include "JVelha-Model.h"
#include "JVelha-View.h"
#include "JVelha-Controller.h"


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void apresentaMensagem(char mens[100]) {
	printf("%s", mens);
}

void menuInicial() {
	char op;
	
	printf("       JOGO DA VELHA    \n");
	printf("=======================================\n");
	printf("1) = Jogar contra o computador\n");
	printf("2) = Jogar com 2 jogadores\n");
	printf("3) = Salvar o jogo de onde parou\n");
	printf("4) = Carregar um jogo salvo\n");
	printf("5) = Sair do jogo\n");
	printf("=======================================\n");
	printf("O que deseja fazer: \n");
	printf("--> ");
	scanf("%c", &op);
	fclear();
	
	switch (op) {
		case '1':
			iniciaJogo();
			flag = 1;
			jogarComp();
			break;
		case '2':
			iniciaJogo();
			flag = 2;
			mostraJogada();
			break;
		case '3':
			printf("\n");
			gravar();
			ftempo(4);
			break;
		case '4':
			carregar();
			retomar();
			break;
		case '5':
			exit(0);
			break;
		default: 
			printf("Opcao invalida, tente novamente\n");
			ftempo(3);
			limpar();
			break;
	}
}

void mostraJogo() {
	printf("  Tabuleiro de jogo:\n\n");
	for(int i = 0; i < 3; i++) {
		printf("    ");
		for(int j = 0; j < 3; j++) {
			if(jogo[i][j].status == 'X') {
				printf(" |X| ");
			}
			else if(jogo[i][j].status == 'O') {
				printf(" |O| ");
			}
			else if (jogo[i][j].status == '.'){
				printf(" | | ");
			}
		}
		printf("\n\n");
	}
	printf("\n\n");
}

void mostraJogada() {
	char op;
	
	while(1) {
		
		limpar();
		verificaVencedor();
		mostraJogo();
		printf("Jogador da vez: %c\n\n", jvez);
		printf("Jogador 1 = X\n");
		printf("Jogador 2 = O\n");
		printf("\n\n");
		
		printf("Digite o que deseja fazer: \n");
		printf("J) - Realizar uma jogada\n");
		printf("S) - Sair para o menu inicial\n");
		printf("=> ");
		scanf("%c", &op);
		
		switch (op) {
			case 'j':
				printf("\n");
				jogar();
				break;
			case 's':
				limpar();
				fclear();
				menuInicial();
				break;
			default:
				printf("Escolha invalida, tente novamente\n\n");
				ftempo(2);
				break;
		}
	}
}

void qualDificul() {
	limpar();
	if(dif == 0) {
		printf("Selecione a dificuldade de jogo: \n");
		printf("1 - Modo facil\n");
		printf("2 - Modo dificil\n");
		printf("=> ");
		scanf("%d", &dif);
	}
}

void mostraJogadaContraComp() {
		char op;
		
		limpar();
		verificaVencedor();
		mostraJogo();
		printf("Jogador da vez: %c\n\n", jvez);
		printf("Jogador 1 = X\n");
		printf("Jogador 2 = O\n");
		printf("\n\n");
		
		printf("Digite o que deseja fazer: \n");
		printf("J) - Realizar uma jogada\n");
		printf("S) - Sair para o menu inicial\n");
		printf("=> ");
		scanf("%c", &op);
		
		switch (op) {
			case 'j':
				printf("\n");
				jogar();
				break;
			case 's':
				limpar();
				fclear();
				menuInicial();
				break;
			default:
				printf("Escolha invalida, tente novamente\n\n");
				ftempo(2);
				break;
		}
}



