#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){

	fastio;
	int ok = 1;
	ll n;
	ll L, soma = 0, menor, pot2;
	ll v[40], in[40];

	cin >> n >> L;
	
	FI(n)
		cin >> in[i];
	
	v[0] = in[0];
	
	FI(n-1){
		if(in[i+1] > 2*in[i])
			v[i+1] = 2*in[i];
		else
			v[i+1] = in[i+1];
	}

	
	ll tam = log2(L);
	ll faltam = L;	
	ll total = 0;	

	for(int i = 0; i < n; i++)
		if(n&(1<<i))
			total += v[i];


	for(int i = tam; i >= 0; i--){
		
		if(L & (1<<i)){
			menor = INF;
			pot2 = 1;
			for(int j = i; j >= 0; j--){
				if(j < n && menor > v[j]*pot2){
					menor = v[j]*pot2;
//					cout << "v[j] = " << v[j] << " j = " << j << " i = " << i << "pot 2 = " << pot2 <<  endl;
					
					}
				pot2 *= 2;
			}
			
			soma += menor;
		}
	}
//	debug(soma);

	ll soma2 = INF, L2, sub = 0;
	for(int i = n-1; i >= 0; i--){	
		if(!(L & (1<<i))){
			ll aux = 0;
			L2 = L;
			sub = 0;
			L2 = L2 | (1 << i);
			for(int j = i-1; j >= 0; j--)
				L2 = L2 & ~(1<<j);
			
			//debug(L2);	
			for(int j = 0; j < n; j++)
				if(!(L2 & (1<<j)) && (L&(1<<j)))
					sub += v[j];

			if(!(L & (1 << i)))aux = v[i];

			aux += soma - sub;
			//cout << "aux = " << aux << " i = " << i << " sub = " << sub<< endl;
			soma2 = min(aux, soma2);
		}
	}
	soma = min(soma, soma2);

	cout << soma << "\n";
return 0;
}
