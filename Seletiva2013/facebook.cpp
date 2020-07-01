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

ll soma;
int n, aux;

int main(){
	
	fastio;

	int T;	
	bool ok;

	cin >> T;
	
	while(T--){
	
		soma = 0;
		cin >> n;

		ok = true;

		FI(n){
			cin >> aux;
			
			if(aux >= n){
				ok = false;
				break;	
			}

			soma += aux; 
		}
	
		if(!ok){
			cout << "N\n";
			continue;
		}
	
		if(soma % 2)
			cout << "N\n";
		else
			cout << "Y\n";
	}
return 0;
}


