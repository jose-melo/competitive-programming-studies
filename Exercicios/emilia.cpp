#include <bits/stdc++.h>
using namespace std;

int matriz[1000][1000];

typedef struct {

	int x;
	int y;
} pos;

pos dir[4];

int n, m;

pos soma(pos a, pos b){
	pos res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
return res;
}


int dfs(pos sala,long long int *cont){
	pos aux;
	int control, i;

	if(matriz[sala.x][sala.y] == 3)
		return 1;

	matriz[sala.x][sala.y] = 4;

	for(i = 0; i < 4; i++){

		aux.x = sala.x +  dir[i].x;
		aux.y = sala.y +  dir[i].y;

		if(aux.x < n && aux.y < m && aux.x >= 0 && aux.y >= 0){

			if(matriz[aux.x][aux.y] == 3){
				*(cont)++;
				return 1;
			}

			if(matriz[aux.x][aux.y] == 1){
				
				(*cont)++;

				control = dfs(aux, cont);

				if(control == 0){
					(*cont)--;
				}else{
					return 1;
				}

			}
		}
	}

return 0;
}




int main(){

	long long int i, j, cont;

	cont = 1;
	pos ini;

	dir[0].x = -1;
	dir[0].y = 0;
	dir[1].x = 0;
	dir[1].y = -1;
	dir[2].x = 1;
	dir[2].y = 0;
	dir[3].x = 0;
	dir[3].y = 1;

	ini.x = 0;
	ini.y = 0;
	scanf("%d %d", &n, &m);

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &matriz[i][j]);
			if(matriz[i][j] == 2){
				ini.x = i;
				ini.y = j;
			}
		}
	}

	i = dfs(ini, &cont);
	cont++;

	printf("%lli\n", cont);

return 0;
}






