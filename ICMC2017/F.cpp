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

ll soma[112345];
vector<ll> adj[112345];
ll brilho[112345], certo[112345], certov[112345];
ll n, m, w;

ll res;

void BFS(){
	
	ll cont, x;

	queue<ll> fila;

	fila.push(1);

	cont = 0;
	while(!fila.empty()){
		x = fila.front();
		fila.pop();	

		cont++;
		
		certo[x] = cont;
		certov[cont] = x;

		for(auto y : adj[x])
			fila.push(y);

	}
	
return ;
}


int main(){

	fastio;

	cin >> n >> m >> w;
	
	brilho[1] = w;

	ll u, v;
	
	FI(n-1){
		cin >> u >> v >> w;
		adj[v].pb(u);
		brilho[u] = w;
	}

	BFS();

	FOR(i, 1, n+1){
		soma[i] = soma[i-1] + brilho[certov[i]];
	}



	ll cand, h, l, r;
	ll somaTotal = 0;

	ll alt = log2(n);

	FI(m){
		cin >> cand;
		
		cand =  certo[cand];

		h = log2(cand);	
		res = -1;
		for(int p = 0; p < h; p++)
			res = max(res, soma[(1<<(p+1)) - 1] - soma[(1<<p)-1]);
		
		l = r = cand;
		for(int p = h; p <= alt; p++){
			
			ll fim =  (1<<(p+1)) - 1;
		
			if(fim > n)
				fim = n;

			somaTotal = soma[fim] - soma[(1<<p)-1];

			res = max(res, somaTotal - (soma[r] - soma[l-1]));
			
			l = 2*l;
			r = 2*r + 1;		
			if(r > n) r = n;

		}
		
		cout << res << "\n";

	}

return 0;
}







