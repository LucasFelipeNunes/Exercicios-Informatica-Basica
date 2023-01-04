#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<string.h>
int pts[20], golsTime[2], jogos[20], vit[20], emp[20], gp[20], gc[20];
void naoEmpate(int ganhador){
	vit[ganhador]++;
	pts[ganhador] += 3;
}
int main(void){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	char timesParticipantes[20][20] = {"America Mineiro", "Athletico", "Atletico Mineiro", "Bahia", "Botafogo", "Red Bull Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiaba", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Gremio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"};
	float aproveitamento[20];
	for(int i = 0;i < 20;i++){
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
		printf("aaaaa");
	}
	for(int i = 0;i < 20;i++){
		aproveitamento[i] = pts[i] / 3 / jogos[i];
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f", /*timesParticipantes[i],*/ pts[i], jogos[i], vit[i], emp[i], jogos[i] - vit[i] - emp[i], gp[i], gc[i], gp[i] - gc[i], aproveitamento[i]);
	}
	return 0;
}
