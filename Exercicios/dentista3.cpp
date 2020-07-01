#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> intervalo;

pair<int, intervalo> consultas[10100];
intervalo marcadas[10100];

int pode (intervalo x, int consultas_marcadas){
	int i;

	for(i = 0; i < consultas_marcadas; i++){
		if(x.first >= marcadas[i].first && x.first < marcadas[i].second || x.second > marcadas[i].first && x.second <= marcadas[i].second)
			return -1;
	}
return 1;
}

int main(){

	int num_consultas, ini, fim, i, res = 0, consultas_marcadas = 0;

	scanf("%d", &num_consultas);

	for(i = 0; i < num_consultas; i++){
		scanf("%d %d", &ini, &fim);
		consultas[i].second.first = ini;
		consultas[i].second.second = fim;
		consultas[i].first = fim - ini;
	}

	sort(consultas, consultas + num_consultas);

	marcadas[0].first = consultas[0].second.first;
	marcadas[0].second = consultas[0].second.second;
	res++;
	consultas_marcadas++;

	i = 1;
	while(i < num_consultas){

		if(pode(consultas[i].second, consultas_marcadas) == 1){
			marcadas[consultas_marcadas].first = consultas[i].second.first;
			marcadas[consultas_marcadas].second = consultas[i].second.second;
			res++;
			consultas_marcadas++;
		}

	i++;
	}

	printf("%d\n", res);

	return 0;
}