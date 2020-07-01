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


void troco(int a, int b){

	resp.pb(mp(a, b));

	int aux = v[b];
	
	v[b] = v[a];
	v[a] = aux;

}


int main(){

	int n;

	cin >> n;

	FI(n)
		cin >> v[i+1];

	int idx = 1;
	int d = n / 2;

	
	while(idx <= n){

		while(v[idx] == idx)idx++;
	
		if(idx > n)break;

		if(v[idx] >  idx){

			if(v[idx] - idx >= d){
				troco(v[idx], idx);	
			}
			else if(n - v[idx] >= d ){
				troco(idx, n);
				troco(v[n], n);
				troco(n, idx);
			}else if(idx - 1 >= d){
				troco(idx, 1);
				troco(1, v[1]);
				troco(1, idx);	
			}else{
				troco(idx, n);
				troco(n, 1);
				troco(1, v[1]);
				troco(1, n);

			}
		}	
		
	}	

	cout << resp.size() << "\n";

	for(auto x : resp)
		cout << x.fi << " " << x.se << "\n";


return 0;
}


