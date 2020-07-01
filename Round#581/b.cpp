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

	
	int n, l, r;

	cin >> n >> l >> r;

	ll soma1 = 0;
	ll soma2 = 0;

	for(int i = 0; i < l; i++)
		soma1 += pow(2, i);
	
	for(int i = 0; i < r; i++)
		soma2 += pow(2, i);

	ll respMin = (n - l) + soma1;

	ll respMax = (n - r) * pow(2, r-1) + soma2;

	cout << respMin << " " << respMax << endl;
return 0;
}






