#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int 
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

int primosTotais[5123456];
vector<int> primos;
ll pd[5123456];
ll divisor[5123456];
ll fatores[5123456];

void gera_primos(){

	divisor[2] = 2;

	for(int i = 4; i <= 5000000; i += 2){
		primosTotais[i] = 1;
		divisor[i] = 2;
	}

	for(int i = 3; i <= 5000000; i += 2)
		if(primosTotais[i] == 0)
			for(int j = 2*i; j <= 5000000; j += i){
				primosTotais[j] = 1;
				divisor[j] = i;
			}
	primos.pb(2);
	FOR(i, 3, 5000001){
		if(i % 2 == 1 && primosTotais[i] == 0)
			primos.pb(i);
	}
return;
}

int main(){
	
	fastio;

	int T;

	cin >> T;

	gera_primos();

	int cont, num;
	
	fatores[1] = 0;

	FOR(i, 2, 5000001){	
		
		if(primosTotais[i] == 0){
			fatores[i] = 1LL;
			continue;
		}
		fatores[i] = fatores[i/divisor[i]] + 1LL;
	
	}
	pd[1] = 0LL;

	FOR(i, 2, 5000001)
		pd[i] = fatores[i] + pd[i-1];
		
	int a, b;
	FI(T){
		cin >> a >> b;
		cout << pd[a] - pd[b] << "\n";
	}

return 0;
}






