#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back


int main(){


	ll N;
	vector<ll> v;

	cin >> N;

	ll aux;
	f(5){
		cin >> aux;
		v.pb(aux);
	}

	sort(v.begin(), v.end());

	ll mn = v[0];

	aux = N / mn;

	if(N > mn && N % mn != 0)
		aux++;

	if(N >= mn)
		aux--;

	cout << 5 + aux << endl;

return 0;
}
