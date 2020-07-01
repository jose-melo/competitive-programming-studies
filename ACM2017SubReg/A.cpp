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

ll pot(ll b, ll exp){
	ll resp = 1;
	if (exp == 0) return 1;
	for (int i = 0; i < exp; i++){
		resp *= b;
	}
	return resp;
}

int main(){

	fastio;
		
	int T;
	cin >> T;
	//cout << pot(2, 4) << endl;
	while(T--){
		ll n, x;
		cin >> n >> x;

		ll digf = n;
		ll resp = 0;
		for(int i = 1; i <= 16; i++){
			ll l = pot(10, i-1);
			ll r = pot(10, i) - 1;
			if (x >= l && x <= r){
				if ((digf/i + x) > r){
					digf -= (r-x+1)*i;
					resp += r-x+1;
					x = r+1;
				}
				else{
					if(digf%i){
						cout << "-1\n";
						break;
					}
					resp += digf/i;
					cout << resp << "\n";
					break;
				}
			}
		}
	}

	return 0;
}
