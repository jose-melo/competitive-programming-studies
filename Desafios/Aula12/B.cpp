#include <bits/stdc++.h>
using namespace std;

int n;
int grafo[1123];
int visitados[1123];

void limpa(){	
	for(int i = 0; i <= n; i++)
		visitados[i] = 0;
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> grafo[i];

	int noh;
	for(int i = 1; i <= n; i++){
		noh = i;
		while(!visitados[noh]){
			visitados[noh] = 1;		
			noh = grafo[noh];
		}
		limpa();
		cout << noh << " ";
	}
	cout << "\n";

return 0;
}




