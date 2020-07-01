#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500

typedef struct {
	
	int id;
	char ch;
} node;

vector<node> listAdj[MAX_N];

int visitado[MAX_N];

int n, m;


void dfs(node p, char ch){

	if(visitado[p.id] == 1)return;

	visitado[p.id] = 1;
	p.ch = ch;

	for(auto x = listAdj[p.id].begin(); x < listAdj[p.id].end(); x++){
		if(visitado[*x] == 0){
			dfs(*x, ch);
		}
	}
}

int main(){

	int i, a, b;
	node aux1, aux2;

	
	scanf("%d %d", &n, &m);

	for(i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		aux1.id = a;
		aux2.id = b;
		aux1.ch = 0;
		aux2.ch = 0;

		listAdj[aux1.id].push_back(aux2);
		listAdj[aux2.id].push_back(aux1);
	}

	for(i = 1; i <= n; i++){
		if(listAdj[i].size() == n - 1)

			
	}




}







