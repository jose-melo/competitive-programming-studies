#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000
#define INF 1000000000

int pesos[MAX_N];
int custos[MAX_N];
int f[MAX_N][MAX_N];
int sol[MAX_N];



int pd(int n, int kg){

	printf("###### n = %d kg = %d\n", n, kg);

	if(n < 0){
		printf("###### n < 0 RETURNED 0\n");
		return INF;}

	if(kg < 0){
		printf("###### kg < 0 RETURNED INF\n");
		return INF;}

	if(f[n][kg] != -1){
		printf("###### f[%d][%d] RETURNED\n", n, kg);
		return f[n][kg];
	}

	for(int k = 0; k <= kg; k++)
		sol[k] = INF;


	int aux = 0;
	for(int i = 1; i <= kg; i++){
		if(custos[i] != -1){
			sol[aux] = pd(n - 1, kg - i) + custos[i];
			aux++;
		}
	}

	int min = INF;
	for(int i = 1; i <= aux; i++)
		if(sol[i] < min)
			min = sol[i];

	f[n][kg] = min;

	printf("f[%d][%d] = %d\n",n, kg, f[n][kg]);

return f[n][kg];
}

int main(){


	int num, n, kg;	


	scanf("%d", &num);


	for(int cont = 1; cont <= num; cont++){

		scanf("%d %d", &n ,&kg);

		for(int i = 1; i <= kg; i++){
			scanf("%d", &custos[i]);
		}

		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= kg; j++)
				f[i][j] = -1;


		int res = pd(n, kg);

		if(res == 0)
			printf("-1\n");
		else
			printf("%d\n", res);
	}

return 0;
}