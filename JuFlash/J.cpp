#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int n, m;
int v[112345];
ll soma[112345];


int main(){

	fastio;

	cin >> n >> m;

	
	
	
	soma[0] = 0;

	FOR(i, 1, n+1){
		cin >> v[i];
		soma[i] = soma[i-1] + v[i];
	}
	
	if(n == 1){
		cout << m << "\n";
		return 0;
	}
	
	ll res;

	FOR(i, 1, n+1){

		res = max(soma[n] - soma[i], soma[n] - v[i] + m);
	
		res = max(res, soma[i-1]);

		cout << res << " ";
	}

	cout << "\n";
	
return 0;
}




