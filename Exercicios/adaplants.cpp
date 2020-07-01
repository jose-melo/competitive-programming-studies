#include <bits/stdc++.h>
using namespace std;

int v[100100];
int aux[100100];


int main(){


	int n, k, i, j, t, aux2;

	scanf("%d", &t);

	for(j = 0; j < t;  j++){

		scanf("%d %d", &n, &k);

		for(i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			aux[i] = v[i];
		}


		int p, q, max = -1;

		p = 1;

		while(p < n){
			//printf("k =%d p = %d\n",k , p);
			q = p + 1;

			while(abs(q - p) <= k && max(p, q) <= n){
				if(abs(v[q] - v[p]) > max)
					max = abs(v[q] - v[p]);
				
				q++;
						}

			
			p++;
		}

		printf("%d\n", max);
	}

return 0;
}