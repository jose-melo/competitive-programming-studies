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

	fastio;

	ll somaPar = 0;
	ll somaImpares = 0;

	vector<int> impares;

	int n;
		
	cin >> n;
	
	int aux;
	FI(n){
		cin >> aux;
		if(aux%2){
			impares.pb(aux);
			somaImpares += aux;
		}else
			somaPar += aux;

	}

	sort(impares.begin(), impares.end());

	if(impares.size()%2)	
		somaImpares -= impares[0];

	cout << somaPar + somaImpares << "\n";
return 0;
}



