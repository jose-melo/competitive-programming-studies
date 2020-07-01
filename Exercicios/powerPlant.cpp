#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ii pair<ll, ll>

vector<ll> pais, ordem;
vector<pair<ll, ii>> edges;
ll pp[300];

void INIT(ll n){

	pais.assign(n+1, 0);
	ordem.assign(n+1, 0);

	for(ll i = 0; i <= n; i++)
		pais[i] = i;
}

ll find(ll i){
	while(i != pais[i]){
		i = pais[i];
	}
return pais[i];
}

bool isSameSet(ll x, ll y){

	//printf("x = %lli y = %lli find(x) = %lli find(y) = %lli, pp[find(x) = %lli pp[find(y)]] = %lli\n",x, y, find(x), find(y), pp[find(x)], pp[find(y)]);

	if(find(x) != find(y)){
		
		if((pp[find(x)] == -1 && pp[find(y)] == -1)){
			//printf("returned true\n");
			return true;
		}

		//printf("returned false\n");
		return false;
	}
//printf("returned true\n");
return true;
}

void UNION(ll i, ll j){

	//printf("UNION i = %lli j = %lli X = %lli y = %lli\n", i, j, find(i), find(j));

	if(!isSameSet(i, j)){

		ll x = find(i);
		ll y = find(j);

		if(ordem[x] > ordem[y]){
			pais[y] = x;

			if(pp[y] == -1)
				pp[x] = -1;

		}else{
			pais[x] = y;
			
			if(pp[x] == -1)
				pp[y] = -1;

			if(ordem[x] == ordem[y])
				ordem[y]++;
		}

	}

	/*printf("pais: ");
	ll aux = 0;
	for(auto k = pais.begin(); k < pais.end(); k++){
		printf("pais[%lli] = %lli ", aux, *k);
		aux++;
	}
	printf("\n");
	printf("ordem: ");
	aux = 0;
	for(auto k = ordem.begin(); k < ordem.end(); k++){
		printf("ordem[%lli] = %lli ", aux, *k);
		aux++;
	}
	printf("\n");
	printf("pp: ");
	for(ll i = 0; i <= 9; i++)
		printf("%lli ", pp[i]);
	printf("\n");*/

}


bool comp(pair<ll, ii> a, pair<ll, ii> b){
	return a.first < b.first;
}

ll kruskal(ll n, ll m){

	ll cont = 0;

	INIT(n);

		/*printf("pais: ");
	ll aux = 0;
	for(auto k = pais.begin(); k < pais.end(); k++){
		printf("pais[%lli] = %lli ", aux, *k);
		aux++;
	}
	printf("\n");
	printf("ordem: ");
	aux = 0;
	for(auto k = ordem.begin(); k < ordem.end(); k++){
		printf("ordem[%lli] = %lli ", aux, *k);
		aux++;
	}
	printf("\n");*/


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


	ll t, n, m, k, a, b, c, p, res, cont = 1;

	scanf("%lli", &t);

	while(t--){

		scanf("%lli %lli %lli", &n, &m, &k);

		for(ll i = 0; i < k; i++){
			scanf("%lli", &p);
			pp[p] = -1;
		}

		for(ll i = 0; i < m; i++){
			scanf("%lli %lli %lli", &a, &b, &c);
			edges.push_back(make_pair(c, make_pair(a, b)));
		}

		res = kruskal(n, m);

		printf("Case #%lli: ", cont);cont++;
		printf("%lli\n", res);

		for(ll i = 0; i < 300; i++){
			pp[i] = 0;
		}
		edges.clear();
		ordem.clear();
		pais.clear();
		res = 0;
	}
}