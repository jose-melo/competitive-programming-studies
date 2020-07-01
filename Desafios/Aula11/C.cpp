#include <bits/stdc++.h>
using namespace std;

int digitos[10];
int x;

bool temDigitos(int div){
	
	int resto;
	while(div > 0){
		resto = div % 10;
		if(digitos[resto])return true;
		div /= 10;
	}
return false;
}

int main(){

	cin >> x;
	int cont = 0;

	int aux = x;
	while(aux > 0){
		digitos[aux%10] = 1;
		aux /= 10;
	}
	

	for(int div = 1; div*div <= x; div++){
		if(x % div == 0){
			if(temDigitos(div))
				cont++;
			if(x/div != div && temDigitos(x/div))
				cont++;
		}
	}

	cout << cont << endl;
return 0;
}



