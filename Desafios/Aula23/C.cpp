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

int v[312345];
vector<pii> resp;


void troca(int p, int q){

	resp.pb(mp(p, q));
	
	int aux = v[p];

	v[p] = v[q];
	v[q] = aux;

}


int main(){

	fastio;

	int n;

	cin >> n;

	FOR(i, 1, n + 1)
		cin >> v[i];
	

	int d = (n/2);
	int idx;
	for(idx = 1; idx <= n; idx++){
	
		if(v[idx] == idx)continue;

		if(abs(v[idx] - idx) >= d){
			troca(idx, v[idx]);
			continue;
		}
		
		if(n - idx >= d){
			troca(idx, n);
			troca(n, v[n]);
			troca(idx, n);
			continue;
		}

		if(idx - 1 >= d){
			troca(idx, 1);
			troca(1, v[1]);
			troca(1, idx);
			continue;	
		}

	}
	
	for(idx = 1; idx <= n; idx++){
	
		if(v[idx] == idx)continue;

		if(abs(v[idx] - idx) >= d){
			troca(idx, v[idx]);
			continue;
		}
		
		if(n - idx >= d){
			troca(idx, n);
			troca(n, v[n]);
			troca(idx, n);
			continue;
		}

		if(idx - 1 >= d){
			troca(idx, 1);
			troca(1, v[1]);
			troca(1, idx);
			continue;	
		}

	}
	cout << resp.size() << "\n";
	for(auto x : resp)
		cout << x.fi << " " << x.se << "\n";
	

return 0;
}


