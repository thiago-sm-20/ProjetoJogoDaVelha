//proj jvelha
//controller cpp

#include "JVelha-Model.h"
#include "JVelha-Controller.h"
#include "JVelha-View.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void limpar() {
	system("cls");
}

void ftempo(int seg) 
{ 
    time_t  lt1, lt2; 
	lt1 = time(NULL); 
	lt2 = lt1; 
    while (difftime(lt2, lt1) < seg) 
    lt2 = time(NULL); 
} 

void fclear() 
{ 
    int ch; 
    while((ch = fgetc(stdin)) != EOF && ch != '\n'); 
}

void prepSalv() {
	dados.dif1 = dif;
	dados.jogvez = jvez;
	dados.qtjog1 = qtjog;
	dados.flag1 = flag;
}

void gravar() {
	prepSalv();
	
	FILE *ft, *fv; //tabuleiro e variaveis globais 
	
	time_t registrarhora;
	struct tm *horariolocal;
	
	ft = fopen("MAT", "w");
	fv = fopen("DATA", "w");
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			fwrite(&jogo[i][j], sizeof(struct stjogo), 1, ft);
		}
	}    
	
	fwrite(&dados, sizeof(struct salvar), 1, fv);
	
	time(&registrarhora);
	horariolocal = localtime(&registrarhora);
	printf("Salvo em: %02d:%02d:%02d\n", horariolocal->tm_hour, horariolocal->tm_min, horariolocal->tm_sec);
	
	
	fclose(ft);
	fclose(fv);
} 

void carregar() {
	FILE *ft = NULL; 
	FILE *fv = NULL;
	
	ft = fopen("MAT", "r");
	fv = fopen("DATA", "r");
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			fread(&jogo[i][j], sizeof(struct stjogo), 1, ft);
		}
	}
	
	fread(&dados, sizeof(struct salvar), 1, fv);
	
	fclose(ft);
	fclose(fv);
	
	dif = dados.dif1;
	jvez = dados.jogvez;
	qtjog = dados.qtjog1;
	flag = dados.flag1;
}

void retomar() {
	if(flag == 1) {
		jogarComp();
	}
	if(flag == 2) {
		mostraJogada();
	}
}

void zerarEspacos() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			jogo[i][j].status = '.';
		}
	}
}

void primeiroJog() {
	int k;
	
	srand(time(NULL));
	k = rand() % 2 + 1;
	
	if(k == 1) {
		jvez = '1';
	}
	else if(k == 2) {
		jvez = '2';
	}
}

void iniciaJogo() {
	zerarEspacos();
	primeiroJog();	
}

void jogar() {
	int i, j, k;
	
	apresentaMensagem("Digite o local que deseja: (1 a 9, da esq para dir)\n");
	scanf("%d", &k);
	fclear();

	if(k > 9 || k < 1) {
		apresentaMensagem("");
		ftempo(3);
		return;
	}
	
	i = (k - 1) / 3;
	j = (k - 1) % 3;
	
	if(jogo[i][j].status != '.') {
		apresentaMensagem("Jogada ja realizada");
		ftempo(3);
		return;
	}


	if(jvez == '1') {
		jogo[i][j].status = 'X';
		jvez = '2';
		qtjog++;
	}
	else if(jvez == '2') {
		jogo[i][j].status = 'O';
		jvez = '1';            ;
		qtjog++;
	}
}

void verificaVencedor() {
	if(jogo[0][0].status == 'X' && jogo[0][1].status == 'X' && jogo[0][2].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[1][0].status == 'X' && jogo[1][1].status == 'X' && jogo[1][2].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[2][0].status == 'X' && jogo[2][1].status == 'X' && jogo[2][2].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][0].status == 'X' && jogo[1][0].status == 'X' && jogo[2][0].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][1].status == 'X' && jogo[1][1].status == 'X' && jogo[2][1].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][2].status == 'X' && jogo[1][2].status == 'X' && jogo[2][2].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][0].status == 'X' && jogo[1][1].status == 'X' && jogo[2][2].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[2][0].status == 'X' && jogo[1][1].status == 'X' && jogo[0][2].status == 'X') {
		limpar();
		mostraJogo();
		printf("O jogador 1 (ou X) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	
	
	
	if(jogo[0][0].status == 'O' && jogo[0][1].status == 'O' && jogo[0][2].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[1][0].status == 'O' && jogo[1][1].status == 'O' && jogo[1][2].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[2][0].status == 'O' && jogo[2][1].status == 'O' && jogo[2][2].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][0].status == 'O' && jogo[1][0].status == 'O' && jogo[2][0].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][1].status == 'O' && jogo[1][1].status == 'O' && jogo[2][1].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][2].status == 'O' && jogo[1][2].status == 'O' && jogo[2][2].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[0][0].status == 'O' && jogo[1][1].status == 'O' && jogo[2][2].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	if(jogo[2][0].status == 'O' && jogo[1][1].status == 'O' && jogo[0][2].status == 'O') {
		limpar();
		mostraJogo();
		printf("O jogador 2 (ou O) venceu!!\n");
		printf("Retornando ao menu principal\n");
		ftempo(5);
		limpar();
		menuInicial();
	}
	
	if(qtjog == 9) {
		limpar();  
		mostraJogo();
		printf("O jogo terminou em empate\n");
		printf("Retornando ao menu principal\n");
		ftempo(4);
		limpar();
		menuInicial();
	}
}

void jogarComp() {
	qualDificul();
	
	while(1) {
		limpar();
		verificaVencedor();
		if(jvez == '1') {
			mostraJogadaContraComp();
		}
		if(jvez == '2') {
			compJog();
		} 
	}
}

void compJog() {
	int qt = 0;
	
	if(dif == 1) { //modo facil
		do {
			sorteioComp();
		} while(verificaComp());
		
		jogo[x][y].status = 'O';
		qtjog++;
		jvez = '1';	
		return;	
	}
	if(dif == 2) {  //modo dificil
		int k;
		
		if(jogo[1][1].status == '.') {
			jogo[1][1].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}		
		
		if(jogo[0][0].status == 'O' && jogo[0][1].status == 'O') {
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[1][0].status == 'O' && jogo[1][1].status == 'O') {
			if(jogo[1][2].status == '.') {
				jogo[1][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][0].status == 'O' && jogo[2][1].status == 'O') {
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][1].status == 'O' && jogo[0][2].status == 'O') {
			if(jogo[0][0].status == '.') {
				jogo[0][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[1][1].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[1][0].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][1].status == 'O' && jogo[2][2].status == 'O') {
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][0].status == 'O' && jogo[1][0].status == 'O') {
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][1].status == 'O' && jogo[1][1].status == 'O') {
			if(jogo[2][1].status == '.') {
				jogo[2][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][2].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][2].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[1][0].status == 'O' && jogo[2][0].status == 'O') {
			if(jogo[0][0].status == '.') {
				jogo[0][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[1][1].status == 'O' && jogo[2][1].status == 'O') {
			if(jogo[0][1].status == '.') {
				jogo[0][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[1][2].status == 'O' && jogo[2][2].status == 'O') {
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		
		if(jogo[0][0].status == 'X' && jogo[0][1].status == 'X') {
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}	
		}
		if(jogo[0][2].status == 'X' && jogo[0][1].status == 'X') {
			if(jogo[0][0].status == '.') {
				jogo[0][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}	
		}
		if(jogo[1][0].status == 'X' && jogo[1][1].status == 'X') {
			if(jogo[1][2].status == '.') {
				jogo[1][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}	
		}
		if(jogo[1][2].status == 'X' && jogo[1][1].status == 'X') {
			if(jogo[1][0].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}	
		}
		if(jogo[2][0].status == 'X' && jogo[2][1].status == 'X') {
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][2].status == 'X' && jogo[2][1].status == 'X') {
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][0].status == 'X' && jogo[1][0].status == 'X') {
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 
		}
		if(jogo[2][0].status == 'X' && jogo[1][0].status == 'X') {
			if(jogo[0][0].status == '.') {
				jogo[0][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 
		}
		if(jogo[0][1].status == 'X' && jogo[1][1].status == 'X') {
			if(jogo[2][1].status == '.') {
				jogo[2][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 	
		}
		if(jogo[2][1].status == 'X' && jogo[1][1].status == 'X') {
			if(jogo[0][1].status == '.') {
				jogo[0][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 	
		}
		if(jogo[0][2].status == 'X' && jogo[1][2].status == 'X') {
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 
		}
		if(jogo[2][2].status == 'X' && jogo[1][2].status == 'X') {
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 
		}
		if(jogo[0][0].status == 'X' && jogo[1][1].status == 'X') {
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 
		}
		if(jogo[2][2].status == 'X' && jogo[1][1].status == 'X') {
			if(jogo[0][0].status == '.') {
				jogo[0][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 
		}
		if(jogo[2][0].status == 'X' && jogo[1][1].status == 'X') {
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			} 
		}
		if(jogo[1][1].status == 'X' && jogo[0][2].status == 'X') {
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][0].status == 'X' && jogo[0][2].status == 'X') {
			if(jogo[0][1].status == '.') {
				jogo[0][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[1][0].status == 'X' && jogo[1][2].status == 'X') {
			if(jogo[1][1].status == '.') {
				jogo[1][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][0].status == 'X' && jogo[2][2].status == 'X') {
			if(jogo[2][1].status == '.') {
				jogo[2][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][0].status == 'X' && jogo[2][0].status == 'X') {
			if(jogo[1][0].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][1].status == 'X' && jogo[2][1].status == 'X') {
			if(jogo[1][1].status == '.') {
				jogo[1][1].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][2].status == 'X' && jogo[2][2].status == 'X') {
			if(jogo[1][2].status == '.') {
				jogo[1][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		
		
		if(jogo[0][0].status == 'O' && jogo[0][1].status == 'O' && jogo[1][0].status == 'O') {
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][0].status == 'O' && jogo[2][1].status == 'O' && jogo[1][0].status == 'O') {
			if(jogo[0][0].status == '.') {
				jogo[0][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][1].status == 'O' && jogo[0][2].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[0][0].status == '.') {
				jogo[0][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][1].status == 'O' && jogo[2][2].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		
		if(jogo[0][0].status == 'O' && jogo[1][0].status == 'O' && jogo[1][1].status == 'O') {
			if(jogo[1][2].status == '.') {
				jogo[1][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][0].status == 'O' && jogo[1][0].status == 'O' && jogo[1][1].status == 'O') {
			if(jogo[1][2].status == '.') {
				jogo[1][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][2].status == '.') {
				jogo[2][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[0][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][2].status == 'O' && jogo[1][1].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[1][0].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[0][0].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][2].status == 'O' && jogo[1][1].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[1][0].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][0].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][2].status == '.') {
				jogo[2][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		
		if(jogo[1][0].status == 'O' && jogo[1][1].status == 'O' && jogo[0][2].status == 'O') {
			if(jogo[1][2].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][0].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[1][0].status == 'O' && jogo[1][1].status == 'O' && jogo[2][2].status == 'O') {
			if(jogo[1][2].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[0][0].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[0][0].status == 'O' && jogo[1][1].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[1][0].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[2][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		if(jogo[2][0].status == 'O' && jogo[1][1].status == 'O' && jogo[1][2].status == 'O') {
			if(jogo[1][0].status == '.') {
				jogo[1][0].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
			if(jogo[0][2].status == '.') {
				jogo[0][2].status = 'O';
				qtjog++;
				jvez = '1';
				return;
			}
		}
		
		if(jogo[2][0].status == '.') {
			jogo[2][0].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
		if(jogo[2][2].status == '.') {
			jogo[2][2].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
		if(jogo[0][0].status == '.') {
			jogo[0][0].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
		if(jogo[2][2].status == '.') {
			jogo[2][2].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
		if(jogo[2][1].status == '.') {
			jogo[2][1].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
		if(jogo[1][0].status == '.') {
			jogo[1][0].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
		if(jogo[1][2].status == '.') {
			jogo[1][2].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
		if(jogo[0][1].status == '.') {
			jogo[0][1].status = 'O';
			qtjog++;
			jvez = '1';
			return;
		}
	}
}
	

void sorteioComp() {
	srand(time(NULL));
	x = rand() % 3 + 1;
	y = rand() % 3 + 1;
	x--; y--; 
}

int verificaComp() {
	if (jogo[x][y].status != '.') {
		return 1;
	}
	return 0;
}









