#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101000
#define MAX_N_SEG 400000
#define pos 1
#define neg -1
#define ll long long int

ll seg[MAX_N_SEG];
ll input[MAX_N];

ll comb(ll a, ll b){

	if(a == 0 || b == 0)
		return 0;


	if((a > 0 && b > 0) || (a < 0 && b < 0))
		return pos;

return neg;
}


void build(ll node, ll a, ll b){

	if(a == b){
		seg[node] = comb(input[a], 1);
		return;
	}

	ll m = (a + b) / 2;

	build(2*node, a, m);
	build(2*node + 1, m + 1, b);

	seg[node] = comb(seg[2*node], seg[2*node + 1]);
return;
}


void update(ll node, ll a, ll b, ll i, ll x){

	if(a == b){
		seg[node] = comb(x, 1);
		return;
	}

	ll m = (a + b) / 2;

	if(i <= m)
		update(2*node, a, m, i, x);
	else
		update(2*node + 1, m + 1, b, i, x);

	seg[node] = comb(seg[2*node], seg[2*node + 1]);
return;
}

ll query(ll node, ll a, ll b, ll l, ll r){

	if(a == l && b == r)
		return seg[node];

	ll m = (a + b) / 2;

	if(a <= l && r <= m)
		return query(2*node, a, m, l, r);

	if(m < l && r <= b)
		return query(2*node + 1, m + 1, b, l, r);

return comb(query(2*node, a, m, l, m), query(2*node + 1, m + 1, b, m + 1, r));
}

int main(){

	ll n, q, x, add, y, res;
	char consulta;


	while(scanf("%lli %lli", &n, &q) != EOF){

		for(ll i = 1; i <= n; i++)
			scanf("%lli", &input[i]);

		build(1, 1, n);

		for(ll i = 1; i <= q; i++){
			scanf(" %c", &consulta);

			if(consulta == 'C'){
				scanf("%lli %lli", &x, &add);
				update(1, 1, n, x, add);
			}else{
				scanf("%lli %lli", &x, &y);
				res = query(1, 1, n, x, y);
				if(res == pos){
					printf("+");
				}else{
					if(res == neg)
						printf("-");
					else
						printf("0");
				}
			}
		}
		printf("\n");
	}

return 0;
}


