#include <bits/stdc++.h>
using namespace std;
vector<int> vizinho[3123];
int componente[3123];
int cont;

void BFS(int x){
	queue< pair<int, int> >  fila;
	fila.push(make_pair(x, 0));
	componente[x] = 1;
	int atual = 0;
	while (!fila.empty()){
		pair<int, int> v = fila.front();
		fila.pop();
		for (int i = 0; i < vizinho[v.first].size(); i++){
			int u = vizinho[v.first][i];
			if(componente[u] == -1){
				componente[u] = 1;
				fila.push(make_pair(u, v.second+1));
				if (v.second+1 > cont) cont = v.second+1;
			}
		}
	}
}

int main(){
	int n, m, aux1, aux2;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> aux1 >> aux2;
		vizinho[aux1].push_back(aux2);
		vizinho[aux2].push_back(aux1);
	}
	for (int i = 0; i < 3120; i++) componente[i] = -1;
	for (int i = 1; i <=n; i++){
		BFS(i);
		for (int i = 1; i <= n; i++){
			if (componente[i] == -1){
				cout << "=[\n";
				return 0;
			}
			componente[i] = -1;
		}
	}
	cout << "=] " << cont << endl;
	return 0;
}
