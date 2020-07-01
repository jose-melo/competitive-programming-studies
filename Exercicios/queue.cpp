#include <bits/stdc++.h>
using namespace std;


int notas[5];
int nota_aluno[5];

int total(int *v){

	int soma = 0, i;

	for(i = 0; i < 5; i++){

		switch (i){
			case 0: 
				soma += v[i]*1;
				notas[0] += v[i];
			break;

			case 1: 
				soma += v[i]*5;
				notas[1] += v[i];
			break;

			case 2: 
				soma += v[i]*10;
				notas[2] += v[i];
			break;

			case 3: 
				soma += v[i]*20;
				notas[3] += v[i];
			break;

			case 4: 
				soma += v[i]*50;
				notas[4] += v[i];
			break;
		}
	}
return soma;
}

int paga_troco(int troco){

	if(troco == 0)return 1;
	if(troco < 5){
		if(notas[0] != 0){
			notas[0]--;
			troco--;
			return paga_troco(troco);
		}
	return -1;
	}else{

		if(troco < 10){
			if(notas[1] != 0){
				notas[1] -= 5;
				troco -= 5;
				return paga_troco(troco);
			}
			return -1;
		}else{

			if(troco < 20){
				if(notas[2] != 0){
					notas[2] -= 10;
					troco -= 10;
					return paga_troco(troco);
				}

				if(notas[1] != 0){
				notas[1] -= 5;
				troco -= 5;
				return paga_troco(troco);
				}
				return -1;
			}else{

				if(troco < 50){
					if(notas[3] != 0){
						notas[3] -= 20;
						troco -= 20;
						return paga_troco(troco);
					}
					if(notas[2] != 0){
					notas[2] -= 10;
					troco -= 10;
					return paga_troco(troco);
					}

					if(notas[1] != 0){
					notas[1] -= 5;
					troco -= 5;
					return paga_troco(troco);
					}
				return -1;
				}else{

					if(notas[4] != 0){
						notas[4] -= 50;
						troco -= 50;
						return paga_troco(troco);
					}			
					if(notas[3] != 0){
						notas[3] -= 20;
						troco -= 20;
						return paga_troco(troco);
					}
					if(notas[2] != 0){
					notas[2] -= 10;
					troco -= 10;
					return paga_troco(troco);
					}

					if(notas[1] != 0){
					notas[1] -= 5;
					troco -= 5;
					return paga_troco(troco);
					}
				return -1;
				}	
			}
		}
	}
return -1;
}

int main(){

	int num_alunos, i, soma_alum, j, total_alum, troco, res = 0;

	scanf("%d", &num_alunos);

	for(i = 0; i < num_alunos; i++){

		scanf("%d", &total_alum);

		for(j = 0; j < 5; j++)
			scanf("%d", &nota_aluno[j]);

		soma_alum = total(nota_aluno);

		if(i == 0){
			if(soma_alum != total_alum){
				res = 2;
			}
		}else{
			troco = soma_alum - total_alum;
			if(paga_troco(troco) == -1)
				if(res != 2)res = 2;
		}
	}

	if(res == 0)
		printf("yes\n");
	else
		printf("no\n");
return 0;
}