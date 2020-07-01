#include <stdio.h>
#include <stdlib.h>



int bb(int *v, int l, int r, int x){

	int m;

	if(r - l > 1){

		m = (l + r) / 2;
		if(v[m] == x)return 1;
		if(v[m] > x)r = m;
		if(v[m] < x)l = m + 1;
		return bb(v, l, r, x);
	}

	if(r - l == 1 && v[l] == x)return 1;
return -1;
}


int main(){

	int num, res, n, i;
	int *v;

	scanf("%d", &n);

	v = malloc(n * sizeof(n));


	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);


	scanf("%d", &num);

	res = bb(v, 0, n, num);

	printf("%d\n", res);

return 0;
}