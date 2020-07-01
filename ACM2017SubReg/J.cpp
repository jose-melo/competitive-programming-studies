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

typedef struct {
	ll r, x, y;
	int id;

} bola;

vector<bola> bolas;
ll esq, dir;
int visitados[1123];

bool inter(bola a, bola b){

	double dist = sqrt((a.x - b.x)*1LL*(a.x - b.x) + (a.y - b.y)*1LL*(a.y - b.y));

	if(dist <= a.r + b.r)
		return true;

return false;
}


void dfs(bola node){


	if(visitados[node.id])
		return;

	visitados[node.id] = 1;

	esq = min(esq, node.x - node.r);	
	dir = max(dir, node.x + node.r);


	for(auto x : bolas){
		if(visitados[x.id])continue;
		
		if(inter(x, node))
			dfs(x);
	}

return;
}

int main(){

	int T;
	fastio;

	cin >> T;
	
	int N, W, L;
	while(T--){

		cin >> N >> W >> L;

		ll cont =  0;

		ll x, y, r;
		bola b;
		FI(N){
	
			cin >> x >> y >> r;
			
			b.x = x;
			b.y = y;
			b.r = r;
			b.id = i+1;

			if(b.y - b.r >= L)continue;

			bolas.pb(b);

		}
		
		FI(1002)		
			visitados[i] = 0;
			
		for(auto x : bolas){
			if(visitados[x.id])continue;
			
			esq = INF;
			dir = -1;
			dfs(x);

			
			if(esq <= 0 && dir >= W)
				cont++;

		}	
		

		cout << cont << "\n";	
		FI(1002)		
			visitados[i] = 0;
		
		bolas.clear();		
	}



}






