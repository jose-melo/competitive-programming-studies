#include <bits/stdc++.h>
using namespace std;

#define ll long long int


ll memo[(1<<18)+10][20];
ll satisfacao[20];
ll bonus[20][20];


int n, m, k;


ll pd(int num_peguei, int atual, int conjunto){

	int conjunto_aux;
	if(num_peguei == m)return 0;

	if(memo[conjunto][atual] != -1)
		return memo[conjunto][atual];

	for(int bit = 0; bit < n; bit++){
		if((conjunto & (1<<bit)) == 0){
			conjunto_aux = conjunto | (1<<bit);
			memo[conjunto][atual] = max(memo[conjunto][atual],
									pd(num_peguei+1, bit+1, conjunto_aux) + satisfacao[bit+1] + bonus[atual][bit+1]);
			
		}
	}

return memo[conjunto][atual];
}


int main(){

	int a, b, c;

	cin >> n >> m >> k;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			bonus[i][j] = 0;

	for(int i = 1; i <= n; i++)
		cin >> satisfacao[i];


	for(int i = 1; i <= k; i++){
		cin >> a >> b >> c;
		bonus[a][b] = c;
	}
	for(int i = 0; i <= (1<<n); i++)
		for(int j = 1; j <= n; j++)
				memo[i][j] = -1;

	int conjunto = 0;
	ll resposta = 0;
	for(int bit = 0; bit < n; bit++){
		conjunto = conjunto | (1<<(bit));
		resposta = max(resposta, pd(1, bit+1, conjunto) + satisfacao[bit+1]);
		conjunto = 0;
	}

	cout << resposta << endl;
return 0;
}






