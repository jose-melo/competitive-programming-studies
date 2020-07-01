#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101000
#define MAX_N_SEG 400000
#define INF 100000000000000000
#define ll long long int

ll seg[MAX_N_SEG];
ll input[MAX_N];


void build(ll node, ll a, ll b){

	if(a == b){
		seg[node] = input[a];
		return;
	}

	ll m = (a + b) / 2;
	build(2*node, a, m);
	build(2*node + 1, m + 1, b);

	seg[node] = min(seg[2*node], seg[2*node + 1]);
return;
}

void update(ll node, ll a, ll b, ll pos, ll x){

	if(a == b){
		seg[node] = x;
		return;
	}

	ll m = (a + b) / 2;

	if(pos <= m)
		update(2*node, a, m, pos, x);
	else
		update(2*node + 1, m + 1, b, pos, x);

	seg[node] = min(seg[2*node], seg[2*node + 1]);

return;
}

ll query(ll node, ll a, ll b, ll x, ll y){

	if(a == x && b == y)
		return seg[node];

	ll m = (a + b) / 2;

	if(a <= x && y <= m)
		return query(2*node, a, m, x, y);
	if(m < x && y <= b)
		return query(2*node + 1, m + 1, b, x, y);

return min(query(2*node, a, m, x, m), query(2*node + 1, m + 1, b, m + 1, y));
}

int main(){

	ll T, N, Q, x, y, cont = 0;

	scanf("%lli", &T);
	cont++;

	while(T--){

		printf("Scenario #%lli:\n", cont);

		scanf("%lli %lli", &N, &Q);

		for(ll i = 1; i <= N; i++)
			scanf("%lli", &input[i]);

		build(1, 1, N);

		for(ll i = 1; i <= Q; i++){
			scanf("%lli %lli", &x, &y);
			printf("%lli\n",query(1, 1, N, x, y));
		}
	
		cont++;
	}
return 0;
}


