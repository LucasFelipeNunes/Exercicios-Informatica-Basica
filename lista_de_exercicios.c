#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<locale.h>
#include<time.h>
main(){
	int numeroex;
	setlocale(LC_ALL, "portuguese");
	printf("EXERCÍCIOS DE INFORMÁTICA\n");
	printf("Escolha o numero do exercício: ");
	scanf("%d", &numeroex);
	system("cls");
	switch(numeroex){
		case 1:
		{
			float alunos[21], mediasala, somar;
			int acimamedia;
			for(int i = 1; i <= 20;i++){
				printf("Digite a nota do aluno %d: ", i);
				scanf("%f", &alunos[i]);
				somar += alunos[i];
			}
			mediasala = somar/20;
			for(int j = 1;j <= 20;j++){
				if(alunos[j] > mediasala){
					acimamedia++;
				}
			}
			printf("\nA media da sala foi %.2f e %d alunos ficaram acima dessa media", mediasala, acimamedia);
			break;
		}
		case 2:
		{
			float veto [10], auxilia, auxilia2;
			int ordemvetores [10];
			for (int i = 0;i<10;i++){
				ordemvetores[i] = i;
			} //isso serve só para declarar cada um dos vetores mais rapidamente
			printf("Digite 10 numeros quaisquer: ");
			for(int j = 0;j < 10;j++){
				scanf("%f", &veto[j]);
			}
			for(int k = 0;k < 10;k++){
				for(int l = k;l < 10; l++){
					if(veto[k] > veto[l]){
						auxilia = veto[k];
						veto[k] = veto[l];
						veto[l] = auxilia;
						auxilia2 = ordemvetores[k];
						ordemvetores[k] = ordemvetores[l];
						ordemvetores[l] = auxilia2;
					}
				}
			}
			printf("Em ordem crescente, os numeros que voce digitou ficam: ");
			for(int m = 0;m < 10;m++){
				printf("\n%f", veto[m]);
			}
			printf("\nE a ordem dos vetores onde eles foram colocados e: ");
			for(int n = 0;n < 10;n++){
				printf("\n%d", ordemvetores[n]);
			}
			break;
		}
		case 3:
		{
			int atriz[5][3], soma[5], zerador = 0;
			while(zerador<5){
				soma[zerador] = 0;
				zerador++;
			}
			for(int i = 0;i < 5;i++){
				for(int j = 0;j < 3;j++){
					printf("Digite o numero que ficara na linha %d e na coluna %d da matriz: ", i + 1, j + 1);
					scanf("%d", &atriz[i][j]);
					soma[i] += atriz[i][j];
				}
			}
			for(int x = 0;x < 5;x++){
				printf("\nA soma da linha %d resulta em %d", x + 1, soma[x]);
			}
			break;
		}
		case 4:
		{
			setlocale(LC_ALL, "portuguese");
			int matri[4][5], somaimpar = 0, somapar = 0, pares = 0, impares = 0, aux;
			float aux2, aux3, aux4, aux5, mediaimpar, mediapar;
			for (int i = 0;i < 3;i++){
				for (int j = 0;j < 5;j++){
					printf("Digite o valor que será alocado na linha %d e coluna %d: ", i, j);
					scanf("%d", &matri[i][j]);
					aux = matri[i][j]%2;
					if(aux == 1){
						impares++;
						somaimpar += matri[i][j];
					}
					else if(aux == 0){
						pares++;
						somapar += matri[i][j];
					}
				}
			}
			aux2 = pares;
			aux3 = impares;
			aux4 = somapar;
			aux5 = somaimpar; //essas variáveis foram criadas para transformar int em float, para que as médias saiam com vírgula
			mediaimpar = aux5/aux3;
			mediapar = aux4/aux2;
			printf("\nA quantidade de números pares é %d\nA quantidade de números ímpares é %d\nA soma dos números pares é %d\nA soma dos números ímpares é %d\nA média dos números pares é %f\nA média dos números ímpares é %f", pares, impares, somapar, somaimpar, mediapar, mediaimpar);
			break;
		}
		case 5:
		{
			system("color F0");
			char nomes [10][100];
			float notas [10][3], media[10], auxiliar = 0;
			int i5, j5, k, l;
			for(i5 = 0; i5 < 10; i5++){
				printf("Digite o nome do aluno %d: ", i5 + 1);
				scanf("%s", &nomes[i5]);
				printf("Digite abaixo as notas dele(a):\n");
				for(j5 = 0;j5 < 3; j5++){
					scanf("%f", &notas[i5][j5]);
					auxiliar += notas[i5][j5];
				}
				media[i5] = auxiliar/3;
				auxiliar = 0;
			}
			printf("\n\nALUNOS\t\t\tNOTAS\tSITUAÇÃO");
			for(i5 = 0;i5 < 10;i5++){
				printf("\n %s", nomes[i5]);
				for(j5 = 0;j5 < 3;j5++){
					printf("\t%.2f", notas[i5][j5]);
				}
				if(media[i5] >= 7){
					printf("\tAPROVADO");
				}
				else{
					printf("\tREPROVADO");	
				}
			}
			break;
		}
		case 6:
		{
			setlocale(LC_ALL, "portuguese");
			int matriz [5][5] = {{1, 2, 3, 4, 5},
								{6, 7, 8, 9, 10},
								{11, 12, 13, 14, 15},
								{16, 17, 18, 19, 20},
								{21, 22, 23, 24, 25}};
			printf("Os números da primeira diagonal são: ");
			for(int i = 0; i < 5; i++){
				printf("%d ", matriz[i][i]); 
			}
			printf("\nJá os números da segunda diagonal são: ");
			for(int i = 0; i < 5; i++){
				printf("%d ", matriz[i][4 - i]); 
			}
			break;
		}
		case 7:
		{
			setlocale(LC_ALL, "portuguese");
			int jogador, i, j;
			char velha[3][3];
			for(i = 0;i < 3;i++){
				for(j = 0;j < 3;j++){
					velha[i][j] = ' ';
				}				
			}
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
			break;
		}
		case 8:
		{
			setlocale(LC_ALL, "portuguese");
			int escolha;
			float saque, deposito, saldo, saquetotal, depositototal;
			while(true){
				printf("CAIXA ELETRÔNICO - ELETRO INC.");
				printf("\n\nO que você deseja fazer?\n1. Saque\n2. Depósito\n3. Consultar Saldo\n4. Sair\nDigite aqui: ");
				scanf("%d", &escolha);
				system("cls");
				switch(escolha){
					case 1:
						printf("Qual valor você deseja sacar? ");
						scanf("%f", &saque);
						printf("\nSaque de R$%.2f realizado com sucesso.", saque);
						sleep(1);
						system("cls");
						saquetotal += saque;
					break;
					case 2:
						printf("Qual valor você deseja depositar? ");
						scanf("%f", &deposito);
						printf("\nDepósito de R$%.2f realizado com sucesso.", deposito);
						sleep(1);
						system("cls");
						depositototal += deposito;
					break;
					case 3:
						saldo = depositototal - saquetotal;
						printf("O seu saldo atual é de R$%.2f", saldo);
						sleep (3);
						system("cls");
					break;
					case 4:
						exit(0);
					break;
					default:
						printf("Essa opção não existe\n");
						printf("Voltando ao menu principal");
				}
			}
			break;
		}
		case 9:
		{
			int a, b, i, j;
			float diagonalAum = 1, diagonalAdois = 1, diagonalBum = 1, diagonalBdois = 1;
			setlocale(LC_ALL, "portuguese");
			printf("Quais são as dimensões da matriz A? (nº de linhas e nº de colunas): ");
			scanf("%d", &a);
			float A[a][a];
			printf("Ok, agora vamos digitar os valores de cada espaço da matriz");
			for(i = 0;i < a;i++){
				for(j = 0;j < a;j++){
					printf("\nDigite o valor que será inserido na matriz A[%d][%d]: ", i, j);
					scanf("%f", &A[i][j]);
					if(i == j){
						diagonalAum *= A[i][j];
					}
					if((i + j) == (a - 1)){
						diagonalAdois *= A[i][j];
					}
				}	
			}
			printf("\n\nAgora, quais são as dimensões da matriz B? (nº de linhas e colunas): ");
			scanf("%d", &b);
			float B[b][b];
			printf("Ok, agora vamos digitar os valores de cada espaço da matriz");
			for(i = 0;i < b;i++){
				for(j = 0;j < b;j++){
					printf("\nDigite o valor que será inserido na matriz B[%d][%d]: ", i, j);
					scanf("%f", &B[i][j]);
					if(i == j){
						diagonalBum *= B[i][j];
					}
					if((i + j) == (b - 1)){
						diagonalBdois *= B[i][j];
					}	
				}
			}
			printf("\n\nO valor da diagonal principal de A é %f\nO valor da diagonal secundária de A é %f\nO valor da diagonal principal de B é %f\nO valor da diagonal secundária de B é %f", diagonalAum, diagonalAdois, diagonalBum, diagonalBdois);
			break;
		}
		case 10:
		{
			setlocale(LC_ALL, "portuguese");
			int tamanho;
			printf("Defina o tamanho do vetor: ");
			scanf("%d", &tamanho);
			int vetor [tamanho];
			srand(time(NULL));
			printf("\n\nO vetor aleatório de tamanho %d foi gerado\nEle consiste em: ", tamanho);
			for(int i = 0;i < tamanho;i++){
				vetor[i] = rand () % tamanho;
				printf("%d ", vetor[i]);
			}
		break;
		}
		default:
			printf("Ué");
	}
}
