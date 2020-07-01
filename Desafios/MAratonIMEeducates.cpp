#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main(){

	ll n, pessoas = 0, aux, aux2;

	scanf("%lli", &n);

	aux2 = n;
	while(aux2--){
		scanf("%lli", &aux);
		pessoas += aux;
	}

	if(pessoas % 5 != 0)
		printf("%lli\n", (pessoas / 5) + 1);
	else
		printf("%lli\n", pessoas / 5);

return 0;
}

