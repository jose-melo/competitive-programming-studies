#include <bits/stdc++.h>
using namespace std;

int main(){

		int num_cortes, p, max, num_elementos, i;

		int v[2100];
		int aux[2100];
		int repetidos[3010];
		set<int> cortes;
		
		scanf("%d", &num_elementos);
		scanf("%d", &num_cortes);


		for(i = 1; i <= num_elementos; i++){
			scanf("%d", &v[i]);
			aux[i] = v[i];
		}

			
		sort(aux, aux+num_elementos+1);

		long long int resposta = 0;
		for(i = 0; i < num_cortes; i++){
			resposta += aux[num_elementos-i];

			if(cortes.find(aux[num_elementos-i]) != cortes.end())
				repetidos[aux[num_elementos-i]]++;

			cortes.insert(aux[num_elementos-i]);
		}
		cout << resposta << "\n";
		num_cortes--;
		int k = 0;
		int cortei = 0;
		for(i = 1; i <= num_elementos && num_cortes != cortei; i++){
			k++;
			
			if(num_elementos-i == num_cortes-cortei){
				//printf("B i = %d\n", i);
				printf("%d ", k);
				while(num_elementos-i > 0){
					printf("1 ");
					i++;
				}
			}	
			else if(cortes.find(v[i]) != cortes.end()){
				//printf("A k = %d i = %d\n", k, i);
				cortei++;
				printf("%d ", k);
				k = 0;
				if(repetidos[v[i]] == 0)
					cortes.erase(v[i]);
				else
					repetidos[v[i]]--;			
			}		

		}
		i--;
		if(i < num_elementos){
			k = num_elementos-i;
			printf("%d", k);
		}

		printf("\n");
return 0;
}