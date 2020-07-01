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


	int n, k;
	int v[312345];
	
	cin >> n >> k;

	FI(n)
		cin >> v[i];
	
	vector<int> resp;

	FI(n-1)
		resp.pb(v[i+1] - v[i]);
	
	sort(resp.begin(), resp.end());
	

	ll res = 0;
	k--;
	for(int i = 0; i < resp.size() - k; i++)
		res += resp[i];

	cout << res << "\n";
	
return 0;
}


