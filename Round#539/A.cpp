#include <bits/stdc++.h>
using namespace std;

int num_cities, tam_tanque, resposta;

int main(){

	scanf("%d %d", &num_cities, &tam_tanque);

	num_cities--;

	resposta = 0;
	int city = 1;
	int tanque = 0;
	while(num_cities > 0){

		while(tanque < tam_tanque && num_cities > 0){
			resposta += city;
			num_cities--;
			tanque++;
		}
		city++;
		tanque--;
	}

	printf("%d\n", resposta);

return 0;
}