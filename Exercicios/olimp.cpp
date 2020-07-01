#include <bits/stdc++.h>
using namespace std;

int m[100][3];

void troca(int ** m, int a, int b, int *v){

	int aux[3];
	int i, aux2;

	for(i = 0; i < 3; i++){
		aux = m[a][i];
		m[a][i] = m[b][i];
		m[b][i] = m[a][i];
	}

	aux2 = v[a];
	v[a] = v[b];
	v[b] = aux2;
return;
}


int separa (int *v, int **m){

	int p, q, pivo;
	
	pivo = v[l];
	q = r - 1;
	p = l;
	while(p < q){
		while(v[q] > pivo && p < q)q--;
		if(p < q)troca(m, p, q, v);
		while(v[p] <= pivo && p < q)p++;
		if(p < q)troca(m, p, q, v);
	}

return p;
}

void qs(int *v, int l, int r, int **m){

	int pivo;
	if(r - l > 1){
		pivo = separa(v, m);
		qs(v, l, pivo, m);
		qs(v, pivo + 1, r, m);
	}
}




void ordena matriz(int **m, int column, int num_paises){

	int v[100];
	int i;

	for(i = 1; i <= num_paises; i++)
		v[i] = m[i][column];
	qs(v, 0, num_paises, m);
return;
}




int main(){

}