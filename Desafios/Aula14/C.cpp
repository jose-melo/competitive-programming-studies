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

int n, cont;
map<ll, int> v;
ll tradutor[200];
int visitados[200];
vector<ll> listAdj[200];
vector<ll> res;

void dfs(int node){

	if(visitados[node])
		return;

	visitados[node] = 1;
	cont++;

	for(auto x : listAdj[node])
		dfs(x);
return ;
}

void resolve(int node){

	if(visitados[node])
		return;

	visitados[node] = 1;
	
	res.push_back(tradutor[node]);
	
	for(auto x : listAdj[node])
		resolve(x);

return;
}

void limpa(){

	FI(n)
		visitados[i] = 0;
}


int main(){

	cin >> n;
	ll aux;	
	FI(n){
		cin >> aux;
		v.insert(mp(aux, i));	
		tradutor[i] = aux;
	}
	FI(n){
		if(v.find(2*tradutor[i]) != v.end())
			listAdj[i].pb(v[2*tradutor[i]]);
		if(tradutor[i] % 3 == 0 && v.find(tradutor[i] / 3) != v.end())
			listAdj[i].pb(v[tradutor[i]/3]);	
	}

	FI(n){
		cont = 0;
		dfs(i);
		limpa();
		if(cont == n){
			resolve(i);
			
			for(auto x : res)
				cout << x << " ";
			cout << "\n";
			return 0;
		}
	}	
return 0;
}

