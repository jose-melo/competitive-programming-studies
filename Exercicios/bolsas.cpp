#include <bits/stdc++.h>
using namespace std;

#define MAXIN 10100

typedef struct {
	
	int t;
	int d;
} bolsa;

bolsa v[MAXIN];

bool func(bolsa a, bolsa b){

	if(a.d < b.d)return true;
return false;
}


int main(){

	int i, n, atraso = 0, tempo = 0, res = -1;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d %d", &v[i].t, &v[i].d);
	
	sort(v, v + n, func);

	for(i = 0; i < n; i++){
		atraso = max(0, tempo + v[i].t - v[i].d);
		tempo += v[i].t;
		if(atraso > res)res = atraso;
	}

	printf("%d\n", res);

return 0;
}