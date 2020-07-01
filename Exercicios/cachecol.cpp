#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007
#define ll long long int
#define MAX_N 60

void matrizMult(ll a[2][2], ll b[2][2], ll ans[2][2]){

	ans[0][1] = 0;
	ans[0][0] = 0;
	ans[1][1] = 0;
	ans[1][0] = 0;

	for(ll i = 0; i < 2; i++)
		for(ll j = 0; j < 2; j++)
			for(ll k = 0; k < 2; k++){
				ans[i][j] += (((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD); 
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

	ll n, iguais, diferentes, resposta, a, b;
	ll T[2][2], res[2][2];

	scanf("%lli", &n);

	T[0][0] = 3;
	T[0][1] = 2;
	T[1][0] = 2;
	T[1][1] = 2;

	//n = n % MOD;

	//printf("n = %lli\n", n);


	matrizPow(T, n-1, res);

	a = ((((res[0][0] % MOD)*(6 % MOD) % MOD) % MOD) + (((res[0][1] % MOD)*(6 % MOD) % MOD) % MOD) % MOD);
	b = ((((res[1][0] % MOD)*(6 % MOD) % MOD) % MOD) + (((res[1][1] % MOD)*(6 % MOD) % MOD) % MOD) % MOD);

	//printf("a = %lli b = %lli\n",a, b);

	resposta = ((a % MOD) + (b % MOD) % MOD);
	
	/*while(resposta < 0)
		resposta += MOD;
	resposta = resposta % MOD;*/

	printf("%lli\n", resposta%MOD);

return 0;	
}



