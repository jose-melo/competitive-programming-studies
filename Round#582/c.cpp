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


	int T;

	cin >> T;
	
	ll n, m, k;
	while(T--){

		cin >> n >> m;

		k = n / m;

		ll soma1 = 0;
		ll resp = 0;	

		for(int i = 1; i <= 10; i++)
			soma1 += (m*i) % 10;

		resp += soma1 * (k/10);

		for(int i = 0; i < k%10; i++)
			resp += (m*(i + 1)) % 10;

		cout << resp << "\n";


	}
return 0;
}







