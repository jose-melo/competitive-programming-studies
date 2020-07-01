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

#define LMAX 20

int pula[51234][30];
ll dist[51234][30];
vector<pii> listAdj[51234];
int ini[51234], fim[51234];
int tempo;


void dfs(int u, int pai){

	tempo++;

	ini[u] = tempo;


	pula[u][0] = pai;
	
	for(auto x : listAdj[u]){
		if(x.fi == pai)
			dist[u][0] = x.se;
	}
	
	for(int i = 1; i <= LMAX; i++){
		pula[u][i] = pula[pula[u][i-1]][i-1];
		dist[u][i] = dist[u][i-1] + dist[pula[u][i-1]][i-1];

	}

	for(auto x : listAdj[u])
		if(x.fi != pai)
			dfs(x.fi, u);

	fim[u] = tempo;
	tempo++;	
return;
}

bool eh_ancestral(int u, int v){

	if(ini[u] <= ini[v] && fim[u] >= fim[v])
		return true;

return false;	
}


ll LCA(int u, int v){

	ll resp = 0;
	int tenta_pular;

	if(eh_ancestral(u, v)){
		
		for(int i = LMAX; i >= 0; i--){
			tenta_pular = pula[v][i];
			if(tenta_pular != -1 && !eh_ancestral(tenta_pular, u)){
				resp += dist[v][i];
				v = tenta_pular;
			}
		}

		resp += dist[v][0];
		return resp;
	}

	if(eh_ancestral(v, u)){
		
		for(int i = LMAX; i >= 0; i--){
			tenta_pular = pula[u][i];
			if(tenta_pular != -1 && !eh_ancestral(tenta_pular, v)){
				resp += dist[u][i];
				u = tenta_pular;
			}
		}
		resp += dist[u][0];
		return resp;
	}

	for(int i = LMAX; i >= 0; i--){
		tenta_pular = pula[u][i];
		if(tenta_pular != -1 && !eh_ancestral(tenta_pular, v)){
			resp += dist[u][i];
			u = tenta_pular;
		}
	}

	resp += dist[u][0];
	u = pula[u][0];
	for(int i = LMAX; i >= 0; i--){
		tenta_pular = pula[v][i];
		if(tenta_pular != -1 && !eh_ancestral(tenta_pular, u)){
			resp += dist[v][i];
			v = tenta_pular;
		}
	}

	resp += dist[v][0];
return resp;
}


int main(){

	fastio;

	int n, q, T;

	cin >> T;	

	while(T--){
			cin >> n >> q;

			int u, v, w;
			FI(n){

				cin >> u >> v >> w;
				listAdj[u].pb(mp(v, w));
				listAdj[v].pb(mp(u, w));
			}

			tempo = 0;

			for(int i = 0; i <= n; i++)
				for(int j = 0; j <= LMAX; j++)
					pula[i][j] = -1;

			dfs(0, 0);

			FI(q){

				cin >> u >> v;
				
				if(u != v)
					cout << LCA(u, v) << "\n";
				else
					cout << "0\n";
			}
	}
return 0;

}







