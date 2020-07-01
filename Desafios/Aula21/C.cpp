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


int pais[112345];
int ordem[112345];
int n, m, T;


void build(){

	FOR(i, 1, n+1){
		pais[i] = i;
		ordem[i] = 1;
	}
return;
}

int find(int a){
	
	if(a == pais[a])	
		return a;

	pais[a] = find(pais[a]);
return pais[a];
}

bool isSameSet(int a, int b){
	return find(a) == find(b);
}


void UNION(int a, int b){

	int x, y;

	if(!isSameSet(a, b)){

		x = find(a);
		y = find(b);

		if(ordem[x] < ordem[y]){
			pais[x] = y;
		}else{
			pais[y] = x;
			
			if(ordem[x] == ordem[y])
				ordem[x]++;
		}
	}
}

ll contaPot(ll num){

	ll cont = 0;

	while(num > 1){
		cont++;
		num /= 2;
	}
return cont;
}

vector<pair<int, pii>> listAdj;

int main(){

	fastio;

	cin >> T;

	while(T--){

		cin >> n >> m;
	
		int a, b;
		ll c;
		FI(m){
			cin >> a >> b >> c;

			c = contaPot(c);
			
			listAdj.pb(mp(c, mp(a,b)));
		}

		sort(listAdj.begin(), listAdj.end());

		build();

		ll resp = 0;
		for(auto x : listAdj){
			c = x.fi;
			a = x.se.fi;
			b = x.se.se;

			if(!isSameSet(a, b)){
				resp += c;
				UNION(a, b);
			}
		}

		cout << resp + 1 << "\n";

		listAdj.clear();

	}

return 0;
}
















