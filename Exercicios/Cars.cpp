#include <bits/stdc++.h>
using namespace std;



pair<int, int> v[1000];


int main(){

	int num_cars, num_laps, i, j, aux, soma;

	scanf("%d %d", &num_cars, &num_laps);

	for(i = 1; i <= num_cars; i++){
		soma = 0;
		for(j = 0; j < num_laps; j++){
			scanf("%d", &aux);
			soma += aux;
		}
		v[i] = make_pair(soma, i);
	}

	sort(v, v + num_cars +1);

	for(i = 1; i <= 3; i++)
		printf("%d\n", v[i].second);

	printf("\n");

return 0;
}


