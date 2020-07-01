#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ii pair<ll, ll>



vector<ll> ordem, pais;

vector<pair<ll, ii>> edges;
vector<ii> res;

bool comp(pair<ll, ii> a, pair<ll, ii> b){
	return a.first < b.first;
}

void INIT(ll n){

	ordem.assign(n+1, 0);
	pais.assign(n+1, 0);

	for(ll i = 0; i <= n; i++)
		pais[i] = i;
}

ll find(ll x){
	while(x != pais[x])
		x = pais[x];
return pais[x];
}

bool isSameSet(ll x, ll y){
	return find(x) == find(y);
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


void kruskal(ll n, ll m){

	INIT(n);

	sort(edges.begin(), edges.end(), comp);

	for(ll i = 0; i < m; i++){

		/*prllf("pais: ");
		ll aux = 0;
		for(auto k = pais.begin(); k < pais.end(); k++){
			prllf("pais[%lli] = %lli ", aux, *k);
			aux++;
		}
		prllf("\n");
		prllf("ordem: ");
		aux = 0;
		for(auto k = ordem.begin(); k < ordem.end(); k++){
			prllf("ordem[%lli] = %lli ", aux, *k);
			aux++;
		}
		prllf("\n");*/


		if(!isSameSet(edges[i].second.first, edges[i].second.second)){
			res.push_back(make_pair(edges[i].second.first, edges[i].second.second));
			UNION(edges[i].second.first, edges[i].second.second);
		}
	}

}

int main(){

	ll n, m, x, y, w, cont = 1;

	scanf("%lli", &n);

	while(n){
		scanf("%lli", &m);

		edges.clear();
		for(ll i = 0; i < m; i++){
			scanf("%lli %lli %lli", &x, &y, &w);
			edges.push_back(make_pair(w, make_pair(x, y)));
		}

		res.clear();
		kruskal(n, m);

		printf("Teste %lli\n", cont);
		cont++;
		std::vector<pair<ll, ll>>::iterator it;
		for(it = res.begin(); it < res.end(); it++){
			if(it->first < it->second)
				printf("%lli %lli\n", it->first, it->second);
			else
				printf("%lli %lli\n", it->second, it->first);
		}	

		printf("\n");
		scanf("%lli", &n);
	}

}












