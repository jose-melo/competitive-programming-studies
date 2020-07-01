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
#define mod 998244353

int visitados[312345], cor[312345];
vector<int> listAdj[312345];
int contA, contB, n, m;
bool ok;

void dfs(int node, int opt){

	if(visitados[node] || !ok)
		return;

	visitados[node] = 1;
	
	if(opt == 1)
		contA++;
	else
		contB++;	

	for(auto x : listAdj[node]){
		if(opt == 1){
			if(cor[x] == 1)
				ok = false;
			cor[x] = 2;
			dfs(x, 2);
		}else{
			if(cor[x] == 2)
				ok = false;
		
			cor[x] = 1;
			dfs(x, 1);		
		}
	}
return;
}

ll modexp(int base, int exp){

	if(exp == 0)
		return 1;
	
	if(exp == 1)
		return base;

		
	ll R = modexp(base, exp/2) % mod;

	if(exp % 2)
		return (((R * R)%mod)* base)%mod;
return (R*R) % mod;
}



int main(){

	fastio;

	int T;

	cin >> T;

	while(T--){
			
		cin >> n >> m;
		
		int a, b;
		FI(m){
			cin >> a >> b;
			listAdj[a].pb(b);
			listAdj[b].pb(a);
		}

		FOR(i, 1, n+1){
			visitados[i] = 0;	
			cor[i] = -1;
		}

		ll cont = 0;
		ll res = 1;


		ok = true;
		for(int i = 1; i <= n && ok; i++){
			if(!visitados[i]){
				cont = 0;
				contA = 0;
				contB = 0;
				
				dfs(i, 1);
			
			 	cont = (cont + modexp(2, contA)) % mod;
				cont = (cont + modexp(2, contB)) % mod;		

				res = (res * cont) % mod;
			}	
			
		}
		
		if(!ok){
			cout << "0\n";
		}else{
			cout << res % mod << "\n";
			
		}
	
	
		FOR(i, 1, n+1){
			visitados[i] = 0;
			cor[i] = -1;
			listAdj[i].clear();	
		}

	}	
return 0;
}





