#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
#define x first
#define y second


typedef pair<int, int> casa;

char matriz[MAX_N][MAX_N];

vector<casa> listAdj{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int n, m;


int dfs(casa p, int num_necessario, int *num_atual){
	if(*num_atual == num_necessario)return 1;

	matriz[p.x][p.y] = 'J';

	for(auto aux = listAdj.begin(); aux < listAdj.end(); aux++){

		casa aux2 = p;
		aux2.x += (*aux).x;
		aux2.y += (*aux).y;

		if(aux2.x >= 0 && aux2.x < n && aux2.y >= 0 && aux2.y < m){
			if(matriz[aux2.x][aux2.y] == '.'){
				(*num_atual)++;
				if(dfs(aux2, num_necessario, num_atual) == 1){
					return 1;
				}
			}
		}
	}

return 0;
}

int main(){

	int k, i, j, vazias = 0, cont = 0, control = 0, num_atual = 0;

	scanf("%d %d %d", &n, &m, &k);


	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf(" %c",&matriz[i][j]);
			if(matriz[i][j] == '.')
				vazias++;

		}
	}


	for(i = 0; i < n && control == 0; i++){
		for(j = 0; j < m && control == 0; j++){
			if(matriz[i][j] == '.'){
				casa aux;
				aux.x = i;
				aux.y = j;

				dfs(aux, vazias - k, &num_atual);

				if(num_atual == vazias - k)
					control = 1;
			}
				
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(matriz[i][j] == '.'){
				printf("X");
			}
			else{
				if(matriz[i][j] == 'J')
					printf(".");
				else
					printf("%c", matriz[i][j]);

			}
		}
		printf("\n");
	}


return 0;
}