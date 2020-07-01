#include <bits/stdc++.h>
using namespace std;


#define MAX_M 60
#define MOD 1000000007
#define ll long long int 


ll ** alocaMatriz(ll m){

	ll** ans;
	ans = (ll **) malloc(m * sizeof(ll*));

	for(ll i = 0; i < m; i++)
		ans[i] = (ll*) malloc(m * sizeof(ll));
return ans;
}

ll** matrizMult(ll** a, ll** b, ll m){

	ll** ans;
	ans = alocaMatriz(m);

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			for(ll k = 0; k < m; k++){
				ans[i][j] = (((ans[i][j] % MOD) + ((a[i][k] % MOD) * (b[k][j] % MOD) % MOD) % MOD) % MOD); 
			}
return ans;
}


ll** matrizExpo(ll** x, ll n, ll m){

	if(n == 1)return x;


	ll** res = matrizExpo(x, n/2, m);

	if(n % 2)
		return matrizMult(matrizMult(x, res, m), res, m);
	
return matrizMult(res, res, m);
}

ll** matrizExpo2(ll** x, ll n, ll m){

	ll** res = alocaMatriz(m);

	for(int i = 0; i < m; i++)
		res[i][i] = 1;

	while(n > 0){

		if(n & 1)
			res = matrizMult(res, x, m);

		x = matrizMult(x, x, m);
		n = n >> 1;
	}
return res;	
}

int main(){

	ll n, m, t;

	scanf("%lli", &t);

	while(t--){
		scanf("%lli %lli", &m, &n);
		
		ll** matriz = alocaMatriz(m);
		ll** input = alocaMatriz(m);

		for(ll i = 0; i < m; i++)
			for(ll j = 0; j < m; j++)
				scanf("%lli", &input[i][j]);


		matriz = matrizExpo2(input, n, m);

		for(ll i = 0; i < m; i++){
			for(ll j = 0; j < m; j++)
				printf("%lli ", matriz[i][j]);
			printf("\n");
		}

	}

}







