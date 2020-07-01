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


vector<int> memo[212345], input;

int main(){

	int n, k;

	cin >> n >> k;
	
	int aux;
	FI(n){
		cin >> aux;
		input.pb(aux);	
	}
	
	for(int i = 0; i < input.size(); i++){
		aux = input[i];
		int cont = 0;
		while(aux >= 1){
			memo[aux].pb(cont);
			cont++;
			aux /= 2;
		}
	}	

	ll resp = INF;
	for(int i = 0; i <= 200001; i++){
		if(memo[i].size() < k)continue;
		sort(memo[i].begin(), memo[i].end());
		ll soma = 0;
		for(int j = 0; j < k; j++)
			soma += memo[i][j];
		resp = min(soma, resp);
		
	}


	cout << resp << "\n";
return 0;
}




