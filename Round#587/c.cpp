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


int n, m;
vector<pii> arestas;
vector<int> listAdj[10];
int grafo[10];
ll dominoh;
int jausei[30];
int resp = 0;
vector<pii> dominos;


int solve(int are){

	cout << resp << " " << are << endl;
	if(resp == m){
		return resp;
	}


	int cont;
	if(are == m){
		cont = 0;

		for(int k = 0; k < dominos.size(); k++)
			if(jausei[k] == 1)
				cont++;
				
		return cont;
	}
	int a, b, c, d;
	a = arestas[are].fi;
	b = arestas[are].se;
	
	for(int i = 0; i <  dominos.size(); i++){
		
		if(jausei[i] == 1)continue;
		c = dominos[i].fi;
		d = dominos[i].se;
		bool ok = true;
		for(auto adjA : listAdj[a])
			if(adjA == b)continue;
			else if(grafo[adjA] != c && grafo[adjA] != 0)
				ok = false;	

		for(auto adjB : listAdj[b])
			if(adjB == a)continue;
			else if(grafo[adjB] != d && grafo[adjB] != 0)
				ok = false;
		
		if(ok){
			grafo[a] = c;
			grafo[b] = d;
			
			jausei[i] = 1;
			resp = max(resp, solve(are+1));
						
			grafo[a] = 0;
			grafo[b] = 0;
			jausei[i] = 0;
		}

		ok = true;				
		for(auto adjA : listAdj[a])
			if(adjA == b)continue;
			else if(grafo[adjA] != d && grafo[adjA] != 0)
				ok = false;

		for(auto adjB : listAdj[b])
			if(adjB == a)continue;
			else if(grafo[adjB] != c && grafo[adjB] != 0)
				ok = false;
		
		if(ok){		
			grafo[a] = d;
			grafo[b] = c;
			
			jausei[i] = 1;
			resp = max(resp, solve(are+1));
						
			grafo[a] = 0;
			grafo[b] = 0;
			jausei[i] = 0;
		}		
	}

}


int main(){
	
	cin >> n >> m;
			int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		arestas.pb(mp(a, b));
		listAdj[a].pb(b);
		listAdj[b].pb(a);
	}

	for(int i = 1; i <= 6; i++)
		for(int j = i; j <= 6; j++)
			dominos.pb(mp(i, j));

	solve(0);

	cout << resp << endl;

	return 0;

}





