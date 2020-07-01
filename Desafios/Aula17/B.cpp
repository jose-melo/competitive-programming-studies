#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int 
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

	ll x, y;
	double a, b, c;

	cin >> x >> y;

	a = log(x);
	b = log(y);
	c = x / (1.0*y);
	b = b*c;

	if(a < b)
		cout << "<\n";

	if(a > b)
		cout << ">\n";

	if(a == b)
		cout << "=\n";
	
return 0;
}

