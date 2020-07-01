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

int soma[112345];

int main(){

	string s;
	int n, l, r;

	cin >> s;
	
	soma[0] = 0;
	soma[1] = 0;

	FOR(i, 1, s.size())			
		if(s[i] == s[i-1])
			soma[i+1] = soma[i] + 1;
		else
			soma[i+1] = soma[i];

	cin >> n;
	
	FI(n){
		cin >> l >> r;
		cout << soma[r] - soma[l] << "\n";
	}
return 0;
}


