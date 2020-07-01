#include <bits/stdc++.h>
using namespace std;


int lanterns[1100];




int main(){


	int n, i, tam;
	double max, res, a;

	scanf("%d %d", &n, &tam);


	for(i = 0; i < n; i++)
		scanf("%d", &lanterns[i]);

	sort(lanterns, lanterns + n);

	max = lanterns[0];

	for(i = 1; i < n; i++){
		a = (double) (lanterns[i] - lanterns[i-1]) / 2;
		if( a > max)
			max = (double) (lanterns[i] - lanterns[i-1]) / 2;
	}
	if(tam - lanterns[n-1] > max){
			max = tam - lanterns[n-1];
	}

	res = (double) max;


	printf("%lf\n", res);

return 0;
}