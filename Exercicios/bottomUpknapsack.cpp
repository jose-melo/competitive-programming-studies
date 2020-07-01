#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000


int f[MAX_N][MAX_N], w[MAX_N], p[MAX_N];


void knapSack(int n, int b){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= b; j++){

			if(i == 0 || j == 0){
				f[i][j] = 0;

			}else{

				if(j - w[i - 1] >= 0){
					f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i - 1]] + p[i - 1]);
				}else{
					f[i][j] = f[i - 1][j];
				}
			}
		}
	}
}

int  main(){

	int b, n;

	scanf("%d %d", &b, &n);


	for(int i = 0; i < n; i++)
		scanf("%d %d", &w[i], &p[i]);

	knapSack(n, b);

	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= b; j++){
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}*/

	printf("%d\n",f[n][b]);

return 0;
}









