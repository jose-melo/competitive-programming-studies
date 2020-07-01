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

ll memo[11234][30], custo[30][30];

ll pd(int K, int letra) {
	
	if (K == 1)
		return 0;

	if (memo[K][letra] != -1) 
		return memo[K][letra];

	ll res = INF;
	for (int i = 0; i < 26; i++)
		res = min(res, pd(K-1, i) + custo[i][letra]);
	memo[K][letra] = res;
	return memo[K][letra];
}

int main(){
	
	fastio;

	int K;
	cin >> K;
	
	FI(26){
		for (int j = 0; j < 26; j++){
			cin >> custo[i][j];
		}
	}
	for (int i = 0; i < 11234; i++)
		for (int j = 0; j < 30; j++)
			memo[i][j] = -1;

	ll resp = INF;
	FI(26)
		resp = min (resp, pd(K, i));

	cout << resp << endl;

	return 0;

}
