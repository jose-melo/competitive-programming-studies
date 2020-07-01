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

int visitados[112345];
int cont_n, cont_m;
vector<int> listAdj[112345];

void dfs(int node){

	if(visitados[node])
		return;
	cont_n++;
	visitados[node] = 1;

	for(auto x : listAdj[node]){
		cont_m++;
		dfs(x);
	}
return ;
}

int main(){


	int n, m;

	cin >> n >> m;
	int a, b;

	FI(m){
		cin >> a >> b;
		listAdj[a].push_back(b);
		listAdj[b].push_back(a);
	}
	
	int res = 0;
	FOR(i, 1, n+1){
		if(!visitados[i]){
			cont_m = 0;
			cont_n = 0;
			dfs(i);
			cont_m /= 2;
			if(cont_m == cont_n - 1)
				res += 1;	
		}
	}

	cout << res << "\n";
return 0;
}
