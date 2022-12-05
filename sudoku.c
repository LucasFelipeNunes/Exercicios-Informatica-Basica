#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>
main(){
	system("color F0");
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	int numero, linha, coluna, sudoku[9][9], status = 0, a, b, c, d, x[9], y;
	for(int i = 0;i < 9;i++){
		do{
			status = 1;
			do{
				x[i] = rand()%10;
			}	while(x[i] == 0);
			for(int j = 0;j < i;j++){
				if(x[j] == x[i]){
					status = 0;
				}
			}
		}	while(status == 0);
	}
	y = rand()%10;
	int M[10][9][9] =	{{{0,x[7],0,x[4],0,0,x[5],0,0},{0,x[1],0,x[3],x[2],0,0,x[8],x[4]},{x[9],0,0,0,x[6],x[1],0,0,0},{0,0,x[5],0,x[8],0,0,x[2],x[9]},{0,x[2],x[9],x[7],0,x[5],x[1],x[6],0},{x[6],x[8],0,0,x[4],0,x[7],0,0},{0,0,0,x[8],x[1],0,0,0,x[7]},{x[8],0,0,0,x[5],x[4],0,x[3],0},{0,0,x[2],0,0,x[3],0,x[4],0}},
						{{0,0,x[8],x[4],x[7],0,x[3],0,x[6]},{0,x[6],0,0,0,x[2],0,x[1],0},{x[2],x[4],0,x[5],0,0,0,0,x[8]},{0,0,x[9],x[1],x[5],0,x[4],0,x[3]},{0,x[7],0,0,0,0,0,x[5],0},{x[5],0,x[4],0,x[8],x[3],x[2],0,0},{x[7],0,0,0,0,x[6],0,x[8],x[5]},{0,x[0],0,x[7],0,0,0,x[3],0},{x[6],0,x[2],0,x[0],x[5],x[1],0,0}},
						{{0,x[2],x[7],x[4],0,x[5],x[9],x[6],0},{x[4],x[0],0,x[2],0,x[6],0,x[5],x[1]},{0,0,x[1],0,0,0,0,x[7],0},{x[7],0,0,0,x[8],0,0,0,x[0]},{0,0,x[0],0,0,0,x[7],0,0},{x[1],0,0,0,x[6],0,0,0,x[5]},{0,x[7],0,0,0,0,x[5],0,0},{x[5],x[1],0,x[6],0,x[7],0,x[3],x[4]},{0,x[4],x[2],x[8],0,x[3],x[6],x[1],0}},
						{{x[7],0,x[8],0,x[3],0,0,0,x[6]},{0,x[3],0,x[8],0,0,x[1],x[4],0},{0,x[5],0,0,x[4],x[2],0,0,x[0]},{0,0,x[7],0,x[2],0,0,x[6],0},{x[5],0,x[2],x[3],0,x[0],x[8],0,x[4]},{0,x[0],0,0,x[7],0,x[5],0,0},{x[8],0,0,x[1],x[0],0,0,x[2],0},{0,x[1],x[6],0,0,x[7],0,x[3],0},{x[3],0,0,0,x[8],0,x[7],0,x[1]}},
						{{x[5],0,x[6],0,x[7],x[8],x[4],0,0},{x[0],0,0,0,0,0,0,x[2],0},{0,x[2],x[8],0,0,x[4],x[3],x[6],0},{0,0,0,x[1],x[2],0,x[8],x[5],x[4]},{0,0,0,x[0],0,x[3],0,0,0},{x[2],x[5],x[7],0,x[8],x[6],0,0,0},{0,x[1],x[3],x[6],0,0,x[0],x[8],0},{0,x[4],0,0,0,0,0,0,x[5]},{0,0,x[5],x[8],x[3],0,x[7],0,x[1]}},
						{{x[5],0,0,0,x[8],0,0,0,0},{0,0,0,x[1],0,x[7],x[3],x[8],0},{x[6],0,0,0,0,x[2],x[1],x[7],x[0]},{x[3],x[7],x[4],0,x[0],0,0,0,0},{0,0,x[1],x[2],0,x[8],x[6],0,0},{0,0,0,0,x[1],0,x[5],x[0],x[3]},{x[7],x[0],x[6],x[3],0,0,0,0,x[4]},{0,x[4],x[8],x[6],0,x[5],0,0,0},{0,0,0,0,x[4],0,0,0,x[2]}},
						{{0,0,0,0,x[0],x[4],x[7],0,0},{0,x[0],x[1],x[6],0,x[8],0,x[2],0},{x[4],0,0,x[7],x[3],0,x[5],0,x[6]},{0,0,0,x[8],0,0,x[1],0,x[5]},{x[1],0,x[6],0,0,0,x[2],0,x[0]},{x[3],0,x[4],0,0,x[2],0,0,0},{x[5],0,x[2],0,x[8],x[0],0,0,x[3]},{0,x[6],0,x[5],0,x[7],x[4],x[8],0},{0,0,x[7],x[1],x[6],0,0,0,0}},
						{{0,0,x[3],x[1],0,x[4],0,x[5],0},{x[6],x[8],0,x[3],0,0,x[2],x[7],0},{0,x[5],0,x[7],0,x[2],0,0,x[1]},{x[2],0,x[6],0,0,0,x[8],x[1],x[7]},{0,0,0,0,0,0,0,0,0},{x[5],x[4],x[8],0,0,0,x[6],0,x[0]},{x[8],0,0,x[0],0,x[1],0,x[2],0},{0,x[7],x[4],0,0,x[3],0,x[6],x[8]},{0,x[3],0,x[6],0,x[8],x[4],0,0}},
						{{0,x[4],0,0,0,x[2],x[3],0,x[8]},{0,x[3],x[1],0,x[6],0,0,0,0},{x[7],x[0],0,x[1],x[8],0,0,x[6],0},{x[1],0,x[4],x[8],0,x[6],0,0,x[9]},{0,x[7],0,0,0,0,0,x[4],0},{x[0],0,0,x[7],0,x[4],x[5],0,x[2]},{0,x[2],0,0,x[3],x[1],0,x[0],x[6]},{0,0,0,0,x[4],0,x[1],x[5],0},{x[3],0,x[5],x[6],0,0,0,x[7],0}},
 						{{x[5],0,x[6],0,0,x[0],0,0,x[8]},{x[0],x[4],0,0,x[7],0,x[5],0,0},{0,x[8],0,x[5],0,x[2],0,x[1],0},{0,x[5],0,x[4],x[6],0,0,0,x[7]},{x[8],0,x[3],0,0,0,x[6],0,x[4]},{x[7],0,0,0,x[8],x[1],0,x[3],0},{0,x[0],0,x[7],0,x[6],0,x[5],0},{0,0,x[2],0,x[3],0,0,x[4],x[0]},{x[1],0,0,x[8],0,0,x[7],0,x[2]}}};
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			sudoku[i][j] = M[y][i][j];
		}
	}
	printf("SUDOKU\n\n");
	while(true){
		status = 0;
		printf("    1   2   3   4   5   6   7   8   9\n  -------------------------------------\n");
		for(int i = 0;i < 9;i++){
			printf("%d |", i + 1);
			for(int j = 0;j < 9;j++){
				if(sudoku[i][j] == 0){
					printf("   ");
				}
				else{
					printf(" %d ", sudoku[i][j]);
				}
				if(j == 2 || j == 5 || j == 8){
					printf("|");
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
			if(i == 2 || i == 5 || i == 8){
				printf("  -------------------------------------");
			}
			printf("\n");
		}
		do{
			b = 0;
			d = 0;
			status = 1;
			coluna = 0;
			linha = 0;
			printf("Digite um numero (de 1 a 9): ");
			scanf("%d", &numero);
			while(numero < 1 || numero > 9){
				printf("Numero invalido; Por favor, digite outro numero (de 1 a 9): ");
				scanf("%d", &numero);
			}
			printf("Digite a linha do lugar onde voce deseja por esse numero (de 1 a 9): ");
			scanf("%d", &linha);
			while(linha < 1 || linha > 9){
				printf("Valor invalido; Por favor, digite um valor pra linha (de 1 a 9): ");
				scanf("%d", &linha);
			}
			printf("Agora, digite a coluna do lugar onde voce deseja por esse numero (de 1 a 9): ");
			scanf("%d", &coluna);
			while(coluna < 1 || coluna > 9){
				printf("Valor invalido; Por favor, digite um valor pra coluna (de 1 a 9): ");
				scanf("%d", &coluna);
			}
			if(numero == M[y][linha - 1][coluna - 1]){
				printf("Já tem um numero predeterminado nessa casa; Por favor, redigite os valores\n");
				status = 0;
			}
			else{
				sudoku[linha - 1][coluna - 1] = numero;
			}
			for(int a = 0;(a < 7) && (status == 1);a+=3){
				b += 3;
				for(int c = 0;(c < 7) && (status == 1);c+=3){
					d += 3;
					for(int i = a;(i < b) && (status == 1);i++){
						for(int j = c;(j < d) && (status == 1);j++){
							if(sudoku[linha-1][coluna-1] == sudoku[i][j] && (linha - 1) != i && (coluna - 1) != j && linha - 1 >= a && linha - 1 < b && coluna - 1 >= c && coluna - 1 < d){
								printf("Já existe um numero igual nesse quadrado; Por favor, redigite os valores\n");
								status = 0;
							}
						}
					}
				}
				d = 0;
			}
		}	while(status == 0);
			for(int i = 0;(i < 9) && (status == 1);i++){
				if(sudoku[linha - 1][i] == numero && i != coluna - 1){
					printf("Já tem um numero igual a esse nessa linha; Por favor, redigite os valores\n");
					status = 0;		
				}
				if(sudoku[i][coluna - 1] == numero && i != linha - 1){
					printf("Já tem um numero igual a esse nessa coluna; Por favor, redigite os valores\n");
					status = 0;
				}
			}

		system("cls");
	}
}
