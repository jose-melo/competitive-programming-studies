#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ii pair<int, int>
#define MAX_N 100000

typedef struct {
	int sum;
	int num;
} node;

vector<int> pais, ordem;
node info[MAX_N];

void INIT(int n){

	pais.assign(n+1, 0);
	ordem.assign(n+1, 0);

	for(int i = 0; i <= n; i++){
		pais[i] = i;
		info[i].sum = i;
		info[i].num = 1;
	}
return;
}

int find(int i){

	if(i != pais[i])
		pais[i] = find(pais[i]);
return pais[i];
}

bool isSameSet(int i, int j){
	int aux  = 0;
	return find(i) == find(j);
}

void UNION (int i, int j){

	if(!isSameSet(i, j)){

		int x = find(i);
		int y = find(j);

		if(ordem[x] > ordem[y]){
			pais[y] = x;
			info[x].num += info[y].num;
			info[x].sum += info[y].sum;
		}else{
			pais[x] = y;
			info[y].num += info[x].num;
			info[y].sum += info[x].sum;
			if(ordem[x] == ordem[y])
				ordem[y]++;
		}
	}
}

void MOVE(int x, int y){

	if(!isSameSet(x, y)){
		int j = find(y);
		int i = find(x);
		pais[x] = j;
		info[i].num -= 1;
		info[i].sum -= x;
		info[j].num += 1;
		info[j].sum += x;

		if(info[i].num == 1)ordem[i] = 0;

	}
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