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
#define ti cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int a[1234];
set<int> t[4*31234];
int n;

void build(int v, int l, int r) {
    if (l == r) {
        t[v].insert(a[l]);
    	return;
	} 
	
    int m = (l + r) / 2;
    
	build(v*2, l, m);
    build(v*2+1, m+1, r);
    
	for(auto x : t[2*v])
		t[v].insert(x);

	for(auto x : t[2*v + 1])
		t[v].insert(x);

}

set<int> query(int v, int a, int b, int l, int r) {
    set<int> x, y;
	if (l > r) 
        return x;
    if (l == a && r == b) {
        return t[v];
    }

    int m = (a + b) / 2;
    x = query(v*2, a, m, l, min(r, m));
	y = query(v*2+1, m+1, b, max(l, m+1), r);

	for(auto k : x)
		y.insert(k);
return y;
}

int main(){

	fastio;

	cin >> n;

	FOR(i, 1, n+1)
		cin >> a[i];

	build(1, 1, n);

	int q, a, b;
	cin >> q;
	FI(q){
		cin >> a >> b;

		cout << query(1, 1, n, a, b).size() << "\n";

	}
return 0;
}
