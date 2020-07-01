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

ll soma;
ll somaMax;
int pesos[112345];
vector<int> listAdj[112345];
int visitados[112345];
int ini;
int cont, n;

void dfs(int noh){

	if(visitados[noh] == 0)



}



int main(){

	int m;

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> pesos[i];

	int a, b, s;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		listAdj[a].pb(b);
		listAdj[b].pb(a);
	}

	cin >> s;

	soma = pesos[s];
	somaMax = -1;
	
	dfs(s, -1);

	cout << somaMax << endl;

return 0;
}


