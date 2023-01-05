#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<string.h>
int gols[2];
void jogoMataMata(void){
	for(int j = 0;j < 2;j++){
		gols[0] = rand() % 3;
		gols[1] = rand() % 3;
	}
	if(gols[1] == gols[0]){
		gols[0] += rand() % 5;
		gols[1] += rand() % 5;
	}
}
int main(void){
	char siglasFase1[2][3][4] = {
		{"HUA", "NCP", "BOR"},
		{"NCN", "EL", "ZAM"}
	}, siglasFase2[2][8][4] = {
		{"CAR", "UNQ", "AAA", "BBB", "CDM", "CUR", "CCC", "MAG"},
		{"CAM", "MIL", "SCR", "HUR", "FOR", "CER", "DIM", "ALW"}
	}, siglasFase3[2][4][4], siglasFaseGrupos[8][4][4];
	int golsProFase1[2];
	srand(time(NULL));
	for(int i = 0;i < 3;i++){ // jogos da primeira fase
		jogoMataMata();
		strcpy(siglasFase2[0][(i == 0) ? 2 : (i == 1) ? 3 : 6], siglasFase1[gols[1] > gols[0]][i]);
	}
	for(int i = 0;i < 8;i++){ //jogos da segunda fase
		jogoMataMata();
		strcpy(siglasFase3[i >= 4][(i >= 4) ? i : 7 - i], siglasFase2[gols[1] > gols[0]][i]);
	}
	for(int i = 0;i < 4;i++){ //jogos da terceira fase
		jogoMataMata();
	}
	return 0;
}
