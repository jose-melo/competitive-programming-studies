#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define x first
#define y second


typedef pair<int, int> casa;

int matriz[MAX_N][MAX_N];

vector<casa> listAdj{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int visitados[MAX_N][MAX_N];

int n;

int resposta[MAX_N][MAX_N];

void BFS(casa orig){

	queue<casa> fila;

	casa aux;

	fila.push(orig);
	visitados[orig.x][orig.y] = 1;

	/*printf("INICIO DA BFS\n");
	*/
	while(!fila.empty()){

		casa s = fila.front();
		fila.pop();

		/*printf("s = [%d, %d]\n", s.x, s.y);
		*/
		for(auto y = listAdj.begin(); y < listAdj.end(); y++){

			aux = s;
			aux.x += y->x;
			aux.y += y->y;

			/*printf("aux = (%d, %d), visitados[aux.x][aux.y] = %d\n", aux.x, aux.y, visitados[aux.x][aux.y]);
			*/
			if(aux.x >= 0 && aux.x < n && aux.y >= 0 && aux.y < n && visitados[aux.x][aux.y] != 2){
				
				if(visitados[aux.x][aux.y] == 0){
					resposta[aux.x][aux.y] = resposta[s.x][s.y] + matriz[aux.x][aux.y];
					/*printf("NOVO resposta[%d][%d] = %d  resposta[s.x][s.y] = %d matriz[aux.x][aux.y] = %d\n",aux.x,aux.y, resposta[aux.x][aux.y], resposta[s.x][s.y], matriz[aux.x][aux.y]);
					*/visitados[aux.x][aux.y] = 1;

					fila.push(aux);
				}else{
					if(visitados[aux.x][aux.y] == 1){
						/*printf("BLAU resposta[%d][%d] = %d  resposta[s.x][s.y] = %d matriz[aux.x][aux.y] = %d\n",aux.x,aux.y, resposta[aux.x][aux.y], resposta[s.x][s.y], matriz[aux.x][aux.y]);	
						*/if(resposta[aux.x][aux.y] > resposta[s.x][s.y] + matriz[aux.x][aux.y]){
							/*printf("TOMA\n");*/
							resposta[aux.x][aux.y] = resposta[s.x][s.y] + matriz[aux.x][aux.y];
							/*printf("JYFGH resposta[%d][%d] = %d  resposta[s.x][s.y] = %d matriz[aux.x][aux.y] = %d\n",aux.x,aux.y, resposta[aux.x][aux.y], resposta[s.x][s.y], matriz[aux.x][aux.y]);	
							*/
							fila.push(aux);
						}
					}
				}
			}
		}
	}
}

int main(){

	int i, j;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &matriz[i][j]);



	casa orig;
	orig.x = 0;
	orig.y = 0;


	BFS(orig);

	/*printf("\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %d ", resposta[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	printf("%d\n", resposta[n-1][n-1]);

printf("\n");
return 0;
}


