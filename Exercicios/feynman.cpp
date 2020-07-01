#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10010000
#define INF 1000000000
#define mod 1000000007

#define A 0
#define B 1
#define C 2
#define D 3

long long int f[MAX_N];

int n;

long long int memoization(int i){

	if(i == 1){
		f[i] = 1;
		return f[i];
	}

	if(f[i] != -1)
		return f[i];

	if(f[i - 1] != -1)
		f[i] = f[i - 1] + (i * i);
	else
		f[i] = memoization(i - 1) + (i * i);

return f[i];
}

int main(){

	scanf("%d", &n);

	while(n != 0){

		for(int i = 0; i <= n; i++)
			f[i] = -1;

		printf("%lli\n", memoization(n));


		scanf("%d", &n);
	}
return 0;
}

