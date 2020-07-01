#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ii pair<ll, ll>
#define MAX_N 1000000

vector<ll> pais, ordem;
set<ii> edges;
ii edges_control[MAX_N];
ll cont;
ll ans[MAX_N];
bool add[MAX_N];
ll take[MAX_N];

void INIT(ll n){

	pais.assign(n+9, 0);
	ordem.assign(n+9, 0);

	for(ll i = 0; i <= n; i++)
		pais[i] = i;
}

ll find(ll i){
	while(i != pais[i]){
		ll aux = pais[i];
		pais[i] = pais[aux];
		i = aux;
	}
return pais[i];
}

bool isSameSet(ll i, ll j){
	return find(i) == find(j);
}


ll UNION(ll i, ll j){

	ll cont = 0;

	if(!isSameSet(i, j)){
		cont = 1;
		ll x = find(i);
		ll y = find(j);

		if(ordem[y] > ordem[x]){
			pais[x] = y;
		}else{
			pais[y] = x;
			if(ordem[x] == ordem[y])
				ordem[y]++;
		}
	}
return cont;
}

/*
ll liga(ll n, ll m){

	ll cont = 0;

	INIT(n);

	set<ii>::iterator x;

	for(x = edges.begin(); x != edges.end(); x++){
		if(!isSameSet(x->first, x->second)){
			UNION(x->first, x->second, &cont);
			//printf("cont = %lli\n", cont);
		}
	}

return cont;	
}*/

int main(){

	ll n, m, a, b, q, e, cont;

	scanf("%lli %lli", &n, &m);

	for(ll i = 0; i <= m; i++)
		add[i] = true;
	add[0] = false;

	INIT(n);

	cont = n;

	for(ll i = 1; i <= m; i++){
		scanf("%lli %lli", &a, &b);
		edges.insert(make_pair(a, b));
		edges_control[i] = make_pair(a, b);
	}

	scanf("%lli", &q);

	for(ll i = 0; i < q; i++){
		scanf("%lli", &e);
		add[e] = false;
		take[i] = e;
	}

	for(ll i = 1; i <= m; i++){
		if(!add[i])continue;
		cont -= UNION(edges_control[i].first, edges_control[i].second);
	}

	ans[0] = cont;

	for(ll i = q-1; i >= 0; i--){
		cont -= UNION(edges_control[take[i]].first, edges_control[take[i]].second);
		if(i != 0)ans[i] = cont;
	}

	for(ll i = 1; i < q; i++)
		printf("%lli ", ans[i]);
	printf("%lli", ans[0]);
	printf("\n");

return 0;
}