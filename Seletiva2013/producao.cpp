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

	ll soma;
	int T;
	cin >> T;

	while (T--){
		int N;
		cin >> N;
		vector< pii > valores;
		int aux1, aux2;
		for(int i = 0; i < N; i++){
			cin >> aux1 >> aux2;
			valores.pb(mp(aux1, aux2));
		}

		sort(valores.begin(), valores.end()); 

		soma = 1;

		for (int i = 0; i < valores.size(); i++){
			if (valores[i].fi > soma) soma = valores[i].fi;
			soma += valores[i].se;
		}

		cout << soma << endl;
		valores.clear();
	}

	return 0;
}
				
