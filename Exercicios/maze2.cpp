#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
#define x first
#define y second


typedef pair<int, int> casa;

char matriz[MAX_N][MAX_N];

vector<casa> listAdj{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int n, m;

int dfs(casa p, int cont, int num){

	printf("~~~~~DFS matriz[%d][%d] = %c; cont = %d\n", p.x, p.y,matriz[p.x][p.y], cont);

	cont++;

	if(cont == num)return 1;

	for(auto aux = listAdj.begin(); aux < listAdj.end(); aux++){

		casa aux2 = p;
		aux2.x += (*aux).x;
		aux2.y += (*aux).y;


		if(aux2.x > 0 && aux2.x < m && aux2.y > 0 && aux2.y < n){
			if(matriz[aux2.x][aux2.y] % '.' == 0){
				matriz[aux2.x][aux2.y] += '.';
				return dfs(aux2, cont, num);
			}
		}
	}

return 0;
}




int main(){

	int k, i, j, vazias = 0, cont = 0;

	scanf("%d %d %d", &n, &m, &k);


	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf(" %c",&matriz[i][j]);
			if(matriz[i][j] == '.')
				vazias++;

		}
	}



	for(i = 0; i < n && cont < k; i++){
		for(j = 0; j < m && cont < k; j++){

			printf("matriz[%d][%d] = %c vazias = %d\n",i, j, matriz[i][j], vazias);

			if(matriz[i][j] % '.' == 0){



				matriz[i][j] = '#';

				casa aux;
				aux.x = i;
				aux.y = j;

				if(dfs(aux, 0, vazias) == 0){
					matriz[aux.x][aux.y] = '.';
				}else{
					cont++;
					vazias--;
				}
			}
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(matriz[i][j] % '.' == 0)
				printf(" . ");
			else
				printf(" %c ", matriz[i][j]);
		}
		printf("\n");
	}


return 0;
}













