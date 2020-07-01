#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10100

int folhas[MAX_N];

vector<int> listAdj[MAX_N];

int visitados[MAX_N];


void dfs(int node, int nivel, int *cont, int *max){

	visitados[node] = 1;
	int control = 0;
	nivel++;

	if(*max < nivel)
		*max = nivel;

	for(auto x = listAdj[node].begin(); x < listAdj[node].end(); x++){
		if(visitados[*x] == 0){
			dfs(*x, nivel, cont, max);
			if(node == 1){
				folhas[*cont] = *max;
				(*cont)++;
				*max = -1;
			}
		}
	}
}

int main(){

	int n, i, a, b, cont = 0, nivel = -1, max = -1;

	scanf("%d", &n);

	for(i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		listAdj[a].push_back(b);
		listAdj[b].push_back(a);
	}

	dfs(1, nivel, &cont, &max);

	sort(folhas, folhas + cont);

	if(cont != 1)
		printf("%d\n", folhas[cont - 1] + folhas[cont - 2]);
	else
		printf("%d\n", folhas[cont - 1]);


return 0;
}
