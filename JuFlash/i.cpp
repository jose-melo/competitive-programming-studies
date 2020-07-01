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
int primos[100100];
vector<int> listaPrimos;
ll somaTotal;
ll input[112345];

int main (){

	int cont = 0;
	for(int i = 2 ; i <= 100000; i++){
		if(primos[i] == 0){
			cont++;
			for(int j = i + i ; j < 100000 ; j+=i)
				primos[j]  = 1;
		}
	}

	for(int i = 2; i <= 100000; i++)
		if(primos[i] == 0)
			listaPrimos.pb(i);
	

	int n;
	cin >> n;
	bool testaPalindromo = true;
	for(int i = 0; i < n; i++)
		cin >> input[i];
	
	for(int i = 0; i < n/2; i++)
		if(input[i] != input[n-i-1])
			testaPalindromo = false;

	if(testaPalindromo){
		cout << "-1\n";
		return 0;	
	}	

	somaTotal = 0;
	for(int i = 0; i < n/2; i++)
		somaTotal += abs(input[i] - input[n-i-1]);
	
	ll res = 1;
	ll aux;
	for(auto x : listaPrimos){
		aux = somaTotal;	
		while(aux % x == 0){
			res *= x;
			aux /= x;
		}	
	}

	bool ok = true;
	if(res == 1){
		if(somaTotal / (n/2) != (input[n-1] - input[0])){
			ok = false;
		}else{
			res = input[n-1] - input[0];
		}
	}
	
	if(ok){
		cout << res << "\n";
	}else{
		cout << "-1\n";
	}

return 0;
}


