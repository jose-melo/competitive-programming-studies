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

	ll r, x, y, x_final, y_final, res = 0;

	long double dist;

	cin >> r >> x >> y >> x_final >> y_final;

	ll aux1, aux2;	
	
	aux1 = (x - x_final) * (x - x_final);
	aux2 = (y - y_final) * (y - y_final);

	dist = sqrt(aux1 + aux2);	

	res = ceil(dist / (2*r));

	

	cout << res << "\n";
return 0;
}




