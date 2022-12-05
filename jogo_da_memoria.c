#include<stdlib.h>		
#include<stdio.h>		
#include<locale.h>
#include<time.h>
#include<unistd.h>
main(){
	setlocale(LC_ALL, "portuguese");
	int linha[3], coluna[3], aux[4], contador = 0, produto = 1, pontos1 = 0, pontos2 = 0, jogadores;
	printf("JOGO DA MEMORIA\n\nEscolha o número de jogadores (1 ou 2): ");
	scanf("%d", &jogadores);
	while(jogadores != 1 && jogadores != 2){
		printf("Quantidade inválida; por favor, digite 1 ou 2 para a quantidade de jogadores: ");
		scanf("%d", &jogadores);
	}
	printf("Escolha a quantidade de linhas de cartas: ");
	scanf("%d", &linha[0]);
	printf("Escolha a quantidade de colunas de cartas: ");
	scanf("%d", &coluna[0]);
	while(linha[0] < 1 || coluna[0] < 1 || (linha[0] * coluna[0])%2 == 1){
		printf("Quantidade de linhas e/ou colunas inválida; por favor, redigite esses valores\nEscolha a quantidade de linhas de cartas: ");
		scanf("%d", &linha[0]);
		printf("Escolha a quantidade de colunas de cartas: ");
		scanf("%d", &coluna[0]);
	}
	system("cls");
	int respostas[linha[0]][coluna[0]], cartas[linha[0]][coluna[0]];
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	for(int i = 0;i < linha[0];i++){
		for(int j = 0;j < coluna[0];j++){
			cartas[i][j] = 0;
			respostas[i][j] = 0;
		}
	}
	while(contador < ((linha[0] * coluna[0])/2)){
		aux[0] = rand()%linha[0];
		aux[1] = rand()%coluna[0];
		aux[2] = rand()%linha[0];
		aux[3] = rand()%coluna[0];
		while(respostas[aux[0]][aux[1]] != 0 || respostas[aux[2]][aux[3]] != 0 || aux[0] == aux[2] && aux[1] == aux[3]){
			aux[0] = rand()%linha[0];
			aux[1] = rand()%coluna[0];
			aux[2] = rand()%linha[0];
			aux[3] = rand()%coluna[0];		
		}
		while(respostas[aux[0]][aux[1]] == 0){
			respostas[aux[0]][aux[1]] = (contador + 1);
			respostas[aux[2]][aux[3]] = respostas[aux[0]][aux[1]];
		}
		contador++;
	}
	contador = 3;
	while(contador > 0){
		for(int i = 0;i < linha[0];i++){
			for(int j = 0;j < coluna[0];j++){
				if(cartas[i][j] < 10){
					printf("0");
				}
				printf("%d\t", cartas[i][j]);
			}
			printf("\n");
		}
		if(jogadores == 2){
			if((contador%2) == 1){
				printf("\n\nÉ a vez do jogador 1");
			}
			else{
				printf("\n\nÉ a vez do jogador 2");
			}
			printf("\nJOGADOR 1 %d x %d JOGADOR 2", pontos1, pontos2);
		}
		printf("\nDigite as coordenadas de uma carta (linha e coluna): ");
		scanf("%d", &linha[1]);
		scanf("%d", &coluna[1]);
		while(linha[1] < 1 || linha[1] > linha[0] || coluna[1] < 1 || coluna[1] > coluna[0] || cartas[linha[1] - 1][coluna[1] - 1] != 0){
			printf("\nCoordenada inválida; Por favor, digite uma coordenada válida: ");
			scanf("%d", &linha[1]);
			scanf("%d", &coluna[1]);			
		}
		for(int i = 0;i < linha[0];i++){
			for(int j = 0;j < coluna[0];j++){
				if((linha[1] - 1) == i && (coluna[1] - 1) == j){
					if(respostas[i][j] < 10){
						printf("0");
					}
					printf("%d\t", respostas[i][j]);
				}
				else{
					if(cartas[i][j] < 10){
						printf("0");
					}
						printf("%d\t", cartas[i][j]);
				}
			}
			printf("\n");
		}
		printf("Agora, digite as coordenadas de outra carta: ");
		scanf("%d", &linha[2]);
		scanf("%d", &coluna[2]);
		while(linha[2] < 1 || linha[2] > linha[0] || coluna[2] < 1 || coluna[2] > coluna[0] || linha[1] == linha[2] && coluna[1] == coluna[2] || cartas[linha[2] - 1][coluna[2] - 1] != 0){
			printf("Coordenada inválida; Por favor, digite uma coordenada válida: ");
			scanf("%d", &linha[2]);
			scanf("%d", &coluna[2]);
		}
		printf("\n");
		for(int i = 0;i < linha[0];i++){
			for(int j = 0;j < coluna[0];j++){
				if((linha[1] - 1) == i && (coluna[1] - 1) == j || (linha[2] - 1) == i && (coluna[2] - 1) == j){
					if(respostas[i][j] < 10){
						printf("0");
					}
					printf("%d\t", respostas[i][j]);
				}
				else{
					if(cartas[i][j] < 10){
						printf("0");
					}
					printf("%d\t", cartas[i][j]);
				}
			}
			printf("\n");	
		}
		if(respostas[linha[1] - 1][coluna[1] - 1] == respostas[linha[2] - 1][coluna[2] - 1]){
			printf("VOCE ACERTOU ESSA COMBINAÇÃO");
			cartas[linha[1] - 1][coluna[1] - 1] = respostas[linha[1] - 1][coluna[1] - 1];
			cartas[linha[2] - 1][coluna[2] - 1] = respostas[linha[2] - 1][coluna[2] - 1];
			if(jogadores == 2){
				if((contador%2) == 1){
					pontos1++;
				}
				else{
					pontos2++;
				}
			}
		}
		else{
			printf("VOCE ERROU ESSA COMBINAÇÃO");
		}
		for(int i = 0;i < linha[0];i++){
			for(int j = 0;j < coluna[0];j++){
				produto *= cartas[i][j];
			}
		}
		if(produto != 0 && jogadores == 2){
			if(pontos1 > pontos2){
				printf("\n\nPARABENS JOGADOR 1, VOCE GANHOU");
				exit(0);
			}
			else if(pontos2 > pontos1){
				printf("\n\nPARABENS JOGADOR 2, VOCE GANHOU");
				exit(0);
			}
			else{
				printf("\n\nO jogo terminou empatado");
			}
			printf("\nPLACAR: JOGADOR 1 %d x %d JOGADOR 2", pontos1, pontos2);
			exit(0);
		}
		else if(produto != 0 && jogadores == 1){
			printf("\n\nPARABENS, VOCE VENCEU!!!");
		}
		else{
			produto = 1;
		}
		sleep(3);
		for(int i = 1;i < 3;i++){
			linha[i] = 0;
			coluna[i] = 0;
		}
		contador++;
		system("cls");
	}
}
