#include<stdlib.h>
#include<stdio.h>
main(){
	char dica[46], chute[26], errow[26];
	int letras, status;
	for(int i = 0;i < 26;i++){
		errow[i] = ' ';
	}
	printf("JOGO DA FORCA\n\nPrimeiramente, digite o tema (uma palavra) da palavra que será adivinhada: ");
	scanf("%s", &dica);
	printf("Agora, digite quantas letras tem a sua palavra: ");
	scanf("%d", &letras);
	char palavra[letras], aux[letras];
	printf("Agora, digite, LETRA POR LETRA (teclando ENTER a cada letra digitada) a palavra a ser adivinhada: ");
	for(int i = 0;i < letras;i++){
		scanf("%s", &palavra[i]);
		aux[i] = '_';
	}
	for(int jogadas = 0;jogadas < 26;jogadas++){
		system("cls");
		printf("Letras erradas: ");
		for(int i = 0;i < 26;i++){
			if(errow[i] != ' '){
				printf("%c ", errow[i]);
			}
		}
		printf("\n");
		for(int i = 0;i < letras;i++){
			printf("%c ", aux[i]);
		}
		printf("\nDica: %s\nDigite uma letra: ", dica[46]);
		scanf("%c", &chute[jogadas]);
		status = 0;
		for(int i = 0;i < letras;i++){
			if(chute[jogadas] == palavra[i]){
				aux[i] = palavra[i];
				status = 1;
			}
		}
		if(status == 0){
			errow[jogadas] = chute[jogadas];
		}
	}
}
