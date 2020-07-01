#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

int v[MAX_N];


int merge_(int l, int m, int r){

	int cont = 0;

	/*printf("merge: \n");
	printf("l: ");
	for(int i = 0; i < m; i++)
		printf("%d ", v[i]);
	printf("   ");

	printf("r: ");
	for(int i = m; i < r; i++)
		printf("%d ", v[i]);
	printf("\n");*/

	if(l == r - 1)return 0;

	int p, q, k;
	int aux[MAX_N];

	p = l;
	q = m;
	k = 0;

	while(p < m && q < r){
		if(v[p] <= v[q]){
			aux[k] = v[p];
			k++;
			p++;
		}
		else{
			cont = cont + (m - p);
			aux[k] = v[q];
			k++;
			q++;
		}
	}

	while(p < m)aux[k++] = v[p++];

	while(q < r)aux[k++] = v[q++];

	int f = l;
	for(int i = 0; i < k; i++){
		v[f] = aux[i];
		f++;
	}

	/*printf("aux: ");
	for(int i = 0; i < k; i++)
		printf("%d ", aux[i]);
	printf("\n");*/

	


	/*printf("merge: \n");
	printf("v: ");
	for(int i = l; i < k; i++)
		printf("%d ", v[i]);
	printf("\n");*/

return cont;
}


int mergeSort(int l, int r){

	int cont = 0;
	
	if(l == r - 1)
		return 0;

	int m = (l + r) / 2;

	cont += mergeSort(l, m);
	cont += mergeSort(m, r);

	cont += merge_(l, m, r);
return cont;
}


int main(){

	int n, res, m, index, val;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	
	scanf("%d", &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d", &index, &val);
		v[index] = val;
	}


	/*printf("v: ");
	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");*/

	res = mergeSort(0, n);

	/*printf("v: ");
	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");*/

	printf("res = %d\n", res);

return 0;
}







