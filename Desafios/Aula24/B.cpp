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

vector<ll> v;
ll soma1, soma2;
int n;

int main(){

	fastio;

	cin >> n;
	
	ll a, b;
	soma1 = 0;
	soma2 = 0;
	FI(n){
		cin >> a >> b;

		soma2 += (n*b - a);

 		v.pb((a - b));	
	}

	sort(v.begin(), v.end(), greater<ll>());

	for(int i = 0; i < n; i++)
		soma1 += (i + 1)*v[i];


	cout << soma1 + soma2 << "\n";
return 0;
}







