#include <bits/stdc++.h>
using namespace std;

#define MAX_M 60
#define MOD 1000000
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


	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			ans[i][j] = ans[i][j] % MOD;

return ans;			
}

ll** matrizPow(ll** a, ll n, ll m){

	//printf("n = %lli\n", n);

	if(n == 1)return a;
	if(n == 0){
		ll** res = alocaMatriz(2);
		res[0][0] = res[1][1] = 1;
		res[0][1] = res[1][0] = 0;
		return res;
	}
	if(n < 0){
		ll** res = alocaMatriz(2);
		res[0][0] = res[1][1] = 0;
		res[0][1] = res[1][0] = 0;
		return res;
	}


	ll** res = matrizPow(a, n/2, m);

	if(n % 2)
		return matrizMult(matrizMult(res, res, m), a, m);

return matrizMult(res, res, m);
}


int main(){

	ll n, k, l;
	ll** T = alocaMatriz(2);

	while(scanf("%lli %lli %lli", &n, &k ,&l) != EOF){

		n = n / 5;

		/*printf("n = %lli\n",n );*/

		T[0][0] = k%MOD;
		T[0][1] = l%MOD;
		T[1][0] = 1;
		T[1][1] = 0;

		/*printf("n = %lli k = %lli l = %lli\n",n, k, l);*/


		/*printf("n-1 = %lli\n",n-1 );*/

		ll** res = matrizPow(T, n-1, 2);

		/*printf("res:\n");
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				printf("%lli ",res[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		ll resposta = (((((res[0][0] % MOD) *(k % MOD) % MOD)% MOD) + (res[0][1] % MOD) % MOD)) % MOD;

		/*printf("resposta = %lli\n", resposta);*/

		deque<ll> v;

		int cont = 1;
		while(cont < 7){
			v.push_front(resposta % 10);
			resposta /= 10;
			cont++;
		}

		for(auto x = v.begin(); x < v.end(); x++)
			printf("%lli", *x);
		printf("\n");

		
		v.clear();

	}

return 0;
}
