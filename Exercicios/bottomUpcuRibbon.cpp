#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int fita[10000];


int a, b, c;

void pd(int n){

	int i, c1, c2, c3;

	fita[0] = -INF;
	fita[1] = 0;
	for(i = 2; i <= n; i++){

		if(i - a + 1 >= 0)
			c1 = i - a + 1;
		else c1 = 0;
		
		if(i - b + 1 >= 0)
			c2 = i - b + 1;
		else c2 = 0;
		
		if(i - c + 1 >= 0){
			c3 = i - c + 1;
		}
		else
			c3 = 0;

		fita[i] = max(max(fita[c1] + 1, fita[c2] + 1), fita[c3] + 1);
	}
}

int main(){

	int n;

	scanf("%d %d %d %d", &n, &a, &b, &c);

	a++; b++; c++; n++;


	pd(n);

	printf("%d\n", fita[n]);

return 0;
}


