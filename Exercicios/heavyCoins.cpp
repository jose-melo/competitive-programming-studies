#include <bits/stdc++.h>
using namespace std;

int moedas[11];


bool comp(int a, int b){
	return a > b;
}

int main(){

	int T, num_moedas, soma, sum, cont, resposta;

	cin >> T;

	while(T--){

		cin >> num_moedas >> soma;

		for(int i = 0; i < num_moedas; i++)
			cin >> moedas[i];


		resposta = -1;

		sort(moedas, moedas+num_moedas, comp);

		for(int i = 0; i < 1<<num_moedas; i++){

			cont = 0;
			sum = 0;
			for(int j = 0; j < num_moedas; j++){
				if(i & (1<<j)){
					sum += moedas[j];
					//printf("%d ", moedas[j]);
					cont++;
					if(sum >= soma){
						resposta = max(resposta, cont);
						break;
					}
				}

			}
			//printf("cont = %d\n", cont);

		}
		printf("%d\n", resposta);

	}

}