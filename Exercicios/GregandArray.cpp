#include <bits/stdc++.h>
using namespace std;

#define MAX 100100

int res[MAX];

typedef struct {
	
	int d;
	int ini;
	int fim;

} op;

op operacoes[MAX];

vector <op> v;
vector<op> c;

void trata_intervalos(op x, int i){

	op novo;

	printf("TESTE\n");
	int m = c[i].d;
	for(auto k = v.begin(); k < v.end(); k++){

		printf("TESTE\n");
		/*CASO 1*/
		if(x.ini >= k->ini && x.fim <= k->fim){
			
			/**CASO 1.1**/
			if(x.ini == k->ini && x.fim == k->fim){
				k->d += x.d * m;
				break;
			}
			/**CASO 1.2**/
			if(x.ini == k->ini){
				x.d += k->d * m;
				v.push_back(x);
				k->ini == x.fim;
				break;
			}

			/**CASO 1.3**/
			if(x.fim == k->fim){
				x.d += k->d * m;
				v.push_back(x);
				k->fim = x.ini;
				break;
			}

			/**CASO 1.4**/
			x.d = k->d * m;
			novo = *k;
			novo.ini = x.fim;
			v.push_back(novo);
			k->fim = x.ini;
			break;
		}

		/*CASO 2*/
		if(x.ini <= k->fim && x.fim >= k->fim){

			novo = x;
			novo.d += k->d * m;
			novo.fim = k->fim;
			x.ini = novo.fim;
			k->fim = x.ini;
			v.push_back(novo);
		}

		/*CASO 3*/
		if(x.fim >= k->ini && x.ini <= k->ini){

			novo = x;
			novo.d += k->d * m;
			novo.ini = k->ini;
			x.fim = novo.ini;
			k->ini = x.fim;
			v.push_back(novo);
		}

	}



}

void trata_intervalos2(op x){


	printf("\n4 x.d = %d x.ini = %d x.fim  = %d\n", x.d, x.ini, x.fim);

	int i;
	op novo;

	for(auto k = c.begin(); k < c.end(); k++){

		printf("4 k->d = %d k->ini = %d k->fim  = %d\n", k->d, k->ini, k->fim);
		
		/*CASO 1*/
		if(x.ini >= k->ini && x.fim <= k->fim){
			
			/**CASO 1.1**/
			printf("CASO 1.1\n");
			if(x.ini == k->ini && x.fim == k->fim){
				k->d += x.d;
				break;
			}
			/**CASO 1.2**/
			if(x.ini == k->ini){
				printf("CASO 1.2\n");	
				x.d += k->d;
				c.push_back(x);
				printf("1 x->d = %d\n", x.d);
				k->ini == x.fim;
				break;
			}

			/**CASO 1.3**/
			if(x.fim == k->fim){
				printf("CASO 1.3\n");
				x.d += k->d;
				c.push_back(x);
				printf("2 x->d = %d\n", x.d);
				k->fim = x.ini;
				break;
			}

			/**CASO 1.4**/
			printf("CASO 1.4\n");
			x.d = k->d;
			novo = *k;
			novo.ini = x.fim;
			c.push_back(novo);
			printf("3 novo->d = %d\n", novo.d);
			k->fim = x.ini;
			break;
		}

		/*CASO 2*/
		if(x.ini <= k->fim && x.fim >= k->fim){
			printf("CASO 2\n");
			novo = x;
			novo.d += k->d;
			novo.fim = k->fim;
			k->fim = x.ini;
			x.ini = novo.fim + 1;
			c.push_back(novo);
			printf("4 x.d = %d x.ini = %d x.fim  = %d\n", x.d, x.ini, x.fim);
			printf("4 novo.d = %d novo.ini = %d novo.fim  = %d\n", novo.d, novo.ini, novo.fim);
			printf("4 k->d = %d k->ini = %d k->fim  = %d\n", k->d, k->ini, k->fim);
		}

		/*CASO 3*/
		if(x.fim >= k->ini && x.ini <= k->ini){

			novo = x;
			novo.d += k->d;
			novo.ini = k->ini;
			x.fim = novo.ini;
			k->ini = x.fim;
			c.push_back(novo);
			printf("5 novo->d = %d\n", novo.d);
		}

	}
}




int main(){

	int i, num_op, num_queries, n, ini, fim, d, x, y, j;
	op aux_op;

	scanf("%d %d %d", &n, &num_op, &num_queries);

	for(i = 1; i <= n; i++)
		scanf("%d", &res[i]);

	for(i = 1; i <= num_op; i++){
		scanf("%d %d %d", &ini, &fim, &d);
		operacoes[i].d = d;
		operacoes[i].ini = ini;
		operacoes[i].fim = fim;
	}

	/*aux_op.ini = 0;
	aux_op.fim = 0;
	aux_op.d = 76;
	c.push_back(aux_op);*/

	scanf("%d %d", &x, &y);

	aux_op.ini = x;
	aux_op.fim = y;
	aux_op.d = 1;

	c.push_back(aux_op);

	for(i = 2; i <= num_queries; i++){

		scanf("%d %d", &x, &y);

		aux_op.ini = x;
		aux_op.fim = y;
		aux_op.d = 1;
		trata_intervalos2(aux_op);
	}

	printf("\n");
	for(auto p = c.begin(); p < c.end(); p++)
		printf("%d ", p->d);
	printf("\n");

	for(i = 1; i <= num_op; i++){
		trata_intervalos(operacoes[i], i);
	}

	for(auto g = v.begin(); g < v.end(); g++){
		aux_op = *g;
		for(y = g->ini; y < g->fim; y++)
			res[y] += g->d;
	}


	printf("\n");
	for(i = 1; i <= n; i++)
		printf("%d ", res[i]);
	printf("\n");

return 0;
}