#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>
int main(void){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int numerocartelas, x = 0, y[75], auxiliar, status;
	printf("BINGO!!!\n\nDigite o numero de jogadores: ");
	scanf("%d", &numerocartelas);
	int cartelas[numerocartelas][5][5];
	for(int i = 0;i < numerocartelas;i++){
		for(int j = 0;j < 5;j++){
			for(int k = 0;k < 5;k++){
				if(j != 2 || k != 2){
					do{
						cartelas[i][j][k] = rand() % 16 + x;
						status = 1;
						for (int l = 0; (l < k) && (status == 1);l++){
							if (cartelas[i][j][k] == cartelas[i][j][l]){
								status = 0;
                			}
                		}
					} while (status == 0 || cartelas[i][j][k] - x == 0);
				}
				else{
					cartelas[i][j][k] = 0;
				}
			}
			x += 15;
		}
		x = 0;
	}
	printf("Okay, vamos imprimir cartelas para os jogadores\nObservação: 0 = Peças marcadas (e o coringa)\n");
	for(int i = 0;i < numerocartelas;i++){
		printf("\nCARTELA DO JOGADOR %d\n\n\tB\tI\tN\tG\tO\n", i+1);
		for(int j = 0;j < 5;j++){
			for(int k = 0;k < 5;k++){
				printf("\t%d", cartelas[i][k][j]);
			}
			printf("\n");
		}
	}
	printf("Agora, vamos sortear os numeros\n");
	for(int i = 0;i < 75;i++){
		system("pause");
		do{
			y[i] = rand() % 76;
			status = 1;
			for (int j = 0; (j < i) && (status == 1);j++){
				if (y[i] == y[j]){
					status = 0;
				}
    		}
		} 
		while (status == 0 || y[i] == 0);  			
		printf("NÚMERO SORTEADO: %d\n", y[i]);
		for(int j = 0;j < numerocartelas;j++){
			for(int k = 0;k < 5;k++){
				for(int l = 0;l < 5;l++){
					if(cartelas[j][k][l] == y[i]){
						cartelas[j][k][l] = 0;
					}
				}
			}
		}
		for(int j = 0;j < numerocartelas;j++){
			printf("\nCARTELA DO JOGADOR %d\n\n\tB\tI\tN\tG\tO\n", j+1);
			for(int k = 0;k < 5;k++){
				for(int l = 0;l < 5;l++){
					printf("\t%d", cartelas[j][l][k]);
				}
				printf("\n");
			}
		}
		for(int j = 0;j < numerocartelas;j++){
			if(cartelas[j][0][0] == 0 && cartelas[j][1][1] == 0 && cartelas[j][3][3] == 0 && cartelas[j][4][4] == 0 || cartelas[j][4][0] == 0 && cartelas[j][3][1] == 0 && cartelas[j][1][3] == 0 && cartelas[j][0][4] == 0){
				printf("\n\nJOGADOR %d FEZ A QUINA!!! PARABÉNS, VOCÊ GANHOU\n", j + 1);
				i = 76;
			}
			for(int k = 0;k < 5;k++){
				if(cartelas[j][k][0] == 0 && cartelas[j][k][1] == 0 && cartelas[j][k][2] == 0 && cartelas[j][k][3] == 0 && cartelas[j][k][4] == 0 || cartelas[j][0][k] == 0 && cartelas[j][1][k] == 0 && cartelas[j][2][k] == 0 && cartelas[j][3][k] == 0 && cartelas[j][4][k] == 0){
					printf("\n\nJOGADOR %d FEZ A QUINA!!! PARABÉNS, VOCÊ GANHOU\n", j + 1);
					i = 76;
				}
			}
		}
	}
	return 0;
}
