#include <bits/stdc++.h>
using namespace std;

#define MAX_N 150


vector<int> listAdj[MAX_N];

int visitado[MAX_N];
pair<int, int> result[MAX_N];


void dfs (int node, int nivel, int *maxi){


	if(visitado[node] == 1)return;

	visitado[node] = 1;
	nivel++;


	int controle = 0;
	for(auto x = listAdj[node].begin(); x < listAdj[node].end(); x++){
		if(visitado[*x] == 0){
			controle = 1;
			dfs(*x, nivel, maxi);
		}
	}

	if(controle == 0){
		if(*maxi <= nivel){
			*maxi = nivel;
		}
	}

	/*printf("dfs node = %d, nivel = %d, maxi = %d\n", node, nivel, *maxi);*/
}

void reset(int n){
	int i;

	for(i = 0; i <= n; i++)
		visitado[i] = 0;

}

int main(){

	int n, a, b, i, max = -1, j;

	scanf("%d", &n);
	j = 1;

	while(n){

		reset(n);


		for(i = 1; i < n; i++){
			scanf("%d %d", &a, &b);
			listAdj[a].push_back(b);
			listAdj[b].push_back(a);
		}


		for(i = 1; i <= n; i++){
			dfs(i, -1, &max);
			/*printf("\n                #######################\n");*/
			if(max != -1)
				result[i].first = max;
			else
				result[i].first = 1000;	

			result[i].second = i;
			max = -1;
			reset(n);
		}

		/*for(int y = 1; y <= n; y++){
			printf("(%d, node = %d)", result[y].first, result[y].second);
		}
		printf("\n");*/

		sort(result + 1, result + n + 1);

		/*for(int y = 1; y <= n; y++){
			printf("(%d, node = %d)", result[y].first, result[y].second);
		}
		printf("\n");*/

		printf("Teste %d\n", j);
		printf("%d\n", result[1].second);


		for(i = 0; i <= n; i++)
			listAdj[i].clear();

		scanf("%d", &n);
		j++;
	}




}