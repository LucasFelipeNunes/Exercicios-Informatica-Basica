#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int jogadas = 0, linha[2], coluna[2], status, contador = 0, checao, checaO, aux, movspossiveis[4], verdadeiro = 1;
	char tabuleiro[8][8];
	printf("DAMAS\n\n");
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			if(i < 3 && ((i%2) == 0 && (j%2) == 1 || (i%2) == 1 && (j%2) == 0)){
				tabuleiro[i][j] = 'O';
			}
			else if(i > 4 && ((i%2) == 0 && (j%2) == 1 || (i%2) == 1 && (j%2) == 0)){
				tabuleiro[i][j] = 'o';
			}
			else{
				tabuleiro[i][j] = ' ';	
			}
		}
	}
	while(verdadeiro){
		jogadas++;
		printf("    1   2   3   4   5   6   7   8\n   _______________________________");
		for(int i = 0;i < 8;i++){
			printf("\n%d ", i + 1);
			for(int j = 0;j < 8;j++){
				printf("| %c ", tabuleiro[i][j]);
				if(tabuleiro[i][j] != 0){
					contador += 4;
					if(tabuleiro[i][j] == 'o' && tabuleiro[i - 1][j - 1] == 'o' || tabuleiro[i][j] == 'O' && tabuleiro[i + 1][j - 1] == 'O'){
						contador -= 2;
					}
					if(tabuleiro[i][j] == 'o' && tabuleiro[i - 1][j + 1] == 'o' || tabuleiro[i][j] == 'O' && tabuleiro[i + 1][j + 1] == 'O'){
						contador -= 2;
					}
				}
			}
			if(i == 7){
				printf("|\n  '-------------------------------'");
			}
			else{
				printf("|\n  |---+---+---+---+---+---+---+---|");
			}
		}
		printf("\nÉ a vez do jogador %d\n", 0 - jogadas%2 + 2);
		do{
			status = 1;
			printf("Primeiramente, escolha a peça que voce vai jogar\nDigite a linha em que ela está: ");
			scanf("%d", &linha[0]);
			while(linha[0] < 1 || linha[0] > 8){
				printf("Valor de linha inválido; Por favor, redigite o valor: ");
				scanf("%d", &linha[0]);
			}
			printf("Agora, digite a coluna onde está a peça: ");
			scanf("%d", &coluna[0]);
			while(coluna[0] < 1 || coluna[0] > 8){
				printf("Valor de coluna inválido; Por favor, redigite o valor: ");
				scanf("%d", &coluna[0]);
			}
			if(tabuleiro[linha[0] - 1][coluna[0] - 1] == ' ' || ((jogadas%2) == 1 && tabuleiro[linha[0] - 1][coluna[0] - 1] == 'O' || (jogadas%2) == 0 && tabuleiro[linha[0] - 1][coluna[0] - 1] == 'o')){
				printf("\nNão há peças suas nessas coordenadas; Por favor, redigite-as\n");
				status = 0;
			}
			movspossiveis[0] = linha[0];
			movspossiveis[1] = coluna[0] - 2;
			movspossiveis[2] = linha[0];
			movspossiveis[3] = coluna[0];
			if((jogadas%2 == 1)){
				movspossiveis[0] -= 2;
				movspossiveis[2] -= 2;
				if(tabuleiro[movspossiveis[0]][movspossiveis[1]] == 'O' && (linha[0] - 3) >= 0 && (linha[0] - 3) < 8 && (coluna[0] - 3) >= 0 && (coluna[0] - 3) < 8){
					movspossiveis[0]--;
					movspossiveis[1]--;
					movspossiveis[2] = 0;
					movspossiveis[3] = 0;
				}
				else if(tabuleiro[movspossiveis[2]][movspossiveis[3]] == 'O' && (linha[0] - 3) >= 0 && (linha[0] - 3) < 8 && (coluna[0] + 1) >= 0 && (coluna[0] + 1) < 8){
					movspossiveis[2]--;
					movspossiveis[3]++;
					movspossiveis[0] = 0;
					movspossiveis[1] = 0;
				}
			}
			else{
				if(tabuleiro[movspossiveis[0]][movspossiveis[1]] == 'o' && (linha[0] + 1) >= 0 && (linha[0] + 1) < 8 && (coluna[0] - 3) >= 0 && (coluna[0] - 3) < 8){
					movspossiveis[0]++;
					movspossiveis[1]--;
				}
				else if(tabuleiro[movspossiveis[2]][movspossiveis[3]] == 'o' && (linha[0] + 1) >= 0 && (linha[0] + 1) < 8 && (coluna[0] + 1) >= 0 && (coluna[0] + 1) < 8){
					movspossiveis[2]++;
					movspossiveis[3]++;
				}
			}
			status = 1;
			printf("Agora, escolha para onde voce vai querer mover sua peça\nDigite a linha para onde você vai mover sua peça: ");
			scanf("%d", &linha[1]);
			while(linha[1] < 1 || linha[1] > 8){
				printf("Valor de linha inválido; Por favor, redigite o valor: ");
				scanf("%d", &linha[1]);
			}
			printf("Agora, digite a coluna para onde você vai mover sua peça: ");
			scanf("%d", &coluna[1]);
			while(coluna[1] < 1 || coluna[1] > 8){
				printf("Valor de coluna inválido; Por favor, redigite o valor: ");
				scanf("%d", &coluna[1]);
			}
			if(tabuleiro[linha[1] - 1][coluna[1] - 1] != ' '){
				status = 0;
				printf("\nNão é possível fazer esse movimento; Por favor, redigite  os valores\n");
			}
			else if(movspossiveis[0] == linha[1] - 1 && movspossiveis[1] == coluna[1] - 1 || movspossiveis[2] == linha[1] - 1 && movspossiveis[3] == coluna[1] - 1){
				tabuleiro[linha[1] - 1][coluna[1] - 1] = tabuleiro[linha[0] - 1][coluna[0] - 1];
				tabuleiro[linha[0] - 1][coluna[0] - 1] = ' ';
				if((jogadas%2) == 1 && movspossiveis[0] == (linha[0] - 3) && movspossiveis[1] == (coluna[0] - 3)){
					tabuleiro[linha[0] - 2][coluna[0] - 2] = ' ';
				}
				else if((jogadas%2) == 1 && movspossiveis[2] == (linha[0] - 3) && movspossiveis[3] == (coluna[0] + 1)){
					tabuleiro[linha[0] - 2][coluna[0]] = ' ';
				}
				else if((jogadas%2) == 0 && movspossiveis[0] == (linha[0] + 1) && movspossiveis[1] == (coluna[0] - 3)){
					tabuleiro[linha[0]][coluna[0] - 2] = ' ';
				}
				else if((jogadas%2) == 0 && movspossiveis[2] == (linha[0] + 1) && movspossiveis[3] == (coluna[0] + 1)){
					tabuleiro[linha[0]][coluna[0]] = ' ';
				}
			}
			else{
				status = 0;
				printf("\nNão é possível fazer esse movimento; Por favor, redigite  os valores\n");
			}
		}	while(status == 0);
		system("cls");
		checao = 0;
		checaO = 0;
		for(int i = 0;i < 8;i++){
			if(tabuleiro[8][i] == 'o'){
				tabuleiro[8][i] == 'd';
			}
			if(tabuleiro[1][i] == 'O'){
				tabuleiro[1][i] == 'D';
			}
			for(int j = 0;j < 8;j++){
				if(tabuleiro[i][j] == 'o'){
					checao++;
				}
				if(tabuleiro[i][j] == 'O'){
					checaO++;
				}
			}
		}
		if(checaO == 0){
			printf("A PARTIDA ACABOU; JOGADOR 1 VENCEU");
			exit(0);
		}
		if(checao == 0){
			printf("A PARTIDA ACABOU; JOGADOR 2 VENCEU");
			exit(0);
		}
	}
}
