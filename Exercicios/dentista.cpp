#include <bits/stdc++.h>
using namespace std;




int main(){

	int num_consultas, ini = -1, fim = -1, i, res = 0, ini_atual, fim_atual;

	scanf("%d", &num_consultas);

	scanf("%d %d", &ini_atual, &fim_atual);

	res++;

	for(i = 1; i < num_consultas; i++){
		scanf("%d %d", &ini, &fim);

		if(ini == ini_atual)
			if(fim < fim_atual)
				fim_atual = fim;

		if(ini >= fim_atual){
			ini_atual = ini;
			fim_atual = fim;
			res++;
		}
	}
	printf("%d\n", res);

return 0;
}