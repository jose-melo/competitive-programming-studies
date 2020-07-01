#include <bits/stdc++.h>
using namespace std;

#define MAX_N 110
#define INF 100000000000000000

int seg[MAX_N];
int input[MAX_N];

void build(int node, int a, int b){

	if(a == b){
		seg[node] = input[a];
		return;
	}

	int m = (a + b) / 2;

	build(2*node, a, m);
	build(2*node + 1, m + 1, b);

	seg[node] = seg[2*node] + seg[2*node + 1];

return;
}

void update(int node, int a, int b, int pos, int x){

	if(a == b){
		seg[node] = x;
		return;
	}

	int m = (a + b) / 2;

	if(pos <= m)
		update(2*node, a, m, pos, x);
	else
		update(2*node + 1, m + 1, b, pos, x);

	seg[node] = seg[2*node] + seg[2*node + 1];

return;
}

int query(int node, int a, int b, int l, int r){


	if(a == l && b == r)
		return seg[node];

	int m = (a + b) / 2;

	if(a <= l && r <= m)
		return query(2*node, a, m, l, r);

	if(m < l && r <= b)
		return query(2*node + 1, m + 1, b, l, r);

return query(2*node, a, m, l, m) + query(2*node + 1, m + 1, b, m + 1, r);
}


int main(){

	int n, cont = 1;;
	char consulta;
	int x, y, add;


	scanf("%d", &n);

	while(n){

		printf("CASE %d:\n", cont);

		for(int i = 1; i <= n; i++)
			scanf("%d", &input[i]);
	
		build(1, 1, n);

		scanf(" %c", &consulta);

		while(consulta != 'E'){
			if(consulta == 'S'){
				scanf("%d %d", &x, &add);
				update(1, 1, n, x, add);
			}else{
				scanf("%d %d", &x, &y);
				printf("%d\n",query(1, 1, n, x, y));
			}

			scanf(" %c", &consulta);
			
		}

		scanf("%c %c", &consulta, &consulta);
		scanf("%d", &n);

		cont++;
	}

}






