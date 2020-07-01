#include <bits/stdc++.h>
using namespace std;

int primosTotal[112345];
int primos[112345];
int pd[112345];
int input[112345];
int contaPrimos[112345];
vector<int> divisoresPrimos[112345];


void geraPrimos(){

	
	for(int i = 2; i <= 100000; i++)
		if(primosTotal[i] == 0)
			for(int j = 2*i; j <= 100000; j += i)
				primosTotal[j] = 1;

	int idx = 0;
	for(int i = 2; i <= 100000; i++)
		if(primosTotal[i] == 0){
			primos[idx] = i;
			idx++;
		}
}


int main(){

	int n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	geraPrimos();

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> input[i];

	int aux, idx_primos;
	for(int i = 0; i < n; i++){
		
		idx_primos = 0;
		aux = input[i];
		while(aux > 1){
	
			if(aux % primos[idx_primos] == 0){
				divisoresPrimos[input[i]].push_back(primos[idx_primos]);	
				while(aux % primos[idx_primos] == 0)
					aux /= primos[idx_primos];
			}
			idx_primos++;	
	
		}
	}

	for(int idx = 0; idx < n; idx++){

		for(auto x : divisoresPrimos[input[idx]]){
			
			contaPrimos[x]++;

			if(contaPrimos[x] > pd[idx])
				pd[idx] = contaPrimos[x];
		}

		for(auto x : divisoresPrimos[input[idx]]){

			if(pd[idx] > contaPrimos[x])
				contaPrimos[x] = pd[idx];
		}
	}	

	int max = -1;

	for(int i = 0; i < n; i++)
		if(pd[i] > max)
			max = pd[i];

	
	if(max)
		cout << max << "\n";
	else
		cout << "1\n";
	
return 0;
}








