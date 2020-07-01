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
#define mod 1000000007

int memo[60][60];
string s;
int somaAcc[60];

int pd(int l, int r){

	if(l == r)
		return 1;

	if(memo[l][r] != -1)
		return memo[l][r];

	memo[l][r] = 0;
	for(int p = l; p <= r; p++)
		for(int q = r; q > p; q--)
			if(somaAcc[p] - somaAcc[l-1] == somaAcc[r] - somaAcc[q-1])
				memo[l][r] =  ((memo[l][r] % mod) + (pd(p+1, q-1) % mod))%mod;	

	memo[l][r]++;
	memo[l][r] = memo[l][r] % mod;
	
return memo[l][r] % mod;
}

int main(){

	int T;

	cin >> T;

	while(T--){

		cin >> s;

		somaAcc[0] = 0;

		FOR(i, 0, s.size()+1)
			somaAcc[i+1] = somaAcc[i] + (s[i] - '0');

		FI(s.size() + 2)
			FOR(j, 0, s.size() + 2)
				memo[i][j] = -1;

		
		ll resp = pd(1, s.size());
		resp = resp % mod;

		while(resp < 0)
				resp += mod;

		cout << resp << "\n";
	
	
		FOR(i, 0, 52)
			somaAcc[i] = 0;
	}





}









