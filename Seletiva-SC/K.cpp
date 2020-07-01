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


	int n;
	ll soma = 0;

	cin >> n;
	ll aux;
	FI(n){
		cin >> aux;
		soma += aux; 
	}

	ll media = soma / n;
	for(ll i = media, j = media; i > 2; i--, j++){
		if (verifica(i)){
			resp = i;
			break;
		}
		if (verifica(j))
			resp = j;
			break;






}

