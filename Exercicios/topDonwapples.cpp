#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000
#define INF 1000000000

int pesos[MAX_N];
int custos[MAX_N];
int f[MAX_N][MAX_N];


int pd(int n, int kg){


	if(n <= 0 || kg == 0)return 0;

	if(kg < 0)return INF;

	if(f[n][kg] != -1)
		return f[n][kg];


	int min = INF;
	int kgi;

	for(int i = 1; i <= kg; i++){
		if(custos[i] == -1){
			continue;}
		int aux = pd(n - 1, kg - i) + custos[i];

 		if(aux < min){
 			min = aux;
 			kgi = i;
 		}
	}
	kg -= kgi;
	
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