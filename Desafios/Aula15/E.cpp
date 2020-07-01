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
#define mod 998244353

ll memo[1001][2002][4];

ll pd(int idx, int k, int fim){

	if(k < 0 || idx < 0 || fim < 0)
		return 0;

	if(memo[idx][k][fim] != -1)
		return memo[idx][k][fim];

	if(idx == 1){
		if(k > 2){
			memo[idx][k][fim] = 0LL;
			return 0;
		}

		if(k == 2){
			if(fim == 0 || fim == 3)
				memo[idx][k][fim] = 0LL;
			else
				memo[idx][k][fim] = 1LL;
			return memo[idx][k][fim];
		}

		if(k == 1){

			if(fim == 1 || fim == 2)
				memo[idx][k][fim] = 0LL;
			else
				memo[idx][k][fim] = 1LL;

			return memo[idx][k][fim];
		}	
	

	}
	
	if(fim == 0)
		memo[idx][k][fim] = pd(idx-1, k, 0) + pd(idx-1, k, 1) + pd(idx-1, k, 2) + pd(idx-1, k-1, 3);
	
	if(fim == 1)	
		memo[idx][k][fim] = pd(idx-1, k, 1) + pd(idx-1, k-1, 0) + pd(idx-1, k-1, 3) + pd(idx-1, k-2, 2);

	if(fim == 2)
		memo[idx][k][fim] = pd(idx-1, k, 2) + pd(idx-1, k-1, 0) + pd(idx-1, k-1, 3) + pd(idx-1, k-2, 1);

	if(fim == 3)
		memo[idx][k][fim] = pd(idx-1, k, 1) + pd(idx-1, k, 2) + pd(idx-1, k, 3) + pd(idx-1, k-1, 0);

	while(memo[idx][k][fim] < 0)
		memo[idx][k][fim] += mod;

	memo[idx][k][fim] = memo[idx][k][fim] % mod;



return memo[idx][k][fim];
}

int main(){

	fastio;

	int n, k;

	cin >> n >> k;
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
			for(int k = 0; k <= 3; k++)
				memo[i][j][k] = -1;
	
	ll res = (pd(n, k, 0) + pd(n, k, 1) + pd(n, k, 2) + pd(n, k, 3)) % mod;

	cout << res << "\n";
return 0;
}


