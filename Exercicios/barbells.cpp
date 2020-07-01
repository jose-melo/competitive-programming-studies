#include <bits/stdc++.h>
using namespace std;


#define ll long long int

set<ll> resposta;
map<ll, int> somas;
ll barras[15];
ll pesos[15];

int main(){

	int num_barras, num_pesos, soma, peso_esq, barra, bit, soma2, bit2, peso_dir, k, cont = 0;
	int aux[15];

	cin >> num_barras;
	cin >> num_pesos;

	for(int i = 0; i < num_barras; i++)
		cin >> barras[i];

	for(int i = 0; i < num_pesos; i++)
		cin >> pesos[i];

	sort(pesos, pesos+num_pesos);
	sort(barras, barras+num_barras);

	somas[0] = 1;	for(barra = 0; barra < num_barras; barra++){
		for(peso_esq = 0; peso_esq < (1<<num_pesos); peso_esq++){
			soma = 0;
			for(bit = 0; bit < num_pesos; bit++){
				if(peso_esq & (1<<bit)){
					soma += pesos[bit];
				}
			}
			
		}
	}


	for(auto x = resposta.begin(); x != resposta.end(); x++)
		cout << *x << endl;
	
return 0;
}
