#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100100
#define ll long long int

typedef struct vertex{
	vertex *prox, *head, *fim, *ant;
	ll num, sum, id;
} Vertex;

typedef Vertex* node;

node nohs[MAX_N];

void INIT(ll n){

	for(ll i = 1; i <= n; i++){
		nohs[i] = (Vertex*) malloc(sizeof(Vertex));
		nohs[i]->prox = NULL;
		nohs[i]->ant = NULL;
		nohs[i]->head = nohs[i];
		nohs[i]->num = 1;
		nohs[i]->sum = i;
		nohs[i]->id = i;
		nohs[i]->fim = nohs[i]; 
	}
return;
}


node find(ll id){
	return nohs[id]->head;
}

bool isSameSet(ll a, ll b){
	return find(a)->id == find(b)->id;
}

void UNION(ll a, ll b){

	if(!isSameSet(a, b)){

		node head_a = find(a);
		node head_b = find(b);

		if(head_a->num < head_b->num){
			head_b->fim->prox = head_a;
			head_a->ant = head_b->fim;

			node aux = head_a;
			for(ll i = 1; i < head_a->num && aux != NULL; i++){
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
			for(ll i = 1; i < head_b->num; i++){
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

void MOVE(ll x, ll y){

	node head_novo = find(y);
	node head_velho = find(x);

	if(nohs[x]->ant != NULL)
		nohs[x]->ant->prox = nohs[x]->prox;
	if(nohs[x]->prox != NULL){
		nohs[x]->prox->ant = nohs[x]->ant;
		nohs[x]->prox->num = nohs[x]->num - 1;
	}

	nohs[x]->prox = NULL;
	nohs[x]->ant = head_novo->fim;
	head_novo->fim = nohs[x];
	nohs[x]->head = head_novo;

	head_novo->num += 1;
	head_novo->sum += x;

	head_velho->num -= 1;
	head_velho->sum -= x;
return;
}


int main(){

	ll n, m, op, a, b;
	scanf("%lli %lli", &n, &m);

	INIT(n);


	for(ll i = 0; i < m; i++){

		scanf("%lli", &op);
		if(op == 1){
			scanf("%lli %lli", &a, &b);
			UNION(a, b);
		}

		if(op == 2){
			scanf("%lli %lli", &a, &b);
			MOVE(a, b);
		}

		if(op == 3){
			scanf("%lli", &a);
			printf("%lli %lli\n", find(a)->num, find(a)->sum);
		}
	}
return 0;
}










