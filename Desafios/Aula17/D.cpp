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
#define mod 1000000007

int pais[112345];
int ordem[112345];
int tam[112345];
vector<pii> listAdj;
int n, k;
int visitados[112345];

void build(){

	FOR(i, 1, n+1){
		pais[i] = i;
		ordem[i] = 1;
		tam[i] = 1;
	}
}

int find(int node){

	if(pais[node] == node)
		return node;
	
	pais[node] = find(pais[node]);	
return pais[node];
}

bool isSameSet(int a, int b){
	return find(a) == find(b);	
}

void UNION(int a, int b){

	int x, y;

	if(!isSameSet(a, b)){
		
		x = find(a);
		y = find(b);	

		if(ordem[x] > ordem[y]){
			pais[y] = x;
			tam[x] += tam[y];	
	
		}else{
			pais[x] = y;			
		
			tam[y] += tam[x];
	
			if(ordem[x] == ordem[y])
				ordem[y]++;
		}
	}
}

ll modexp(int base, int exp){
	
	if(exp == 0)return 1;
	if(exp == 1)return base;

	ll R = modexp(base, exp/2) % mod;

	if(exp % 2)
		return (((R*R) % mod)*base) % mod;
return (R*R) % mod;
}



int main(){

	cin >> n >> k;
	
	int a, b, c;

	FI(n-1){
		cin >> a >> b >> c;
		if(c == 0)
			listAdj.pb(mp(a, b));
	}

	build();

	for(auto x : listAdj){
		int i = x.fi;
		int j = x.se;
		UNION(i, j);
	}

	ll res = modexp(n, k) % mod;
	int tamanho;
	FOR(i, 1, n+1){
		int root = find(i);
		
		if(visitados[root]) continue;

		res -= (modexp(tam[root], k) % mod); 	
		visitados[root] = 1;
	}

	while(res < 0)
		res += mod;		

	cout << res % mod << "\n"; 
return 0;
}


