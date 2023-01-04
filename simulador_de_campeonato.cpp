#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<string.h>
int pts[20], golsTime[2], posicao[20], jogos[20], vit[20], emp[20], gp[20], gc[20], aux;
void naoEmpate(int ganhador){
	vit[ganhador]++;
	pts[ganhador] += 3;
}
int main(void){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	char timesParticipantes[20][20] = {"AME", "CAP", "CAM", "BAH", "BOT", "RBB", "COR", "CTB", "CRU", "CUI", "FLA", "FLU", "FOR", "GOI", "GRE", "INT", "PAL", "SAN", "SPO", "VAS"};
	double aproveitamento[20];
	for(int i = 0;i < 20;i++){
		posicao[i] = i;
		for(int j = i + 1;j < 20;j++){
			for(int k = 0;k < 2;k++){
				golsTime[0] = rand() %3;
				golsTime[1] = rand() %3;
				gp[i] += golsTime[0];
				gc[i] += golsTime[1];
				gp[j] += golsTime[0];
				gc[j] += golsTime[1];
				jogos[i]++;
				jogos[j]++;
				if(golsTime[0] == golsTime[1]){
					emp[i]++;
					emp[j]++;
					pts[i]++;
					pts[j]++;	
				}
				else{
					naoEmpate((golsTime[0] > golsTime[1]) ? i : j);
				}
			}
		}
	}
	for(int i = 0;i < 20;i++){ // calcula o aproveitamento e ordena os times
		aproveitamento[i] = 100.0 * pts[i] / (3 * jogos[i]);
		for(int j = 0;j < 20;j++){
			if(pts[posicao[i]] > pts[posicao[j]] || pts[posicao[i]] == pts[posicao[j]] && (vit[posicao[i]] > vit[posicao[j]] || vit[posicao[i]] == vit[posicao[j]] && (gp[posicao[i]] - gc[posicao[i]] > gp[posicao[j]] - gc[posicao[j]] || gp[posicao[i]] - gc[posicao[i]] == gp[posicao[j]] - gc[posicao[j]] && (gp[posicao[i]] > gc[posicao[j]])))){
				aux = posicao[i];
				posicao[i] = posicao[j];
				posicao[j] = aux;
			}
			
		}
	}
	printf("Pos\tTime\tPts\tJogos\tVit\tEmp\tDer\tGP\tGC\tSG\tAproveitamento");
	for(int i = 0;i < 20;i++){
		printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f", i + 1, timesParticipantes[posicao[i]], pts[posicao[i]], jogos[posicao[i]], vit[posicao[i]], emp[posicao[i]], jogos[posicao[i]] - vit[posicao[i]] - emp[posicao[i]], gp[posicao[i]], gc[posicao[i]], gp[posicao[i]] - gc[posicao[i]], aproveitamento[posicao[i]]);
	}
	return 0;
}
