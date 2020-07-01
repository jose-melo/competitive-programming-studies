#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101000
#define ll long long int


int seg[4*MAX_N][9];
int lazy[4*MAX_N];
int freq[9];
int n;

void build(int node, int a, int b){

	//printf("build node = %d a = %d b = %d\n", node, a, b);

	if(a == b){
		seg[node][1] = 1;
		//printf("seg[node][1] %d\n", seg[node][1]);
		return;
	}

	int m = (a + b) / 2;

	build(2*node + 1, a, m);
	build(2*node + 2, m + 1, b);

	seg[node][1] = seg[2*node + 1][1] + seg[2*node + 2][1];
	//printf("seg[node][1] %d\n", seg[node][1]);

return;
}

void push(int node, int a, int b){

	//printf("push node = %d a = %d b = %d\n", node, a, b);

	if(lazy[node] != 0){

		int aux, lazi;
		lazi = lazy[node];
		lazy[node] = 0;
		int auxxi[9];

		for(int i = 0; i <= 8; i++){
			aux = (i + lazi) % 9;
			auxxi[aux] = seg[node][i];
		}

		for(int i = 0; i <= 8; i++)
			seg[node][i] = auxxi[i];
		


		if(a != b){
			lazy[2*node + 1] += lazi;
			lazy[2*node + 2] += lazi;
		}

	}
}

void query(int node, int a, int b, int l, int r){

	//printf("query node = %d a = %d b = %d l = %d r = %d\n",node, a, b, l, r);

	push(node, a, b);

	if(a > r || b < l)return;

	if(a >= l && b <= r){
		for(int i = 0; i <= 8; i++)
			freq[i] += seg[node][i];
		return;
	}

	int m = (a + b) / 2;

	query(2*node + 1, a, m, l, r);
	query(2*node + 2, m + 1, b, l, r);

return;
}


void update(int node, int a, int b, int l, int r, int add){

	//printf("update node = %d a = %d b = %d l = %d r = %d\n", node, a, b, l, r);

	push(node, a,b);
	if(a > r || b < l)return;

	if(a >= l && b <= r){
		lazy[node] += add;
		push(node, a, b);
		return;
	}

	int m = (a + b) / 2;

	update(2*node + 1, a, m, l, r, add);
	update(2*node + 2, m + 1, b, l, r, add);

	for(int i = 0; i <= 8; i++)
		seg[node][i] = seg[2*node + 1][i] + seg[2 * node + 2][i];
return;
}

void inicializa(){
	for(int i = 0; i <= 8; i++)
		freq[i] = 0;
}

void imp(){

	for(int i = 0; i < n; i++){
		inicializa();
		query(0, 0, n-1, i, i);
		for(int j = 0; j <= 8; j++){
			if(freq[j] != 0){
				printf("%d\n", j);
				break;
			}
		}
	}

}

int main(){

	int q, x, y;
	scanf("%d %d", &n, &q);

	build(0, 0, n-1);

	//imp();

	for(int i = 0; i < q; i++){

		scanf("%d %d", &x, &y);

		inicializa();
		query(0, 0, n-1, x, y);

		int freq_max = -1, nota = 0;
		for(int i = 0; i <= 8; i++){
			if(freq[i] >= freq_max){
				nota = i;
				freq_max = freq[i];
			}
		}

		//printf("QUERY = %d\n", nota);

		update(0, 0, n-1, x, y, nota);

		//imp();

	}


	imp();

return 0;
}







