#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> senha;

senha senhas[10][6];

int aux[10];
int resp[6];

void identifica(char ch, int i, int j){


	
	if(ch == 'A'){

		senhas[i][j].first = aux[0];
		senhas[i][j].second = aux[1];
	}
	if(ch == 'B'){

		senhas[i][j].first = aux[2];
		senhas[i][j].second = aux[3];
	}
	if(ch == 'C'){

		senhas[i][j].first = aux[4];
		senhas[i][j].second = aux[5];
	}
	if(ch == 'D'){

		senhas[i][j].first = aux[6];
		senhas[i][j].second = aux[7];
	}
	if(ch == 'E'){

		senhas[i][j].first = aux[8];
		senhas[i][j].second = aux[9];
	}
return;
}

int main(){

	int i, n, j, aux2, k, acabou = 0, cont = 0, cont2 = 0;
	char ch;

	scanf("%d", &n);
	cont++;

	while(n != 0){

		for(i = 0; i < n; i++){

			for(j = 0; j < 10; j++)
				scanf("%d", &aux[j]);

		/*	printf("aux\n");

			for(k = 0; k < 10; k++)
				printf("%d ", aux[k]);
			printf("\n");*/

			for(j = 0; j < 6; j++){
				scanf(" %c", &ch);
				identifica(ch, i, j);
			}

		}

		/*printf("\n");
		printf("MAOE\n");
		for(i = 0; i < 6; i++)
			printf("%d ", senhas[0][i].first);
		printf("\n");*/

		for(j = 0; j < 6; j++){

			acabou = 0;
			cont2 = 0;
			for(i = 0; i < n && acabou != 2; i++){
				cont2 = 0;
				for(k = 0; k < n && acabou != 2; k++){
					if(senhas[k][j].first == senhas[i][j].first){
						//printf("teste1\n"); 
						resp[j] = senhas[i][j].first;
						cont2++;
					}
					if(senhas[k][j].second == senhas[i][j].first){
						//printf("teste2\n");
						resp[j] = senhas[i][j].first; 
						cont2++;
					}
					if(senhas[k][j].first == senhas[i][j].second){
						//printf("teste3\n");
						resp[j] = senhas[i][j].second; 
						cont2++;
					}
					if(senhas[k][j].second == senhas[i][j].second){
						//printf("teste4\n");
						resp[j] = senhas[i][j].second;
						cont2++;
					}	

					if(cont2 == 1)acabou = 2;
					if(cont2 == 2)acabou = 1;
				}
			}
		}
		printf("\n");
		printf("Teste %d\n", cont);
		for(i = 0; i < 6; i++)
			printf("%d ", resp[i]);
		printf("\n");


	scanf("%d", &n);
	cont++;
	}



}