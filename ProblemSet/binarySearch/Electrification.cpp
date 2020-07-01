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

vector<ll> input;
int n, k, T;

int main(){

	fastio;

	cin >> T;

	while(T--){

		cin >> n >> k;

		int aux;
		FI(n){
			cin >> aux;
			input.pb(aux);
		}
			
		int idx = 0;
		ll menor = INF;
		for(int i = 0; i + k < n; i++)
			if(input[i + k] - input[i] < menor){
				menor = input[i + k] - input[i];
				idx = i;
			}
	
		ll res = input[idx] + (menor) / 2;
		
		cout << res << "\n";
		
		input.clear();

	}
return 0;
}


