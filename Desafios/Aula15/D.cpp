#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int 
#define pii pair<ll, int>
#define INF 4e8
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


vector<pii> listAdj[412345];
vector<pii> listAdj2[412345];
ll dist[412345];
ll dist2[412345];
vector<pii> list;

int n;

int dijkstra2(int ini, int fim){

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	FI(300002)
		dist2[i] = INF;

	dist2[ini] = 0;

	pq.push(mp(dist2[ini], ini));	

	while(!pq.empty()){
		
		pii aux = pq.top();
		int node = aux.se;
		pq.pop();

		for(auto x : listAdj2[node]){
			if(dist2[x.fi] > dist2[node] + x.se){
				dist2[x.fi] = dist2[node] + x.se;
				pq.push(mp(dist2[x.fi], x.fi));
			}
		}
	}
return dist2[fim];
}

int dijkstra(int ini, int fim){

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	FI(300002)
		dist[i] = INF;

	dist[ini] = 0;

	pq.push(mp(dist[ini], ini));	

	while(!pq.empty()){
		
		pii aux = pq.top();
		int node = aux.se;
		pq.pop();

		for(auto x : listAdj[node]){
			if(dist[x.fi] > dist[node] + x.se){
				dist[x.fi] = dist[node] + x.se;
				pq.push(mp(dist[x.fi], x.fi));
			}
		}
	}
return dist[fim];
}

int main(){

	fastio;

	int T, m, k, ini, fim, a, b, c;
	ll res;

	cin >> T;

	while(T--){
		
		res = INF;

		cin >> n >> m >> k >> ini >> fim;

		for(int i = 0; i < m; i++){
			cin >> a >> b >> c;
			listAdj[a].pb(mp(b, c));
			listAdj2[b].pb(mp(a, c));
		}
		
		dijkstra(ini, fim);

		res = dist[fim];
	
		dijkstra2(fim, ini);

		for(int i = 0; i < k; i++){
			cin >> a >> b >> c;		
	
			res = min(res, dist[b] + c + dist2[a]);

			res = min(res, dist[a] + c + dist2[b]);

		}
	
	
		if(res != INF)
			cout << res << "\n";
		else
			cout << "-1\n";


		for(int i = 0; i <= 3*n; i++){
			listAdj[i].clear();
			listAdj2[i].clear();
		}
	
	}

}




