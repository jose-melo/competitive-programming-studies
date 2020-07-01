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

void matrizMult(ll a[2][2], ll b[2][2], ll m, ll ans[][2]){

	ans[0][1] = 0;
	ans[0][0] = 0;
	ans[1][1] = 0;
	ans[1][0] = 0;

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			for(ll k = 0; k < m; k++){
				ans[i][j] = (((ans[i][j] % MOD) + ((a[i][k] % MOD) * (b[k][j] % MOD) % MOD) % MOD) % MOD); 
			}


	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			ans[i][j] = ans[i][j] % MOD;

return;			
}

void matrizPow(ll a[2][2], ll n, ll m, ll ans[2][2]){

	//printf("n = %lli\n", n);

	ll res[2][2], aux2[2][2];

	ans[0][1] = a[0][1];
	ans[0][0] = a[0][0];
	ans[1][1] = a[1][1];
	ans[1][0] = a[1][0];

	if(n == 1)return;
	if(n == 0){
		ans[0][0] = ans[1][1] = 1;
		ans[0][1] = ans[1][0] = 0;
		return;
	}
	if(n < 0){
		ans[0][0] = ans[1][1] = 0;
		ans[0][1] = ans[1][0] = 0;
		return;
	}


	matrizPow(a, n/2, m, res);

	if(n % 2){
		matrizMult(res, res, m, aux2);
		matrizMult(aux2, a, m, ans);
	}
	else{
		matrizMult(res, res, m, ans);
	}

return;
}


int main(){

	ll n, k, l;
	ll T[2][2];
	ll res[2][2];

	while(scanf("%lli %lli %lli", &n, &k ,&l) != EOF){

		n = n / 5;

		/*printf("n = %lli\n",n );*/

		T[0][0] = k%MOD;
		T[0][1] = l%MOD;
		T[1][0] = 1;
		T[1][1] = 0;

		res[0][0] = 0;
		res[0][1] = 0;
		res[1][0] = 0;
		res[1][1] = 0;

		/*printf("n = %lli k = %lli l = %lli\n",n, k, l);*/


		/*printf("n-1 = %lli\n",n-1 );*/

		matrizPow(T, n-1, 2, res);

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
