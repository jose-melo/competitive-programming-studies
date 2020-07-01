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

ll bit[1123456];
ll v[1123456];
int n;


void build(){

	int idx;
	for(int i = 1; i <= n; i++){
		idx = i;

		while(idx <= n){

			bit[idx] += v[i];
			idx = idx + (idx & (-idx));
		}
	}
}

void update(int pos, int x){
	
	int idx = pos;
	while(idx <= n){
		bit[idx] += x;
		idx = idx + (idx & (-idx));
	}
}

ll q(int r){

	if(r == 0)return 0;

	ll resp = 0;
	int idx = r;
	while(idx > 0){
		resp += bit[idx];
		idx = idx - (idx & (-idx));
	}
return resp;
}

ll query(int l, int r){
	return q(r) - q(l-1);
}

int main(){

	fastio;

	int q, a, b;

	cin >> n;

	FI(n)
		cin >> v[i+1];

	build();

	cin >> q;

	char op;
	FI(q){
		cin >> op >> a >> b;
		
		if(op == 'q')
			cout << query(a, b) << "\n";
		else
			update(a, b);
	}
return 0;
}









