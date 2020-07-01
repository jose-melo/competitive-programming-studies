#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ii pair<ll, ll>
#define MAX_N 210000

map<ll, ll> input;
ll pos, possivel, n, k;
ll** machine;
int vis[MAX_N];

void dfs(ll maq, ll node){

	//printf("maq = %lli node = %lli possivel = %lli, vis[node] = %d\n", maq, node, possivel, vis[node]);

	if(node == 1){
		possivel = 1;
		return;
	}

	if(possivel == 1)return;
	if(vis[node]== 1)return;
	vis[node] = 1;


	for(ll i = 1; i <= k && possivel == 0; i++){
		//printf("i = %lli vis[machine[i][node] = %lli] = %d\n", i, machine[i][node], vis[machine[i][node]]);
		if(!vis[machine[i][node]])
			dfs(i, machine[i][node]);
	}
return;
}

int main(){

	ll aux, obj;

	scanf("%lli", &n);

	for(ll i = 1; i <= n; i++){
		scanf("%lli", &aux);
		input.insert(make_pair(aux, i));
	}

	scanf("%lli", &k);

	machine = (ll**) malloc((k+3)*sizeof(ll*));
	for(ll i = 0; i <= k; i++)
		machine[i] = (ll*) malloc((n+3)*sizeof(ll));

	for(ll i = 1; i <= k; i++){
		for(ll j = 1; j <= n; j++){
			machine[i][j] = 0;
		}
	}

	for(ll i = 1; i <= k; i++){
		for(ll j = 1; j <= n; j++){
			scanf("%lli", &aux);
			machine[i][aux] = j;
		}
	}

	scanf("%lli", &obj);
	
	map<ll, ll>::iterator x = input.find(obj);

	pos = x->second;

	possivel = 0;
	
	dfs(0, pos);

	if(possivel)
		printf("YES\n");
	else
		printf("NO\n");
return 0;
}




