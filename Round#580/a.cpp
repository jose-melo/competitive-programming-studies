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

int a[440], b[440];
vector<int> ina, inb;


int main(){

	int n, m;

	cin >> n;
	int aux;	
	FI(n){
		cin >> aux;
		a[aux] = 1;
		ina.pb(aux);
	}
	cin >> m;
	FI(m){
		cin >> aux;
		b[aux] = 1;
		inb.pb(aux);
	}
	
	int soma;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			soma = ina[i] + inb[j];
			
			if(!a[soma] && !b[soma]){
				cout << ina[i] << " " << inb[j] << endl;
				return 0;		
			}
		}
return 0;
}





