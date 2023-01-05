#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int jogador, i, j;
	char velha[3][3];
	velha[0][0] = ' ';
	velha[2][2] = ' ';
	printf("JOGO DA VELHA");
	printf("\n\n| %c | %c | %c |", velha[0][0], velha[0][1], velha[0][2]);
	printf("\n| %c | %c | %c |", velha[1][0], velha[1][1], velha[1][2]);
	printf("\n| %c | %c | %c |", velha[2][0], velha[2][1], velha[2][2]);
	for(jogador=1;jogador<10;jogador++){
		if(jogador%2 == 1){
			printf("\n\nÉ a vez do jogador 1. Em qual lugar você joga (nº da linha e coluna, respectivamente): ");
			scanf("%d", &i);
			scanf("%d", &j);
			while(i > 3 || j > 3 || i < 1 || j < 1 || velha[i - 1][j - 1] == 'X' || velha[i - 1][j - 1] == 'O'){
				printf("\nJogada inválida; Redigite o lugar onde você vai jogar (nº da linha e coluna, respectivamente): ");
				scanf("%d", &i);
				scanf("%d", &j);
			}
			velha[i - 1][j - 1] = 'X';
			printf("\n\n| %c | %c | %c |", velha[0][0], velha[0][1], velha[0][2]);
			printf("\n| %c | %c | %c |", velha[1][0], velha[1][1], velha[1][2]);
			printf("\n| %c | %c | %c |", velha[2][0], velha[2][1], velha[2][2]);
			if(velha[0][0]=='X'&&velha[1][0]=='X'&&velha[2][0]=='X'||velha[0][1]=='X'&&velha[1][1]=='X'&&velha[2][1]=='X'||velha[0][2]=='X'&&velha[1][2]=='X'&&velha[2][2]=='X'||velha[0][0]=='X'&&velha[0][1]=='X'&&velha[0][2]=='X'||velha[1][0]=='X'&&velha[1][1]=='X'&&velha[1][2]=='X'||velha[2][0]=='X'&&velha[2][1]=='X'&&velha[2][2]=='X'||velha[2][0]=='X'&&velha[1][1]=='X'&&velha[0][2]=='X'||velha[0][0]=='X'&&velha[1][1]=='X'&&velha[2][2]=='X'){
				//Em resumo, se o jogador 1 venceu...
				printf("\n\nParabéns jogador 1! Você ganhou essa partida");
				exit(0);
			}
		}
		else{
			printf("\n\nÉ a vez do jogador 2. Em qual lugar você joga (nº da linha e coluna, respectivamente): ");
			scanf("%d", &i);
			scanf("%d", &j);
			while(i > 3 || j > 3 || i < 1 || j < 1 || velha[i - 1][j - 1] == 'X' || velha[i - 1][j - 1] == 'O'){
				printf("\nJogada inválida; Redigite o lugar onde você vai jogar (nº da linha e coluna, respectivamente): ");
				scanf("%d", &i);
				scanf("%d", &j);
			}
			velha[i - 1][j - 1] = 'O';
			printf("\n\n| %c | %c | %c |", velha[0][0], velha[0][1], velha[0][2]);
			printf("\n| %c | %c | %c |", velha[1][0], velha[1][1], velha[1][2]);
			printf("\n| %c | %c | %c |", velha[2][0], velha[2][1], velha[2][2]);
			if(velha[0][0]=='O'&&velha[1][0]=='O'&&velha[2][0]=='O'||velha[0][1]=='O'&&velha[1][1]=='O'&&velha[2][1]=='O'||velha[0][2]=='O'&&velha[1][2]=='O'&&velha[2][2]=='O'||velha[0][0]=='O'&&velha[0][1]=='O'&&velha[0][2]=='O'||velha[1][0]=='O'&&velha[1][1]=='O'&&velha[1][2]=='O'||velha[2][0]=='O'&&velha[2][1]=='O'&&velha[2][2]=='O'||velha[2][0]=='O'&&velha[1][1]=='O'&&velha[0][2]=='O'||velha[0][0]=='O'&&velha[1][1]=='O'&&velha[2][2]=='O'){
				//Em resumo, se o jogador 2 venceu...
				printf("\n\nParabéns jogador 2! Você ganhou essa partida");
				exit(0);
			}
		}
	}
	printf("\n\nO jogo terminou empatado");
}
