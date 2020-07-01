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

int main(){
	
	ll x1, x2, x3, x4, h;

	cin >> x1 >> x2 >> x3 >> x4 >> h;

	ll a1 = max(x1, x3);
	ll a2 = min (x2, x4);

	if (a1 > a2) cout << "0\n";
	else cout << (a2-a1)*h << endl;

	return 0;
}
