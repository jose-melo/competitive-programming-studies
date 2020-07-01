#include <bits/stdc++.h>
using namespace std;


pair<int, int> consultas[10100];
pair<int, int> consult[10100];

int main(){

	int num_consultas, ini = -1, fim = -1, i, res = 0, ini_atual, fim_atual;

	scanf("%d", &num_consultas);

	for(i = 0; i < num_consultas; i++){
		scanf("%d %d", &ini, &fim);
		consultas[i].first = ini;
		consultas[i].second = fim;
		consult[i].first = fim - ini;		
		consult[i].second = i;
	}

	sort(consult, consult + num_consultas);

	for




	printf("%d\n", res);

return 0;
}