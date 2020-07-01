#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000
#define INF 1000000000

int p[MAX_N];
int w[MAX_N];
int f[MAX_N][MAX_N];
int sol[MAX_N][MAX_N];

int pd(int n, int k){

	int i, aux, min, index;

	//printf("n = %d k = %d\n", n, k);

	if(k == 0 && n >= 0)return 0;

	if(n == 0 && k != 0){
		//printf("RETURNED INF\n");
		return INF;
	}

	if(n < 0){
		//printf("RETURNED INF\n");
		return INF;
	}
	if(k < 0){
		//printf("RETURNED INF\n");
		return INF;
	}

	if(f[n][k] != -1){
		//printf("RETURNED %d\n", f[n][k]);
		return f[n][k];
	}

	min = INF;

	for(i = 1; i <= k; i++){

		if(p[i] != -1){
			aux = pd(n - 1, k - i) + p[i];
			
			//printf("aux = %d\n", aux);

			if(aux < min){
				min = aux;
			}
		}
	}

	f[n][k] = min;
	//printf("f[%d][%d] = %d\n",n, k, f[n][k]);

return f[n][k];
}


int main(){


	int num, n, kg;	


	scanf("%d", &num);


	for(int cont = 1; cont <= num; cont++){

		scanf("%d %d", &n ,&kg);

		for(int i = 1; i <= kg; i++){
			scanf("%d", &p[i]);
		}

		p[0] = 0;

		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= kg; j++)
				f[i][j] = -1;


		int res = pd(n, kg);

		if(res == INF)
			printf("-1\n");
		else
			printf("%d\n", res);
	}

return 0;
}



