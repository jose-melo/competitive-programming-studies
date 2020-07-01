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

int func(ll a){
	int bit = 0;
	
	
	while(((a>>bit)&1) == 0)
		bit++;
	return bit;
}


int main(){

	int n;

	unordered_map<int, int> freq;
	
	cin >> n;

	ll v[212345], v2[212345];

	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	ll soma = 0;
	for(int i = 0; i < n; i++)
		soma += func(v[i]);


	for(int i = 0; i < n; i++)
		v2[i] = soma - func(v[i]);	
	
	for(int i = 0; i < n; i++)
		freq[v2[i]]++;

	int mx = -1;	
	ll val = -1;	
	for(auto x : freq){
		if(x.second > mx){
			val = x.first;
			mx = x.second;
		}
	}
	
	vector<ll> resp;
	for(int i = 0; i < n; i++){
		if(v2[i] != val)
			resp.pb(v[i]);
	}

	cout << resp.size() << endl;

	if(resp.size() == 0)return 0;

	for(auto x : resp)
		cout << x << " ";
	cout << endl;

return 0;
}
