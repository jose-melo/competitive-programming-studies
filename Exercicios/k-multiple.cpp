#include <bits/stdc++.h>
using namespace std;


int v[100100];
int aux[100100];


/*int bb(int *v, int l, int r, int x){

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
}*/

int main(){

	int n, k, i, cont = 0, j;

	scanf("%d %d", &n, &k);

	for(i = 0; i < n; i++)	
		scanf("%d", &v[i]);

	sort(v, v + n);

	aux[0] = k*v[0];
	cont++;
	for(i = 1; i < n; i++){
		if(!binary_search(aux, aux + cont, v[i])){
			aux[cont] = k*v[i];
			cont++;
		}
	}

printf("%d\n", cont);
return 0;
}