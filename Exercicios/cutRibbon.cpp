#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int fita[10000];


int a, b, c;

int PD(int i){

	if(i == 0)return 0;
	if(i < 0)return -INF;

	if(fita[i] != -1)
		return fita[i];

	fita[i] = max(max(PD(i - a) + 1, PD(i - b) + 1), PD(i - c) + 1);
return fita[i];
}


int main(){

	int n;

	scanf("%d %d %d %d", &n, &a, &b, &c);

	for(int i = 0; i <= n; i++)
		fita[i] = -1;


	printf("%d\n", PD(n));

return 0;
}

