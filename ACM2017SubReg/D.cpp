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

int kids, n;
vector <int> adj[30];
int mask[30];


int check(int num){
	
	int verifica = (1<<kids) - 1;

	int cont = 0 ;

	for(int bit = 0 ; bit < kids ; bit++){
		if(num & (1<<bit) ){
			verifica = (verifica) & (mask[bit+1]);
			cont++;
		}
	}

	for(int bit = 0 ; bit < kids ; bit++){
		if(verifica & (1 << bit) )
			cont++;		
	}

	return cont;
}


int main (){
	int T;
	cin >> T;

	while(T--){
		
		cin >> kids >> n;
	
		FI(n){
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
		}

		for(int i = 1 ; i <= kids ; i++)
			for(auto it : adj[i])
				mask[i] += 1 << (it - 1);
		

		int maior = 0;

		for(int i = 0 ; i < (1<<kids) ; i++)
			maior = max(maior, check(i));

		cout << maior << endl;

		FI(kids+1){
			adj[i].clear();
			mask[i] = 0;
		}

	}

return 0;
}
