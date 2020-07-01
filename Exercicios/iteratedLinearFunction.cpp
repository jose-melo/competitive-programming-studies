#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007
#define ll long long int

void matrizMult(ll a[2][2], ll b[2][2], ll ans[2][2]){

	ans[0][1] = 0;
	ans[0][0] = 0;
	ans[1][1] = 0;
	ans[1][0] = 0;

	for(ll i = 0; i < 2; i++)
		for(ll j = 0; j < 2; j++)
			for(ll k = 0; k < 2; k++){
				ans[i][j] += (((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD) % MOD; 
			}

return;			
}

void matrizPow(ll a[2][2], ll n, ll ans[2][2]){

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


	matrizPow(a, n/2, res);

	if(n % 2){
		matrizMult(res, res, aux2);
		matrizMult(aux2, a, ans);
	}
	else{
		matrizMult(res, res, ans);
	}

return;
}


int main(){

	
	ll A, B, n, x;
	ll T[2][2], res[2][2], aux1, aux2, resposta;

	scanf("%lli %lli %lli %lli", &A, &B, &n, &x);

	T[0][0] = A % MOD;
	T[0][1] = 1;
	T[1][0] = 0;
	T[1][1] = 1;

	matrizPow(T, n-1, res);

	/*printf("res:\n");
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				printf("%lli ",res[i][j]);
			}
			printf("\n");
		}
	printf("\n");*/

	aux1 = ((((((A % MOD)*(x % MOD)) % MOD) % MOD) + (B % MOD)) % MOD) % MOD;
	aux2 = ((res[0][1] % MOD) * (B % MOD)) % MOD;

	resposta = ((((((res[0][0] % MOD) * (aux1 % MOD)) % MOD) % MOD) + (aux2 % MOD)) % MOD) % MOD;

	printf("%lli\n", resposta % MOD);


return 0;	
}



