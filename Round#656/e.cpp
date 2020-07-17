#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int t, n, m;
vector<int> listAdj1[112345];
vector<int> listAdj2[112345];
vector<int> resposta;
int visitado[112345];

void dfs(int noh){

	visitado[noh] = 1;

	for(auto x : listAdj1[noh]){
		if(!visitado[x])
			dfs(x);
	}
	resposta.pb(noh);
}


int main(){

	cin >> t;

	while(t--){
	
		cin >> n >> m;

		for(int i = 0; i < n; i++){
			listAdj1[i].clear();
			listAdj2[i].clear();
		}

		int a, x, y;
		for(int i = 0; i < n; i++){
			cin >> a >> x >> y;

			if(a){
				listAdj1[x].pb(y);
			}else{
				listAdj2[x].pb(y);
				listAdj2[y].pb(x);
			}
		}

		memset(visitado, 0, sizeof(visitado));
		resposta.clear();

		for(int i = 0; i < n; i++){
			if(!visitado[i])
				dfs(i);
		}

		reverse(resposta.begin(), resposta.end());

		set<pii> marcar;
	    set<int>	marcar2;
		vector<pii> resp;
		for(int i = 0; i < resposta.size(); i++){
			marcar2.insert(resposta[i]);
			for(auto x : listAdj2[resposta[i]]){
				if(marcar.find(mp(x, i)) == marcar.end()){
					resp.pb(mp(i, x));
					marcar.insert(mp(i, x));
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(auto x : listAdj2[i]){
				if(marcar.find(mp(x, i)) == marcar.end() && marcar.find(mp(i, x)) == marcar.end()){
					if(marcar2.find(x) == marcar2.end()){
						resp.pb(mp(x, i));
					}else{
						resp.pb(mp(i, x));
					}
				}
			}
		}
	
	
	}



}

