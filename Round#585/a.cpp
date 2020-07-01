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

int a, b, ka, kb, n;

int main(){

	cin >> a >> b >> ka >> kb >> n;

	if(ka > kb){
		swap(ka, kb);
		swap(a, b);
	}
	int mn = n;

	mn -= ((ka-1)*a + (kb-1)*b);


	int mx = min(n/ka, a);

	n -= mx*ka;
	
	mx += min(n/kb, b);

	if (mn < 0)
		mn = 0;

	cout << mn << " " << mx << endl;

return 0;
}



