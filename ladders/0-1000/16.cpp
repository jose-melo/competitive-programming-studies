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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int v[112345];
int k, l, m ,n, d;

int main(){
	
	cin >> k >> l >> m >> n >> d;

	memset(v, 0, sizeof(v));	

	for(int i = k; i <= d; i+=k)
		v[i] = 1;
	
	for(int i = l; i <= d; i += l)
		v[i] = 1;
	
	for(int i = m; i <= d; i += m)
		v[i] = 1;

	for(int i = n; i <= d; i += n)
		v[i] =1;


	int cont = 0;	
	for(int i = 1; i <= d; i++)
		if(v[i] == 1)
			cont++;

	cout << cont << endl;

}


