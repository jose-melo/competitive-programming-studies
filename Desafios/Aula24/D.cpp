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

int bit[31234];
int guarda[1123456];
int v[312345];
int n;
map<pii, int> res;
vector<pii> queries;

int q(int r){
	
	int resp = 0;
	int idx = r;
	while(idx > 0){
		resp += bit[idx];
		idx = idx - (idx & (-idx));
	}

return resp;
}

int query(int l, int r){
	return q(r) - q(l-1);
}

void update(int pos, int del){

	if(pos == 0)return;

	int idx = pos;

	while(idx <= n){
		bit[idx] += del;
		idx = idx + (idx & (-idx));
	}

}


int main(){

	fastio;

	int q;
	int input[312345];
	cin >> n;

	FOR(i, 1, n+1)
		cin >> v[i];

	cin >> q;	
	int a, b;
	vector<pii> aux;
	FI(q){
		cin >> a >> b;
		queries.pb(mp(b, a));
		aux.pb(mp(a, b));
	}

	sort(queries.begin(), queries.end());
	
	vector<pii>::iterator it = queries.begin();

	for(int i = 1; i <= n; i++){

		update(guarda[v[i]], -1);
		update(i, 1);
		guarda[v[i]] = i; 
	/*
		cout << "i = " << i << endl;
		for(int i = 1; i <= n; i++)
			cout << "bit["<<i<<"] = " << bit[i] << endl;
		cout << "\n\n";*/

		while(it->first == i){
			res[mp(it->second, it->first)] = query(it->second, it->first);
			it++;
		}
	}

	for(auto x : aux)
		cout << res[mp(x.fi, x.se)] << "\n";

	
return 0;
}






