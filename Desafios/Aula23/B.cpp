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

ll gcd(int a, int b){
	
	if(a % b == 0)
		return b;

return gcd(b, a % b);
}

int main(){

	ll n, k;

	cin >> n >> k;

	if(k > 1000){
		cout << "No\n";
		return 0;
	}

	n++;
	for(int i = 1; i < k; i++){
		for(int j = i + 1; j <= k; j++){
			ll div = (i * j) / gcd(i, j);
			if(n % div != 0){
				cout << "No\n";
				return 0;
			}
		}
	}

	cout << "Yes\n";

return 0;
}




