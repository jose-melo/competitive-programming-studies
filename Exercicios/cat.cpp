#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100100

int folhas[MAX_N];

vector<int> listAdj[MAX_N];

int visitados[MAX_N];
int cats[MAX_N];
int pais[MAX_N];

int n, m;

void dfs(int node, int *cat, int *cont, int max){

	visitados[node] = 1;
	if(cats[node] == 1){
		if(cats[pais[node]] == 1){
			(*cat)++;
		}
		else{
			(*cat) = 1;
		}
	}


	if(*cat > m)max = 1;


	int control = 0, aux;

	/*printf("~~~DFS node = %d, cat = %d, cont = %d, max = %d\n", node, *cat, *cont, max);*/

	aux = *cat;

	for(auto x = listAdj[node].begin(); x < listAdj[node].end(); x++){
		if(visitados[*x] == 0){
			pais[*x] = node;
			dfs(*x, cat, cont, max);
			*cat = aux;
			control = 1;
		}
	}

	if(control == 0){
	/*printf("~~~~~~~~FOLHA node = %d, max = %d, cont = %d\n", node, max, *cont);*/
		if(max == 0)
			(*cont)++;
	}
}

int main(){

	int i, cont = 0,cat = 0, a, b, max = -1;

	scanf("%d %d", &n, &m);

	for(i = 1; i <= n; i++)
		scanf("%d", &cats[i]);

	for(i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		listAdj[a].push_back(b);
		listAdj[b].push_back(a);
	}

	pais[1] = 0;
	cats[0] = 0;

	dfs(1, &cat, &cont, 0);

	printf("%d\n", cont);

return 0;
}
