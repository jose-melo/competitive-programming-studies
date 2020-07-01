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

int primosTotal[112345];
vector<int> primos;

void gera_primos(){

	for(int i = 3; i <= 100000; i += 2)
		if(primosTotal[i] == 0)
			for(int j = 2*i; j <= 100000; j+=i)
				primosTotal[j] = 1;

	primos.push_back(2);
	for(int i = 3; i <= 100000; i++)
		if(i % 2 == 1 && primosTotal[i] == 0)
			primos.push_back(i);

}

ll algo(ll n){
	if(n == 0)
		return 0;

	if(n % 2 == 0)
		return n / 2;

	for(auto x : primos)
		if(n % x == 0)			
			return 1 + algo(n-x);
return 1;
}



int main(){

	fastio;

	gera_primos();
	
	ll n, cont;	

	cin >> n;

	cont = algo(n);

	cout << cont << "\n";

return 0;
}

