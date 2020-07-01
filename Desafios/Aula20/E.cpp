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

vector<int> listAdj[200001];
int soma[200001], impar[2000001];
int n, contaImpar, somaTotal;

int BFS(){

	int cont = 0;

	queue<pii> fila;
	fila.push(mp(1, 0));

	while(!fila.empty()){
		pii noh = fila.front();
		fila.pop();
		
		if(noh.se % 2)
			impar[1]++;

		cont += noh.se;
		for(auto x : listAdj[noh.fi])
			fila.push(mp(x, noh.se + 1));
	}
return cont;
}

int dfs(int node, int* visitados, int pai){

	int cont = 0, contDesc;
	if(listAdj[node].size() == 1 && listAdj[node][0] == pai)
		return 0;

	if(visitados[node])
		return 0;

	visitados[node] = 1;

	for(auto x : listAdj[node]){
		cont++;	
		contDesc = dfs(x, visitados, node);
		
		cont += contDesc;

		soma[node] = soma[x] + (2*cont) - n + 2;
		
		impar[x] = n - impar[node];

		contaImpar += impar[x];
		somaTotal += soma[x];		

	}
}


int main(){

	int visitados[200001];
	fastio;

	cin >> n;

	FI(n+1)
		visitados[i] = 0;
	int a, b;
	for(int i = 1; i <= n-1; i++){
		cin >> a >> b;
		listAdj[a].pb(b);
		listAdj[b].pb(a);
	}
	
	for(int i = 1; i <= 4; i++){
		cout << "node " << i << ": ";
		for(auto x : listAdj[i])
			cout << x << " ";
		cout << "\n";
	}

	soma[1] = BFS();

	contaImpar = impar[1];
	somaTotal = soma[1];
	dfs(1, visitados, 0);

	cout << (somaTotal / 2) + (contaImpar / 2) << "\n";
return 0;
}









