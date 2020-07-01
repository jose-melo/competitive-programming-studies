#include <bits/stdc++.h>
using namespace std;


#define MAX_M 60
#define MOD 1000000007
#define ll long long int 

int matriz[MAX_M][MAX_M];
int input[MAX_M][MAX_M];


int** matrizMult(int** a, int** b, int m){

	int** ans;
	ans = (int *) malloc(m * sizeof(int*));

	for(int i = 0; i < m; i++)
		ans[i] = (int) malloc(m * sizeof(int));

	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < m; k++)
				ans[i][j] += a[i][k] * b[k][j]; 
return ans;
}


int** matrizExpo(int** x, int n, int m){

	if(n == 1)return x;


	int** res = matrizExpo(x, n/2);

	if(n % 2)
		return matrizMult(matrizMult(x, res, m), res, m);
	
return matrizMult(res, res, m);
}

int main(){

	int n, m, t;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &m, &n)
		
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &input[i][j]);


		matriz = matrizExpo(inptu, n, m);

		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++)
				printf("%d ", matriz[i][j]);
			printf("\n");
		}
		
	}

}







