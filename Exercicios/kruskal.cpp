#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define ii pair<int, int>

vector<int> pais, ordem;
vector<pair<ll, ii>> edges;


void INIT(int n){

	pais.assign(n+1, 0);
	ordem.assign(n, 0);
	for(int i = 0; i <= n; i++)
		pais[i] = i;
}

int find(int i){

	while(i != pais[i])
		i = pais[i];

return pais[i];
}

bool isSameSet(int i, int j){
	return find(i) == find(j);
}

void Union(int x, int y){

	if(!isSameSet(x, y)){
		int i = find(x);
		int j = find(y);

		if(ordem[x] > ordem[y]){
			pais[y] = x;
		}else{
			pais[x] = y;
			if(ordem[x] == ordem[y])
				ordem[y]++;
		}
	}
}

ll kruskal(int n){

	ll cont;

	INIT(n);

	sort(edges.begin(), edges.end());

	for(int i = 0; i < n; i++){
		if(!isSameSet(edges[i].second.first, edges[i].second.second)){
			cont += edges[i].first;
			Union(edges[i].second.first, edges[i].second.second);
		}
	}

return cont;	
}

int main(){

return 0;
}


