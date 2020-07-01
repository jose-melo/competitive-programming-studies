#include <bits/stdc++.h>
using namespace std;

#define MAX_N 110
#define ll long long int

vector<ll> pais, ordem;
vector<pair<ll, ll>> add, rm;
char matriz[MAX_N][MAX_N];
char res[MAX_N][MAX_N];
ll vis[MAX_N];
ll pi[MAX_N];

ll d, a;


void INIT(ll n){

	pais.assign(n+1, 0);
	ordem.assign(n+1, 0);

	for(ll i = 0; i <= n; i++)
		pais[i] = i;
return;
}


ll find(ll i){

	if(i != pais[i])
		pais[i] = find(pais[i]);
return pais[i];
}	

bool isSameSet(ll i, ll j){
	return find(i) == find(j);
}

void UNION(ll i, ll j){

	while(!isSameSet(i, j)){

		ll x = find(i);	
		ll y = find(j);

		if(ordem[x] > ordem[y]){
			pais[y] = x;
		}else{
			pais[x] = y;
			if(ordem[x] == ordem[y])
				ordem[y]++;
		}
	}
}



void DFS(ll node, ll n){

	//printf("node = %lli n = %lli vis[node] = %lli\n", node, n, vis[node]);

	if(vis[node] == 1)return;

	vis[node] = 1;

	for(ll i = 1; i <= n; i++){

		//printf("i = %lli pi[node] = %lli matriz[node-1][i-1] = %c\n", i, pi[node], matriz[node-1][i-1]);

		if(matriz[node-1][i-1] == '1' && i != pi[node]){
			if(vis[i] == 1){
				//printf("retirei (%lli %lli)\n", node, i);
				rm.push_back(make_pair(node, i));
			}else{
				pi[i] = node;
				UNION(node, i);
				DFS(i, n);
			}
		}
	}
return;
}

int main(){

	ll n, cont = 0;

	scanf("%lli", &n);
	scanf("%lli %lli", &d, &a);

	for(ll i = 0; i < n; i++)
		for(ll j = 0; j < n; j++)
			scanf(" %c", &matriz[i][j]);


	INIT(n);

	DFS(1, n);
	for(ll i = 2; i <= n; i++){
		if(!vis[i]){
			//printf("add (%lli %lli)\n",i-1, i);
			add.push_back(make_pair(i-1, i));
			UNION(i-1, i);
			DFS(i, n);
		}
	}	

	for(auto x = add.begin(); x < add.end(); x++){
		if(res[x->first - 1][x->second - 1] != 'a'){
			res[x->first - 1][x->second - 1]  = 'a';
			res[x->second - 1][x->first - 1] = 'a';
			cont += a;
		}
	}

	for(auto x = rm.begin(); x < rm.end(); x++){
		if(res[x->first - 1][x->second - 1] != 'd'){
			res[x->first - 1][x->second - 1] = 'd';
			res[x->second - 1][x->first - 1] = 'd';
			cont += d;
		}
	}

	printf("%lli\n", cont);

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(res[i][j] == 0)
				printf("0");
			else
				printf("%c", res[i][j]);
		}
		printf("\n");
	}

return 0;
}




