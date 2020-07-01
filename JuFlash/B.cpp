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


map<ll, int> freq;
ll input[112345];
int n, m;
vector<int> perm;

int main(){

	fastio;

	cin >> n >> m;

	FOR(i, 1, n+1){
		cin >> input[i];
		input[i] %= m;
	}		

	
	ll aux;
	FOR(i, 1, n+1){
		cin >> aux;
		perm.pb(aux);
	}

	int x;
	FOR(i, 1, n+1){	
		x = input[i];
		freq[x]++;
	}


	int cont = 0;
	ll res = 0;

	for(auto x : perm){
		if(cont == freq.size() - 1)
			break;

		res++;
		
		freq[input[x]]--;
		if(freq[input[x]] == 0)
			cont++;
	}

	cout << res << "\n";
return 0;
}

