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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int main(){

	int n;
	vector<pii> v;
	cin >> n;
	
	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.pb(mp(x, y));
	}


	int a, b, c, d, cont = 0;
	for(int i = 0; i < n; i++){
		a = b =c = d = 0;
		for(int j = 0; j < n; j++){
			if(v[j].fi > v[i].fi && v[j].se == v[i].se)a = 1;
			if(v[j].fi < v[i].fi && v[j].se == v[i].se)b = 1;
			if(v[j].fi == v[i].fi && v[j].se < v[i].se)c = 1;
			if(v[j].fi == v[i].fi && v[j].se > v[i].se)d = 1;
		}

		if(a&b&c&d)
			cont++;

	}

	cout << cont << endl;


}
