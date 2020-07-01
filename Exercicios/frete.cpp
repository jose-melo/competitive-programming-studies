#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ii pair<ll, ll>

vector<ll> pais, ordem;
vector<pair<ll, ii>> edges;

void INIT(ll n){

	ordem.assign(n+1, 0);
	pais.assign(n+1, 0);
	for(ll i = 0; i <= n; i++)
		pais[i] = i;
}

ll find(ll i){

	while(i != pais[i])
		i = pais[i];
return pais[i];
}

bool isSameSet(ll i, ll j){
	return find(i) == find(j); 
}

void UNION(ll x, ll y){

	if(!isSameSet(x, y)){
		ll i = find(x);
		ll j = find(y);

		if(ordem[i] > ordem[j]){
			pais[j] = i;
		}else{
			pais[i] = j;
			if(ordem[i] == ordem[j])
				ordem[j]++;
		}
	}
}

bool comp(pair<ll, ii> a, pair<ll, ii> b){
	return a.first < b.first;
}


ll kruskal(ll n, ll m){

	ll cont = 0;

	INIT(n);

	sort(edges.begin(), edges.end(), comp);

	for(ll i = 0; i < m; i++){
		if(!isSameSet(edges[i].second.first, edges[i].second.second)){
			cont += edges[i].first;
			UNION(edges[i].second.first, edges[i].second.second);
		}
	}

return cont;
}

int main(){

	ll n, m, res, a, b, c, cont = 1;

	while(scanf("%lli %lli", &n, &m) != EOF){

		res = 0;
		edges.clear();
		pais.clear();
		ordem.clear();

		for(ll i = 0; i < m; i++){
			scanf("%lli %lli %lli", &a, &b, &c);
			edges.push_back(make_pair(c, make_pair(a, b)));
		}

		res = kruskal(n, m);

		printf("Instancia %lli\n", cont);cont++;
		printf("%lli\n", res);
		printf("\n");
	}


return 0;
}


