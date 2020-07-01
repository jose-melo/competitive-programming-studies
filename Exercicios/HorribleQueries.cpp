#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10100000
#define MAX_N_SEG 40000000
#define ll long long int

ll seg[MAX_N_SEG];
ll lazy[MAX_N_SEG];
ll input[MAX_N];
ll n;

void imp(){

	printf("seg: ");
	for(ll i = 1; i < 2*n; i++)
		printf("(%lli => %lli) ", i, seg[i]);
	printf("\n");

	printf("lazy: ");
	for(ll i = 1; i < 2*n; i++)
		printf("(%lli => %lli) ",i, lazy[i]);
	printf("\n");
return;
}

void push(ll node, ll a, ll b){

	//printf("PUSH node = %lli a = %lli b = %lli\n", node, a, b);

	//printf("comeco do PUSH:\n");imp();

	if(a > b)return;

	if(a == b){
		return;
	}

	ll m = (a + b) / 2;
	ll n_1, n_2;

	lazy[2*node] += lazy[node]; 
	lazy[2*node + 1] += lazy[node];

	n_1 = (m - a + 1);
	n_2 = (b - m);

	seg[2*node] += n_1*lazy[node];
	seg[2*node + 1] += n_2*lazy[node];
	lazy[node] = 0;

	//printf("fim do PUSH:\n");imp();

return;
}

void build(ll node, ll a, ll b){

	if(a > b)return;

	if(a == b){
		seg[node] = input[a];
		lazy[node] = 0;
		return;
	}

	ll m = (a + b) / 2;

	build(2*node, a, m);
	build(2*node + 1, m + 1, b);

	seg[node] = seg[2*node] + seg[2*node + 1];
return;
}


void update(ll node, ll a, ll b, ll l, ll r, ll x){

	printf("UPDATE update: node = %lli a = %lli b = %lli l = %lli r = %lli \n",node, a, b, l, r);

	push(node, a, b);
	if(a > r || b < l)return;



	if(a >= l && b <= r){
		ll aux = (b - a + 1);
		seg[node] += aux * x;
		lazy[node] += x;
		return;
	}

	ll m = (a + b) / 2;
	
	if(a <= l && r <= m){
		update(2*node, a, m, l, r, x);
	}else{
		if(m < l && r <= b){
			update((2*node) + 1, m + 1, b, l, r, x);
		}else{
			update(2*node, a, m, l, r, x);
			update(2*node + 1, m + 1, b, l, r, x);
		}
	}


	seg[node] = seg[2*node] + seg[2*node + 1];
return;
}

ll query(ll node, ll a, ll b, ll l, ll r){

	printf("QUERY node = %lli a = %lli b = %lli l = %lli r = %lli\n",node, a, b, l, r);
	push(node, a, b);

	if(l > b || r < a) return 0;

	if(a >= l && b <= r){
		return seg[node];
	}

	ll m = (a + b) / 2;


	if(a <= l && r <= m)
		return query(2*node, a, m, l, r);

	if(m < l && r <= b)
		return query(2*node + 1, m + 1, b, l, r);

	ll aux_res = query(2*node, a, m, l, min(m, r)) + query(2*node + 1, m + 1, b, min(m + 1, l), r);

return aux_res;
}

void clean(){


	for(ll i = 0; i <= MAX_N_SEG; i++){
		seg[i] = 0;
		lazy[i] = 0;
	}
	for(ll i = 0; i <= MAX_N; i++)
		input[i] = 0;
	
	n = 0;

return;
}

int main(){

	ll t, c, p, q, add,res;
	int consulta;

	scanf("%lli", &t);

	clean();

	while(t--){

		scanf("%lli %lli", &n, &c);
		for(ll i = 1; i <= n; i++)
			input[i] = 0;

		build(1, 1, n);

		for(ll i = 1; i <= c; i++){
			scanf(" %d", &consulta);

			if(consulta == 0){
				scanf("%lli %lli %lli", &p, &q, &add);
				//printf("Antes do update:\n"); //imp();
				update(1, 1, n, p, q, add);
				//printf("Depois do update:\n");// imp();
			}else{
				scanf("%lli %lli", &p, &q);
				//printf("Antes da query: \n");//imp();
				res = query(1, 1, n, p, q);
				//printf("Depois da query: \n");//imp();
				printf("%lli\n", res);
			}
		}

		clean();
	}

return 0;
}


