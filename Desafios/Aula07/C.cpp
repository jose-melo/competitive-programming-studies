#include <bits/stdc++.h>
using namespace std;

int n, k;
int primos[11234];
vector<int> listaPrimos;


void gera_primos(){
	
	primos[1] = 1;
	primos[2] = 0;
	for(int i = 4; i < 11234; i += 2)
		primos[i] = 1;

	for(int i = 3; i < 11234; i += 2){
		if(primos[i] == 0)
			for(int j = 2*i; j < 11234; j += i)
				primos[j] = 1;
	}

	for(int i = 1; i < 1001; i++){
		if(primos[i] == 0){
			listaPrimos.push_back(i);
		}
	}
}

int main(){

	int cont = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	gera_primos();

	for(int i = 0; listaPrimos[i] + listaPrimos[i+1] + 1 <= n && cont < k; i++){
		if(primos[listaPrimos[i] + listaPrimos[i+1] + 1] == 0){
			cont++;
		}
	}
	if(cont == k)
		cout << "YES\n";
	else
		cout << "NO\n";
return 0;
}







