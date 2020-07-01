#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200100

vector<int> listAdj[MAX_N];

int visitados[MAX_N];
int pais[MAX_N];


void dfs(int node, int *cont){

	int control = 0;

	if(visitados[node] == 1)return;

	if(visitados[node] != 3)
		visitados[node] = 1;

	/*printf("~~~DFS node = %d\n", node);*/

	for(auto x = listAdj[node].begin(); x < listAdj[node].end() && control == 0; x++){
		
		/*printf("visitados[*x = %d] = %d\n", *x, visitados[*x]);*/

		if(visitados[*x] == 3 && pais[node] != *x){
			/*printf("~~~~~~FOUND node = %d x = %d cont = %d\n", node, *x, *cont);*/
			(*cont)++;
		}
		if(visitados[*x] == 0){	

			if(*cont == 1)(*cont)++;

			pais[*x] = node;
			dfs(*x, cont);
		}


		if(visitados[*x] == 1 && pais[node] != *x){

			/*printf("visitados[*x = %d] = %d, pais[node = %d] = %d cont = %d \n",*x, visitados[*x], node, pais[node], *cont);*/
			(*cont) = 2;
		}

	}

	visitados[node] = 2;

	if(*cont == 0)*cont = 2;

	/*printf("TESTE node = %d cont = %d\n", node, *cont);*/

}

int main(){

	int n, m, i, a, b, cont, res = 0;

	scanf("%d %d", &n, &m);

	for(i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		listAdj[a].push_back(b);
		listAdj[b].push_back(a);
	}

	for(i = 1; i <= n; i++){
		cont = 0;

		if(visitados[i] == 0){

			visitados[i] = 3;
			dfs(i, &cont);
			visitados[i] = 2;
		}
		
		if(cont == 1)
			res++;

	}

	printf("%d\n", res);
return 0;
}