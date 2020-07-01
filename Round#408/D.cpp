#include <bits/stdc++.h>

using namespace std;

#define MAX_N 301000
#define ll long long int
#define ii pair<int, int>

vector <ii> listAdj[MAX_N];
int visitados[MAX_N];
vector<int> excluidos;
int d;

void dfs(int node, int dist){

	if(visitados[node] == 1)
		return;

	if(visitados[node] == 0)
		visitados[node] = 1;

	if(dist > d)
		return;

	for(auto x = listAdj[node].begin(); x < listAdj[node].end(); x++){

		if(visitados[x->first] == 1 || visitados[x->first] == 2){
			excluidos.push_back(x->second);
			continue;
		}else{
			if(dist+1 < d)
				dfs(x->first, dist++);
		}
	}

}





