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

vector<int> mapeiaIdx[1123456];
set<ll> val;
set<ll> base;
vector<int> res;
int n;

int main(){

	fastio;

	cin >> n;
	
	int aux;
	ll somaTotal = 0;

	FOR(i, 1, n+1){
		cin >> aux;
		mapeiaIdx[aux].pb(i);
		val.insert(aux);
		base.insert(aux);
		somaTotal += aux;
	}

	for(auto x : base){
		if(mapeiaIdx[x].size() == 1)
			val.erase(x);
		
		if((((somaTotal - x) % 2) == 0) && val.find((somaTotal - x) / 2) != val.end()) {
			for(auto y : mapeiaIdx[x]){
				res.pb(y);
				}
		}
		
		val.insert(x);
	}	

	int tam = res.size();	
	cout << tam << "\n";
	
	if(!tam)return 0;

	for(auto x : res)
		cout << x << " ";
	cout << "\n";
	
	val.clear();
	res.clear();

return 0;
}



