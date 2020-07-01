#include <bits/stdc++.h>
using namespace std;

string pessoas[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
queue<string> fila;

int main(){

	int n;

	cin >> n;
	
	for(int i = 0; i < 5; i++)
		fila.push(pessoas[i]);
	int cont = 0;
	string aux;
	while(cont < n){
		cont++;
		aux = fila.front();
		fila.pop();
		fila.push(aux);
		fila.push(aux);
	}
 
	cout << aux << "\n";

return 0;
}

