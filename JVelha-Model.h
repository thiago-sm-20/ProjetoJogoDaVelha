//proj jvelha
//model h

#ifndef MODEL_H
#define MODEL_H

typedef struct stjogo {
	char status;  // 'X' ou 'O' ou '.' 
} Jogo;

Jogo jogo[3][3];
int qtjog = 0;
char jvez;
int dif = 0;
int x, y;
int flag = 0;

typedef struct salvar {
	int  qtjog1;
	char jogvez;
	int dif1;
	int flag1;
} Salvar;

Salvar dados;

#endif