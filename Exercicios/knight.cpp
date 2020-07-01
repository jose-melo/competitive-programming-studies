#include <bits/stdc++.h>
using namespace std;


#define  ii pair <char, char>
#define MAX_N 8
#define INF 100000000
#define x first
#define y second

ii orig, dest;

vector<int> listAdj{1, 2, 3, 4, 5, 6, 7, 8};

int matriz[MAX_N][MAX_N];


int move(int i, ii atual, ii *resp){

	char aux[2];

	aux[0] = atual.x;
	aux[1] = atual.y;

	/*printf("#### aux = (%c %c) atual = (%c %c)\n",aux[0], aux[1], atual.x, atual.y );*/

	switch(i){

		case 1:
			aux[0] += 1;
			aux[1] += 2;
			break;

		case 2:
			aux[0] += 2;
			aux[1] += 1;
			break;

		case 3:
			aux[0] += 2;
			aux[1] -= 1;
			break;

		case 4:
			aux[0] += 1;
			aux[1] -= 2;
			break;

		case 5:
			aux[0] -= 1;
			aux[1] -= 2;
			break;

		case 6:
			aux[0] -= 2;
			aux[1] -= 1;
			break;

		case 7:
			aux[0] -= 2;
			aux[1] += 1;
			break;

		case 8:
			aux[0] -= 1;
			aux[1] += 2;
			break;
	}

	if(aux[0] >= 'a' && aux[0] <= 'h' && aux[1] >= '1' && aux[1] <= '8' && matriz[8 - (aux[1] - '0')][aux[0] - 'a'] == 0){
		

		resp->x = aux[0];
		resp->y = aux[1];
		

		/*printf("##### aux/resp = (%c %c)\n",aux[0], aux[1]);*/
		return 1;
	}
return 0;
}

void BFS(){

	queue<ii> fila;

	matriz[8 - (orig.y - '0')][orig.x - 'a'] = 0;


	fila.push(orig);

	while(!fila.empty()){

		ii casa = fila.front();
		fila.pop();

		/*printf("#casa = (%c, %c)\n",casa.x, casa.y );*/

		for(int u = 1; u <= 8; u++){
			ii aux;

			/*printf("###u = %d\n", u + 1);*/

			if(move(u, casa, &aux) == 1){
				matriz[8 - (aux.y - '0')][aux.x - 'a'] = matriz[8 - (casa.y - '0')][casa.x - 'a'] + 1;

				if(aux.x == orig.x && aux.y == orig.y)
					matriz[8 - (aux.y - '0')][aux.x - 'a'] = 0;
				else
					fila.push(aux);
			}
		}
	}
}

void clear(){
	int i, j;

	for(i = 0; i < MAX_N; i++)
		for(j = 0; j < MAX_N; j++)
			matriz[i][j] = 0;
return;
}

void imp(){
	
	int i, j;

	printf("\n");

	for(i = 0; i < MAX_N; i++){
		for(j = 0; j < MAX_N; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}



return;
}

int main(){

	int num;

	scanf("%d", &num);


	for(int i = 0; i < num; i++){

		scanf(" %c %c %c %c", &(orig.x), &(orig.y), &(dest.x), &(dest.y));


		clear();

		/*imp();*/

		BFS();

		/*imp();*/

		printf("%d\n",matriz[8 - (dest.y - '0')][dest.x - 'a']);


		clear();
	}
return 0;
}

