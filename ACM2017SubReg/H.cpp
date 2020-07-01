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

vector<int> prods;

int main(){

	fastio;

	int T, n, k, maxx;
	
	cin >> T;

	while(T--){

		cin >> n >> k;
	
		int a, b, c;
		vector<int> aux;
		FI(n){
			cin >> a >> b >> c;
			aux.pb(a);
			aux.pb(b);
			aux.pb(c);

			sort(aux.begin(), aux.end());

			prods.pb(aux[0]);
			prods.pb(aux[1]);
	
			aux.clear();	
		}

		sort(prods.begin(), prods.end());
		
		ll somaTotal = 0;
	
		for(int i = 0; i < k; i++)
			somaTotal += prods[i];	
		
		cout << somaTotal << "\n";	
	
		prods.clear();	

	}



}


