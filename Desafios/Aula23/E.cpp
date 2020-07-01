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

ll seg[4 * ((1<<17) + 100)];
ll v[((1<<17) + 1000)];


void build(int node, int l, int r, bool opt){
	
	if(l == r){
		seg[node] = v[l];
		return;
	}
	
	int mid = (l + r) / 2;

	build(2*node, l, mid, !opt);
	build(2*node + 1, mid+1, r, !opt);

	if(opt)
		seg[node] = seg[2*node] | seg[2*node + 1];
	else
		seg[node] = seg[2*node] ^ seg[2*node + 1];
return;
}

void update(int node, int l, int r, int pos, int val, bool opt){

	if(l == r){
		seg[node] = val;
		return;
	}

	int mid = (l + r) / 2;

	if(pos <= mid)
		update(2*node, l, mid, pos, val, !opt);
	else
		update(2*node + 1, mid + 1, r, pos, val, !opt);

	if(opt)
		seg[node] = seg[2*node] | seg[2*node + 1];
	else
		seg[node] = seg[2*node] ^ seg[2*node + 1];
return;
}

int main(){

	ll n, m, p, b;

	cin >> n >> m;

	FI(1<<n)
		cin >> v[i+1];
	
	build(1, 1, 1<<n, n % 2);


	FI(m){

		cin >> p >> b;
		update(1, 1, 1<<n, p, b, n % 2);	
	
		cout << seg[1] << "\n";

	}
return 0;
}






