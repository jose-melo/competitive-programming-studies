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


vector<int> listAdj[212345];
int visitados[212345];
ll soma[212345];
ll ans[212345];
ll cont[212345];
ll odd[212345];
ll impar[212345];
ll contaImpar;
ll n;
ll somaTotal, somaImpar;

void dfs1(int node){

	if(visitados[node])
		return;

	visitados[node] = 1;
	
	for(auto x : listAdj[node]){
		if(visitados[x])continue;
		dfs1(x);
	
		cont[node] += cont[x];	
		soma[node] += soma[x] + cont[x];
	}
	
return;
}

void dfs3(int node){

	if(visitados[node])
		return;
	
	visitados[node] = 1;
	
	
	for(auto x : listAdj[node]){

		if(visitados[x])continue;
		dfs3(x);		

		impar[node] -= impar[x];	
	}

	impar[node] += cont[node] - 1;

return;
}

void dfs2(int node){


	if(visitados[node])
		return;

	visitados[node] = 1;

	for(auto x : listAdj[node]){
		if(visitados[x])continue;

		ans[x] = ans[node] - 2*cont[x] + n;
		odd[x] = n - odd[node];
		dfs2(x);
	}
return;
}

void limpa(){
	for(int i = 0; i <= n; i++)
		visitados[i] = 0;
}


int main(){

	cin >> n;

	FI(n+1){
		cont[i] = 1;
	}

	int a, b;
	FI(n-1){
		cin >> a >> b;
		listAdj[a].pb(b);
		listAdj[b].pb(a);
	}

	dfs1(1);
	limpa();

	ans[1] = soma[1];

	dfs3(1);
	limpa();	

	odd[1] = impar[1];


	dfs2(1);
	limpa();

	somaTotal = 0;
	somaImpar = 0;
	for(int i = 1; i <= n; i++){

		somaTotal += ans[i];
		somaImpar += odd[i];

	}

	cout << ((somaTotal/(2*1LL)) + (somaImpar/(2*1LL)))/(2*1LL) << "\n";


return 0;
}






