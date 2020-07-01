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

int main(){

	fastio;

	ll n, L, res = 4e18, soma = 0, aux;
	ll v[40];

	cin >> n >> L;

	FI(n)
		cin >> v[i];

	
	FI(n-1)
		v[i+1] = min(v[i+1], 2*v[i]);	
	
	
	for(int i = n-1; i >= 0; i--){
		
		int faltam = L / (1<<i);
		soma += faltam*v[i];
		L -= faltam << i;
	
		if(L <= 0)
			res = min(res, soma);
		else
			res = min(res, soma + v[i]);
	}
	
	cout << res << "\n";

return 0;
}
