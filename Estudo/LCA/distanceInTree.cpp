#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int ini[51234], fim[51234];
int tempo;
int pula[51234][20];
vector<int> listAdj[51234];
int pais[51234];
int pesos[51234][51234];

void dfs(int v, int pai){

	int x;

	tempo++;
	ini[v] = tempo;

	pula[v][0] = pai;

	for(int i = 1; i <= 20; i++){
	
//		cout << "v = " << v << " i = " << i << " pula["<<v<<"]["<<i-1<<"] = " << pula[v][i-1] << endl;
		pula[v][i] = pula[pula[v][i-1]][i-1];
	}
	for(auto x : listAdj[v]){	
		if(x != pai)
			dfs(x, v);

	}

	fim[v] = tempo;
	tempo++;
}

bool eh_ancestral(int u, int v){
	return ini[u] <= ini[v] && fim[u] >= fim[v];
}


int LCA(int a, int b){
	
	if (eh_ancestral(a, b))
		return a;

	if (eh_ancestral(b, a))
		return b;

	int tenta_pular;
	for(int i = 20; i >= 0; i--){
		tenta_pular = pula[a][i];
		if(tenta_pular != -1 && !eh_ancestral(tenta_pular, b))
			a = tenta_pular;
	}
return pula[a][0];
}


int main(){

	int n, q;

	int u, v, w;
	int aux;
	cin >> n;

	FI(n-1){
		cin >> u >> v >> w;
		listAdj[u].pb(v);	
		listAdj[v].pb(u);	

		pesos[u][v] = pesos[v][u] = w;

		int aux;
		if(u > v){
			aux = u;
			u = v;
			v = aux;
		}
		pais[v] = u;
	}

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 20; j++)
			pula[i][j] = -1;
		ini[i] = fim[i] = 0;
	}

	tempo = 0;
	dfs(0,0);
	cin >> q;

	FI(q){
		cin >> u >> v;

		w = LCA(u, v);
		cout << "w = " << w << endl;
		aux = u;
		int soma = 0;
		while(aux != w){
			soma += pesos[aux][pais[aux]];
			cout << "aux = " << aux << "pais[aux] = " << pais[aux] << " peso = " << pesos[aux][pais[aux]] << endl;
			aux = pais[aux];
		}
	
		aux = v;
		while(aux != w){
			soma += pesos[aux][pais[aux]];
			aux = pais[aux];
		}

		cout << soma << endl;
	
	}





}







