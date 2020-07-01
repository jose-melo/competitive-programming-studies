#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007


void matrizMult(int a[4][4], int b[4][4], int ans[4][4]){

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ans[i][j] = 0;


	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				ans[i][j] += a[i][k] + b[k][j];
}


void matrizPow(int a[4][4], int n, int ans[4][4]){

	int res[4][4], aux[4][4];

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ans[i][j] = a[i][j];
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(i == j)
				res[i][j] = 1;
			else
				res[i][j] = 0;

	if(n == 1)return;
	if(n == 0){
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				ans[i][j] = res[i][j];
		return;
	}

	while(n > 0){
		if(n & 1)
			matrizMult(res, a, res);
		matrizMult(a, a, aux);
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++){
				a[i][j] = aux[i][j];
				aux[i][j] = 0;
			}

		n = n >> 1;
	}

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ans[i][j] = res[i][j];
return;
}

int main(){

	int t, n, resposta;
	int T[4][4], res[4][4];

	scanf("%d", &t);

	T[0][0] = 2;
	T[0][1] = -1;
	T[0][2] = 0;
	T[0][3] = 0;

	T[1][0] = 0;
	T[1][1] = 0;
	T[1][2] = 2;
	T[1][3] = -1;

	T[2][0] = 1;
	T[2][1] = 0;
	T[2][2] = 0;
	T[2][3] = 0;

	T[3][0] = 0;
	T[3][1] = 0;
	T[3][2] = 1;
	T[3][3] = 0;

	while(t--){

		scanf("%d", &n);

		matrizPow(T, n-1, res);

		resposta = 2*res[0][0];

		printf("%d\n", resposta);

	}
return 0;
}