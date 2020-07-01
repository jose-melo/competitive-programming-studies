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

int n;
int v[212345];
ll resp1, resp2;

int main(){

	cin >> n;

	FI(n)
		cin >> v[i];

	int mn = 1e9 + 10, mx = -1; 
	for(int i = 0; i < n; i++){

		if(v[i] < mn)
			mn = v[i];
		
		if(v[i] > mx)
			mx = v[i];

	}
	
	ll cont1 = 0, cont2 = 0;

	for(int i = 0; i < n; i++){
		if(v[i] == mn)
			cont1++;

		if(v[i] == mx)
			cont2++;

	}
	
	if(mn == mx){	
		cont2--;
		resp2 = cont1*cont2/2;
		cout << "0 " << resp2 << endl;
		return 0 ;
	}

	resp1 = mx - mn;
	resp2 = cont1*cont2;

	cout << resp1 << " " << resp2 << endl;
}
