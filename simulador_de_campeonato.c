#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>
int pts[20], golsTime[2], posicao[20], jogos[20], vit[20], emp[20], gp[20], gc[20], ca[20], cv[20], aux;
char siglas[20][4] = {"AME", "CAP", "CAM", "BAH", "BOT", "RBB", "COR", "CTB", "CRU", "CUI", "FLA", "FLU", "FOR", "GOI", "GRE", "INT", "PAL", "SAN", "SPO", "VAS"}, times[20][20] = {"América Mineiro", "Athlético", "Atlético Mineiro", "Bahia", "Botafogo", "Red Bull Bragantino", "Corinthians", "Coritiba", "Cruzeiro", "Cuiabá", "Flamengo", "Fluminense", "Fortaleza", "Goiás", "Grêmio", "Internacional", "Palmeiras", "Santos", "São Paulo", "Vasco"};
double aproveitamento[20];
void naoEmpate(int ganhador){ // aumenta as vitórias e pontos do ganhador da partida
	vit[ganhador]++;
	pts[ganhador] += 3;
}
int main(void){
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	for(int i = 0;i < 20;i++){
		posicao[i] = i; //define os numeros das posicoes inicialmente
		for(int j = i + 1;j < 20;j++){ 
			for(int k = 0;k < 2;k++){ //simula os jogos dos 20 times entre eles, nos dois turnos
				golsTime[0] = rand() % 3;
				golsTime[1] = rand() % 3; //gols na partida
				ca[20] += rand() % 3;
				cv[20] += rand() % 1; //cartões na partida
				gp[i] += golsTime[0];
				gc[i] += golsTime[1];
				gp[j] += golsTime[0];
				gc[j] += golsTime[1]; //adicionando gols pró e contra dos times envolvidos
				jogos[i]++;
				jogos[j]++; //número de jogos
				if(golsTime[0] == golsTime[1]){
					emp[i]++;
					emp[j]++;
					pts[i]++;
					pts[j]++; // se der empate, adicionar 1 aos pontos e numero de empates dos clubes
				}
				else{
					naoEmpate((golsTime[0] > golsTime[1]) ? i : j); //se não, aplicar a função "não empate" no time vencedor
				}
			}
		}
	}
	for(int i = 0;i < 20;i++){
		aproveitamento[i] = 100.0 * pts[i] / (3 * jogos[i]); //calcula o aproveitamento
		for(int j = 0;j < 20;j++){ //percorre os times e os ordena
			if(pts[posicao[i]] > pts[posicao[j]] || pts[posicao[i]] == pts[posicao[j]] && (vit[posicao[i]] > vit[posicao[j]] || vit[posicao[i]] == vit[posicao[j]] && (gp[posicao[i]] - gc[posicao[i]] > gp[posicao[j]] - gc[posicao[j]] || gp[posicao[i]] - gc[posicao[i]] == gp[posicao[j]] - gc[posicao[j]] && (gp[posicao[i]] > gc[posicao[j]])))){
				aux = posicao[i];
				posicao[i] = posicao[j];
				posicao[j] = aux; //se um time tem pontos, vitórias, saldo de gols ou gols pró maiores que outro, colocá-lo na frente dele
			}
		}
	}
	printf("Posicao\tTime\tPontos\tJogos\tVit\tEmp\tDer\tGP\tGC\tSG\tAproveitamento");
	for(int i = 0;i < 20;i++){ //cria a tabela
		printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f", i + 1, siglas[posicao[i]], pts[posicao[i]], jogos[posicao[i]], vit[posicao[i]], emp[posicao[i]], jogos[posicao[i]] - vit[posicao[i]] - emp[posicao[i]], gp[posicao[i]], gc[posicao[i]], gp[posicao[i]] - gc[posicao[i]], aproveitamento[posicao[i]]);
	}
	printf("\n\nO time campeão foi o %s!\nOs times classificados direto para a Libertadores foram %s, %s, %s e %s.\nOs times classificados para a Pré-Libertadores foram %s e %s.\nOs times classificados para a Copa Sul-Americana foram %s, %s, %s, %s, %s e %s.\nOs times rebaixados para a série B foram %s, %s, %s e %s.", times[posicao[0]], times[posicao[0]], times[posicao[1]], times[posicao[2]], times[posicao[3]], times[posicao[4]], times[posicao[5]], times[posicao[6]], times[posicao[7]], times[posicao[8]], times[posicao[9]], times[posicao[10]], times[posicao[11]], times[posicao[16]], times[posicao[17]], times[posicao[18]], times[posicao[19]]);
	return 0;
}
