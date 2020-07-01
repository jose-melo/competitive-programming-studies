#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000
#define INF 1000000000

int max_time[MAX_N];
int min_time[MAX_N];
int f[MAX_N][MAX_N];
int resp[MAX_N];


int pd(int d, int sumTotal){

	//printf("d = %d, sumTotal = %d\n",d, sumTotal);

	if(sumTotal < 0)return 0;
	if(d == 0)return 0;
	
	if(d == 1){
		if(max_time[d] >= sumTotal && sumTotal >= min_time[d]){
			resp[1] = sumTotal;
			return 1;}
		return 0;
	}

	if(f[d][sumTotal] != -1)
		return f[d][sumTotal];

	f[d][sumTotal] = 0;
	for(int i = min_time[d]; i <= max_time[d]; i++){
		//printf("i = %d\n",i );

		if(pd(d - 1,sumTotal - i) == 1){
			f[d][sumTotal] = 1;
			//printf("f[%d][%d] = %d\n",d, sumTotal, f[d][sumTotal]);
			resp[d] = i;
			break;
		}
	}

return f[d][sumTotal];
}




int main(){

	int d, sumTime, a, b;

	scanf("%d %d", &d, &sumTime);

	for(int i = 1; i <= d; i++)
		scanf("%d %d", &min_time[i], &max_time[i]);


	for(int i = 0; i <= d; i++)
			for(int j = 0; j <= sumTime; j++)
				f[i][j] = -1;



	if(pd(d, sumTime) == 1){
		printf("YES\n");

		for(int i = 1; i <= d; i++)
			printf("%d ", resp[i]);
		printf("\n");
	}else{
		printf("NO\n");
	}

return 0;
}













