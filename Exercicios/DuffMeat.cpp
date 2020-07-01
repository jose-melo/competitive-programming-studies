#include <bits/stdc++.h>
using namespace std;


pair <int, int> carnes[100100];


int main(){

	int num_dias, i, p, q, preco_total;

	scanf("%d", &num_dias);

	for(i = 0; i < num_dias; i++){
		scanf("%d %d", &carnes[i].first, &carnes[i].second);
	}
	p = 0;
	q = 1;
	preco_total = 0;

	while(q <= num_dias){
		
		preco_total += carnes[p].second * carnes[p].first;

		while(carnes[p].second < carnes[q].second){
			preco_total += carnes[p].second * carnes[q].first;
			q++;
		}
		p = q;
		q++;

	}

	printf("%d\n", preco_total);
return 0;
}