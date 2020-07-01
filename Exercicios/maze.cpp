#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	int x;
	int y;
} pos;

char matriz[550][550];
char aux[550][550];

pos dir[4];


int n, m;

int visitado(pos casa){

	if(aux[casa.x][casa.y] == '.' + 1)
		return 1;
return 0;
}

void mark_visitado(pos casa){
	aux[casa.x][casa.y] = '.' + 1;
return;
}

pos soma(pos a, pos b){

	pos res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
return res;
}


void dfs(pos casa){

	int i;
	pos aux2;

	if(visitado(casa))
		return;

	mark_visitado(casa);

	for(i = 0; i < 4; i++){
		aux2 = soma(casa, dir[i]);
		if(aux2.x > 0 && aux2.x < n && aux2.y > 0 && aux2.y < m)
			if(aux[aux2.x][aux2.y] == '.')
				if(!visitado(soma(casa, dir[i])))
					dfs(soma(casa, dir[i]));
	}

return;
}


checa()

int main(){


	int i, j, cont, num_vazias = 0;
	pos aux3;

	scanf("%d %d", &n, &m);

	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf("%c", &matriz[i][j]);

		reset();


	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			
			reset();
			if(aux[i][j] == '.'){
				aux[i][j] = '.' + 2;
				aux3.x = i;
				aux3.y = j;	
				dfs(aux3);
				if(checa() == 1){
					aux[i][j] = 'X';
				}else{
					aux[i][j] = '.';
				}
			}
		}

	}



}






















