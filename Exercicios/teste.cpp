#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007
#define ll long long int
#define MAX 60


void matrizMult(ll a[MAX][MAX], ll b[MAX][MAX], ll ans[MAX][MAX], ll m){

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			ans[i][j] = 0;

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			for(ll k = 0; k < m; k++){
				ans[i][j] += (((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD) % MOD; 
			}

return;			
}

void matrizPow(ll a[MAX][MAX], ll n, ll ans[MAX][MAX], ll m){

	//printf("n = %lli\n", n);

	ll res[MAX][MAX], aux2[MAX][MAX];

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			ans[i][j] = a[i][j];


	if(n == 1)return;
	if(n == 0){
		for(ll i = 0; i < m; i++)
			for(ll j = 0; j < m; j++){
				if(i == j)
					ans[i][j] = 1;
				else
					ans[i][j] = 0;
			}
						
		return;
	}
	if(n < 0){
		for(ll i = 0; i < m; i++)
			for(ll j = 0; j < m; j++)
				ans[i][j] = 0;
		return;
	}


	matrizPow(a, n/2, res, m);

	if(n % 2){
		matrizMult(res, res, aux2, m);
		matrizMult(aux2, a, ans, m);
	}
	else{
		matrizMult(res, res, ans, m);
	}

return;
}

ll pos(char ch){

	if(ch >= 'a' && ch <= 'z')
		return ch - 'a';

return ch - 'A' + 26;
}


int main(){


	ll n, m, k, linha1, linha2, linha3, resposta;
	char s[3];
	ll T[MAX][MAX], res[MAX][MAX];

	scanf("%lli %lli %lli", &n, &m, &k);

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			T[i][j] = 1;


	for(ll i = 0; i < k; i++){
		scanf("%s", s);
		T[pos(s[0])][pos(s[1])] = 0;
	}

	/*for(ll i = 0; i < m; i++){
		for(ll j = 0; j < m; j++){
			printf("%lli ", T[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	matrizPow(T, n-1, res, m);

	/*for(ll i = 0; i < m; i++){
		for(ll j = 0; j < m; j++){
			printf("%lli ", res[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	for(ll i = 0; i < m; i++)
		for(ll j = 0; j < m; j++)
			resposta = ((resposta % MOD) + (res[i][j] % MOD)) % MOD;

	printf("%lli\n", resposta % MOD);
return 0;
}