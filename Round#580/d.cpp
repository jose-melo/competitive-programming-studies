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

int n;
int pai[112345];
int dist[112345];
vector<ll> v;

int bfs(int ini){
	
	queue<int> fila;

	for(int i = 0; i <= n; i++){
		dist[i] = INF;
		pai[i] = -1;
	}

	dist[ini] = 0;
	fila.push(ini);
	
	int res = INF;
	while(!fila.empty()){
		int atual = fila.front();
		fila.pop();

		for(int i = 0; i < n; i++){
			if(i != atual && (v[i] & v[atual]) != 0LL){
				if(dist[atual] + 1 < dist[i]){
					dist[i] = dist[atual] + 1;
					pai[i] = atual;
					fila.push(i);
				}else{
					if(i != pai[atual]){
						res = min(res, dist[atual] + dist[i] + 1);
					}
				}
			}
		}
	}
return res;
}




int main(){

	cin >> n;

	ll aux;
	FI(n){
		cin >> aux;
		if(aux != 0)
			v.pb(aux);
	}
	n = v.size();
	if(n > 800){
		cout << "3\n";
		return 0;
	}

	int resp = INF;
	for(int i = 0; i < n; i++){
		int tam_ciclo = bfs(i);
		//cout << tam_ciclo << endl;
	
		if(tam_ciclo < resp)
			resp = tam_ciclo;			
	}
	
	if(resp != INF)
		cout << resp << "\n";
	else
		cout << "-1\n";

return 0;
}




