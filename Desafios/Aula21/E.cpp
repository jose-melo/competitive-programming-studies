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

int input[112345];
int n;

int main(){

	fastio;

	cin >> n;

	FI(n)
		cin >> input[i+1];
	
	ll resp = 0;
	FOR(i, 1, n+1)
		if(input[i] > input[i-1])
			resp += (input[i] - input[i-1])*1LL*(n - input[i] + 1);
		else if(input[i] < input[i-1])
			resp += (input[i])*1LL*(input[i-1] - input[i]);

	cout << resp << "\n";
return 0;
}





