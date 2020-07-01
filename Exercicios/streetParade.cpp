#include <bits/stdc++.h>
using namespace std;


stack<int> pilha;
vector<int> carros;


int main(){

	int num_carros, end = 1, i, aux, p;

	scanf("%d", &num_carros);
	while(num_carros != 0){

		for(i = 0; i < num_carros; i++){
			scanf("%d", &aux);
			carros.push_back(aux);
		}

		p = 1;
		i = 0;
		while(i < num_carros){

			if(carros[i] != p){
				if(pilha.empty() || pilha.top() != p){
					pilha.push(carros[i]);
					i++;
				}else{
					if(pilha.top() == p){
						pilha.pop();
						p++;
					}
				}
			}else{
				p++;
				i++;
			}
		}

		if(pilha.empty()){
			printf("yes\n");
		}
		else{

			while(p <= num_carros && pilha.top() == p){
				pilha.pop();
				p++;
			}
			if(pilha.empty())
				printf("yes\n");
			else
				printf("no\n");
		}

		while(!pilha.empty())
			pilha.pop();
		carros.clear();

		scanf("%d", &num_carros);
	}

return 0;
}