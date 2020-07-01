#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000
#define INF 1000000000


int f[MAX_N][MAX_N], w[MAX_N], p[MAX_N];



int pd(int i, int b){

	if(i < 0)return 0;
	if(b < 0)return -INF;

	if(f[i][b] == -1)
		f[i][b] = max(pd(i - 1, b), pd(i - 1, b - w[i]) + p[i]);

return f[i][b];
}


int  main(){

	int b, n;

	scanf("%d %d", &b, &n);


	for(int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &p[i]);

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= b; j++)
			f[i][j] = -1;
	pd(n, b);

	printf("%d\n", f[n][b]);

return 0;
}


