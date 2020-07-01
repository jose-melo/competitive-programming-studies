#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 50100
#define INF 1000000000000000000

ll f[MAX_N];
ll moedas[101];


void pd(ll n, ll m){

	for(ll i = 1; i <= m; i++)
		f[moedas[i]] = 1; 

	for(ll i = 0; i <= n; i++){
		ll menor = INF;
		for(ll j = 1; j <= m; j++){
			if(i - moedas[j] >= 0 && f[i - moedas[j]] != INF){
				f[i] = min(menor, f[i - moedas[j]] + 1);
				if(f[i] < menor)
					menor = f[i];
			}
		}

		if(menor != INF)
			f[i] = menor;
	}
}


int main(){

	ll n, m;

	scanf("%lli", &n);

	while(n != 0){

		scanf("%lli", &m);

		for(ll i = 1; i <= m; i++)
			scanf("%lli", &moedas[i]);

		f[0] = 0;
		for(ll i = 1; i <= n; i++)
			f[i] = INF;

		pd(n, m);

		/*printf("f: ");
		for(ll i = 0; i <= n; i++)
			printf("%lli ", f[i]);
		printf("\n");*/

		if(f[n] != INF)
			printf("%lli\n", f[n]);
		else
			printf("Impossivel\n");

		for(ll i = 1; i <= n; i++)
			f[i] = INF;

		scanf("%lli", &n);
	}
return 0;
}


