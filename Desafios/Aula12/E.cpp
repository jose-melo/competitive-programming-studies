#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (ll i=a;i<n;i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on false
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)


ll l, r;

ll mongol(){

	ll m = -1;

	FOR(i, l, r+1)
		FOR(j, i, r+1)
			m = max(m, i^j);

return m;
}



int main(){

	fastio;
	
	ll resposta = 0LL;
	ll idx = 0LL;

	cin >> l >> r;
	ll diff = r - l;
	
	ll pot2 = 1LL;
	while(pot2 <= diff){
		resposta += 1LL<<idx;
		idx++;
		pot2 = (1LL<<idx);
	}
	while(pot2 <= r){
		if( (l&(1LL<<idx)) ^ (r&(1LL<<idx)) ){
			resposta += pot2;
		}
		idx++;
		pot2 = (1LL<<idx);
	}
	cout << resposta << "\n";
return 0;
}
