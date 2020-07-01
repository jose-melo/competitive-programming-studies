#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ii pair<int, int>
#define MAX_N 100000

struct Vertex{

	Vertex *head, *prox;
	int sum, num, id;

	Vertex(Vertex* head, Vertex*prox, int num, int sum, int id): head(head),prox(prox),num(num),sum(sum), id(id){}
}

Vertex* nodes[MAX_N];

void INIT(int n){

	for(int i = 1; i <= n; i++){
		nodes[i] = new Vertex(novo, nullptr, 1, i, i);
	}
return;
}

Vertex* find(int i){
return nodes[i]->head;
}

bool isSameSet(int i, int j){
	return find(i)->id == find(j)->id;
}

void UNION (int x, int y){

	if(!isSameSet(x, y)){

		Vertex* i = find(x);
		Vertex* j = find(y);

		if(nodes[x]->num > nodes[y])
	}
}

void change(int x, int y){

	if(!isSameSet(x, y)){
		int j = find(y);
		int i = find(x);
		pais[x] = j;
		info[i].num -= 1;
		info[i].sum -= x;
		info[j].num += 1;
		info[j].sum += x;
		if(ordem[])
	}
}








