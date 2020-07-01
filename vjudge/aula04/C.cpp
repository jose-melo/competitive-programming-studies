/*https://codeforces.com/problemset/problem/1060/B*/
#include <bits/stdc++.h>
using namespace std;

long long int n, aux, d, aux2;

int main(){

	cin >> n;

	long long int a = n / 2;
	aux = a;
	int cont = 0;
	while(aux > 9){
		aux = aux / 10;
		cont++;
	}
	
	long long int b = aux-1;
	long long int c = 9;	
	long long int res = b + 9*cont;
	long long int res2 = 9 + 9*cont;

	for(int i = 0; i < cont; i++){
		b = (10*b) + 9;
		c = (10*c) + 9;
	}

	a = n - b;
	d = n - c;

	aux = a;
	while(aux > 9){
		res += aux % 10;
		aux /= 10;
	}
	res += aux;

	aux = d;
	while(aux > 9){
		res2 += aux % 10;
		aux /= 10;
	}
	res2 += aux;

	if(res > res2)
		cout << res << endl;
	else
		cout << res2 << endl;

return 0; 	
}





