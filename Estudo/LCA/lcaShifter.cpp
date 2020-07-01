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

/*
	A ideia aqui é preprocessar a árvore de tal forma que possamos dar saltos de potências de 2. Ao mesmo tempo, rodando uma dfs e guardando o tempo de início e o final de cada nó, é fácil decidir se um determinado nó é ancestral ou não de outro. Assim, após o pré-processamento, só precisamos dar saltos com um nó, em um tempo proporcional à log(N)
*/

#define MAX 112345
#define LMAX 20

int pula[MAX][LMAX+4];
int ini[MAX], fim[MAX];
int tempo;
vector<int> listAdj[MAX];

void dfs(int v, int pai){
	
	tempo++;

	ini[v] = tempo;

	pula[v][0] = pai;

	for(int i = 1; i <= LMAX; i++){
		//Um pulo 2^i pra cima são dois pulos 2^i-1 e 2^i-1
		//cout << "i = " << i << " v = " << v << "pula[v][i-1] = " << pula[v][i-1]  <<endl;
		pula[v][i] = pula[pula[v][i-1]][i-1];
	}

	for(auto x : listAdj[v]){
		if(x != pai)
			dfs(x, v);
	}

	fim[v] = tempo;
	tempo++;

return;
}


bool eh_ancestral(int u, int v){

	if(ini[u] <= ini[v] && fim[u] >= fim[v])
		return true;
return false;
}

int LCA(int a, int b){

	int tenta_pular;

	if(eh_ancestral(a, b))
		return a;
	
	if(eh_ancestral(b, a))
		return b;

	for(int i = LMAX; i >= 0; i--){
		tenta_pular = pula[a][i];
		if(tenta_pular != -1 && !eh_ancestral(tenta_pular, b))
			a = tenta_pular;
	}
return pula[a][0];
}


int main(){

	fastio;

	int n, m, q, a;

	cin >> n;

	FI(n){
		cin >> m;

		for(int j = 0; j < m; j++){
			cin >> a;
			listAdj[i].pb(a);
		}
	}

	for(int i = 0; i < MAX; i++){
		for(int j = 0; j <= LMAX; j++)
			pula[i][j] = -1;
		ini[i] = 0;
		fim[i] = 0;
	}
	tempo = 0;

	dfs(0, 0);

	cin >> q;
	int b;

	FI(q){
		cin >> a >> b;	
		cout << LCA(a, b) << endl;
	
	}

return 0;
}
