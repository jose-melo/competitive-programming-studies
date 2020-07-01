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

ll n;

int main(){
	
	ll res;

	cin >> n;

	if(n % 2)
		res = 6 * (((n+1)/2) * n);
	else
		res = 6 * ((n+1) * (n/2));

	res++;

	cout << res << "\n";
return 0;
}

