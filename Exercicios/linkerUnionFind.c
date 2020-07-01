#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100100
#define ll long long int

typedef struct {
	vertex *prox, *head, *fim, *ant;
	int num, sum, id;
} vertex;

typedef vertex* node;

node nohs[MAX_N];

void INIT(int n){

	for(int i = 1; i <= n; i++){
		node[i] = malloc(sizeof(vertex*));
		node[i]->prox = NULL;
		node[i]->ant = NULL;
		node[i]->head = node[i];
		node[i]->num = 1;
		node[i]->sum = i;
		node[i]->id = i;
		node[i]->fim = node[i]; 
	}
return;
}


node find(int id){
	return nohs[id]->head;
}

bool isSameSet(int a, int b){
	return find(a)->id == find(b)->id;
}

void UNION(int a, int b){

	if(!isSameSet(a, b)){

		node head_a = find(a);
		node head_b = find(b);

		if(head_a->num < head_b->num){
			head_b->fim->prox = head_a;
			head_a->ant = head_b->fim;

			node aux = head_a;
			for(int i = 1; i < head_a->num && aux != NULL; i++){
				aux->head = head_b;
				aux = aux->prox;
			}
			aux->head = head_b;			
			head_b->fim = aux;
			head_b->num += head_a->num;
			head_b->sum += head_a->sum;
		}else{
			head_a->fim->prox = head_b;
			head_b->ant = head_a->fim;

			node aux = head_b;
			for(int i = 1; i < head_b->num; i++){
				aux->head = head_a;
				aux = aux->prox;
			}
			aux->head = head_a;			
			head_a->fim = aux;
			head_a->num += head_b->num;
			head_a->sum += head_b->sum;
		}
	}
return;
}

void MOVE(int x, int y){

	node head = find(y);

	if(nohs[x]->ant != NULL)
		nohs[x]->ant->prox = nohs[x]->prox;
	if(nohs[x]->prox != NULL)
		nohs[x]->prox->ant = nohs[x]->ant;

	nohs[x]->prox = NULL;
	nohs[x]->ant = head->fim;
	head->fim = nohs[x];
return;
}


int main(){

	int n, m, op, a, b;
	scanf("%d %d", &n, &m);

	INIT(n);


	for(int i = 0; i < m; i++){

		scanf("%d", &op);
		if(op == 1){
			scanf("%d %d", &a, &b);
			UNION(a, b);
		}

		if(op == 2){
			scanf("%d %d", &a, &b);
			MOVE(a, b);
		}

		if(op == 3){
			scanf("%d", &a);
			printf("%d %d\n", info[find(a)].num, info[find(a)].sum);
		}
	}
return 0;
}










