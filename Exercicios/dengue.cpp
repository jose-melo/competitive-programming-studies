#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100


vector<int> listAdj[MAX_N];

int visitado[MAX_N];
vector<pair<int, int>> result;

int pais[MAX_N];

int dfs (int node, int nivel){

	int maxi, aux, controle;

	if(visitado[node] == 1)return -1;

	visitado[node] = 1;
	nivel++;

	printf("~~~2DFS node = %d nivel = %d\n", node, nivel);

	maxi = -1;
	controle = 0;
	for(auto x = listAdj[node].begin(); x < listAdj[node].end(); x++){
		printf("node = %d *x = %d\n", node, *x);

		if(visitado[*x] == 0){

			controle = 1;
			aux = dfs(*x, nivel) + 1;
			printf("node: %d ====> *x : %d #### aux = %d max = %d\n",node, *x, aux, maxi);

			if(maxi < aux)
				maxi = aux;
		}
	}

	if(controle == 0){
		result.push_back(make_pair(max(nivel, 0), node));
		return 0;
	}


result.push_back(make_pair(max(maxi, nivel), node));
return maxi;
}

int main(){

	int n, a, b, i;

	scanf("%d", &n);

	while(n){



		for(i = 1; i < n; i++){
			scanf("%d %d", &a, &b);
			listAdj[a].push_back(b);
			listAdj[b].push_back(a);
		}

		dfs(1, -1);

		for(auto y = result.begin(); y < result.end(); y++){
			printf("(%d, node = %d)", y->first, y->second);
		}
		printf("\n");


		sort(result.begin(), result.end());

		for(auto y = result.begin(); y < result.end(); y++){
			printf("(%d, node = %d)", y->first, y->second);
		}
		printf("\n");

		printf("%d \n", result[0].second);

		result.clear();

		scanf("%d", &n);
	}




}