#include <bits/stdc++.h>
using namespace std;

int n, cont;
int gabarito[11234];
int cores[11234];
vector<int> listAdj[11234];
int visitados[11234];


void dfs(int noh){

	if(visitados[noh])return;
	
	visitados[noh] = 1;

	if(cores[noh] != gabarito[noh]){
		cores[noh] = gabarito[noh];
		cont++;
	}

	for(auto x : listAdj[noh])
		if(!visitados[x])
			cores[x] = gabarito[noh];	
		
	
	for(auto x : listAdj[noh])
		dfs(x);
return;
}


int main(){

	cont = 0;

	cin >> n;
	
	int aux;
	for(int i = 2; i <= n; i++){
		cin >> aux;
		listAdj[i].push_back(aux);
		listAdj[aux].push_back(i);
	}

	for(int i = 1; i <= n; i++){
		cin >> aux;
		gabarito[i] = aux;
		cores[i] = 0;
		visitados[i] = 0;
	}

	dfs(1);
	
	cout << cont << "\n";

return 0;
}

