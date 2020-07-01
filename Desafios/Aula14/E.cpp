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
#define debugv(v) for(auto x : v) cout << x << endl;

vector<int> filhos[312345];
int tipo[312345];
int folhas[312345];
int pd[312345];

int contaFolhas(int noh){

	int cont = 0;

	if(filhos[noh].empty()){
		folhas[noh] = 1;
		return folhas[noh];
	}
	for(auto x : filhos[noh])
		cont += contaFolhas(x);
	
	folhas[noh] = cont;
return cont;
}



int resolve(int node){

	if(pd[node] != -1)
		return pd[node];

	if(filhos[node].empty()){
		pd[node] = 1;
		return pd[node];
	}
	
	if(tipo[node] == 1){
		
		int qntosPerdeu = 4e5;

		for(auto x : filhos[node])
			qntosPerdeu = min(qntosPerdeu, folhas[x]- resolve(x));
		
		pd[node] = folhas[node] - qntosPerdeu;
	
		return pd[node];
	}

	int contMinFora = 0;	

	for(auto x : filhos[node])	
		contMinFora += resolve(x) - 1;

	pd[node] = 1 + contMinFora;

return pd[node];
}

int main(){

	fastio;
	
	int n, aux;

	cin >> n;
	
	FOR(i, 1, n+1){
		cin >> aux;
		tipo[i] = aux;
	}
	
	FOR(i, 2, n+1){
		cin >> aux;
		filhos[aux].pb(i);
	}

	FOR(i, 1, n+1){
		pd[i] = -1;
	}

	contaFolhas(1);

	int resposta = resolve(1);

	cout << resposta << "\n";

return 0;
}
