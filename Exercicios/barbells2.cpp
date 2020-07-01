#include <bits/stdc++.h>
using namespace std;


#define ll long long int

set<ll> resposta, auxx;
ll barras[15];
ll pesos[15];


int main(){

	int num_barras, num_pesos, soma, peso_esq, barra, bit, soma2, bit2, peso_dir, k;
	int aux[15];

	cin >> num_barras >> num_pesos;

	for(int i = 0; i < num_barras; i++)
		cin >> barras[i];

	for(int i = 0; i < num_pesos; i++)
		cin >> pesos[i];

	k = 0;
	for(peso_esq = 0; peso_esq < (1<<num_pesos); peso_esq++){
		soma = 0;
		k = 0;
		for(bit = 0; bit < num_pesos; bit++){
			if(peso_esq & (1<<bit)){
				soma += pesos[bit];
				//printf("%d ", bit);
			}else{
				aux[k] = pesos[bit];
				k++;
			}
		}

		if(resposta.find(2*soma) == resposta.end()){
			for(peso_dir = 0; peso_dir < (1<<k); peso_dir++){
				soma2 = 0;
				for(bit2 = 0; bit2 < k; bit2++){
					if(peso_dir & (1<<bit2))
						soma2 += aux[bit2];
				} 
				if(soma2 == soma){
					resposta.insert(2*soma2);
					break;
				}
			}
		}
	}

	for(auto x = resposta.begin(); x != resposta.end(); x++){
		for(int barra = 0; barra < num_barras; barra++){
			auxx.insert(barras[barra] + *x);
		}
	}	
	

	for(auto x = auxx.begin(); x != auxx.end(); x++)
		cout << *x << endl;



return 0;
}
