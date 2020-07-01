#include <bits/stdc++.h>
using namespace std;

int v[1000];

int main(){

	int n, m, i, p, q, cont = 0, diff;

	scanf("%d %d", &n, &m);


	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);


	for(i = 0; i + 1 < n; i++){
		diff = m - v[i];
		v[i] += diff;
		v[i+1] += diff;
		cont += abs(diff);
	}

	printf("%d\n", cont);

return 0;

}