#include <bits/stdc++.h>
using namespace std;

#define MAX_M 60
#define MOD 1000000007
#define ll long long int

ll** alocaMatriz(ll m){

	ll** ans;

	ans = (ll**) malloc(m * sizeof(ll*));

	for(ll i = 0; i < m; i++)
		ans[i] = (ll*) malloc(m * sizeof(ll));
return ans;
}

ll** matrizMult(ll** a, ll** b, ll m){

	ll** ans = alocaMatriz(m);

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			for(ll k = 0; k < m; k++){
				ans[i][j] = (((ans[i][j] % MOD) + ((a[i][k] % MOD) * (b[k][j] % MOD) % MOD) % MOD) % MOD); 
			}

return ans;			
}

ll** matrizPow(ll** a, ll n, ll m){

	if(n == 1)return a;

	ll** res = matrizPow(a, n/2, m);

	if(n % 2)
		return matrizMult(matrizMult(res, res, m), a, m);

return matrizMult(res, res, m);
}

ll fib(ll n){

	if(n == 1 || n == 2)return 1;

	ll** T = alocaMatriz(2);
	ll** res = alocaMatriz(2);


	T[0][0] = 1;
	T[0][1] = 1;
	T[1][0] = 1;
	T[1][1] = 0;

	res = matrizPow(T, n-1, 2);

	/*for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < 2; j++)
			printf("%lli ", res[i][j]);
		printf("\n");
	}*/

return res[0][0];
}


int main(){

	ll n, m, t;

	scanf("%lli", &t);

	while(t--){
		scanf("%lli %lli", &n, &m);
		ll i, j;

		i = ((fib(n+1) % MOD) - (1 % MOD) % MOD);
		j = ((fib(m+2) % MOD) - (1 % MOD) % MOD);

		ll resposta = ((j % MOD) - (i % MOD) % MOD);

		while(resposta < 0)
			resposta += MOD;


		printf("%lli\n", resposta);
	}
return 0;
}

