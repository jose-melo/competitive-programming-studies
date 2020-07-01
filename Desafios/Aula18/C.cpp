#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int pais[11234];
int ordem[11234];
int n;
ll cont;
vector<pair<int, pii>> listAdj;

void build(){
	
	FOR(i, 1, n+1){
		pais[i] = i;
		ordem[i] = 1;		
	}
return;
}

int find(int node){
	
	if(pais[node] == node)
		return node;

	pais[node] = find(pais[node]);
return pais[node];
}

bool isSameSet(int a, int b){
	return find(a) == find(b);
}

void UNION(int a, int b){

	if(!isSameSet(a, b)){

		int x = find(a);
		int y = find(b);

		if(ordem[x] < ordem[y]){
			pais[x] = y;
		}else{
			pais[y] = x;
			if(ordem[x] == ordem[y])
				ordem[x]++;
		}
	}
return;
}

int main(){

	fastio;
	int m;

	cin >> n >> m;

	build();
	
	int a, b, peso;
	FI(m){
		cin >> a >> b >> peso;
		listAdj.pb(mp(peso, mp(a, b)));	
	}

	sort(listAdj.begin(), listAdj.end());

	cont = 0;
	for(auto x : listAdj){
		peso = x.fi;
		a = x.se.fi;
		b = x.se.se;

		if(!isSameSet(a, b)){
			cont += peso;
			UNION(a, b);	
		}
	}

	cout << cont << "\n";
return 0;
}









