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

vector<vector<int>> v[10];
int n, cont;
int pos;
bool cresce;

int fat(int i){

	if(i == 0)return 1;

	return fat(i-1)*i;
}


void solve(int n){

	if(n == 1){

		vector<int> aux;
		aux.pb(1);
		v[1].pb(aux);
		return;
	}

	solve(n-1);
	
	vector<int> aux;
	
	for(int i = 0; i < fat(n-1); i++){
		if(cresce){
			int j;
			aux.clear();
			for(j = 0; j < n; j++){
	
				FOR(k, 0, n-1){
					if(j == k)aux.pb(n);
					aux.pb(v[n-1][i][k]);
				}
				if(j != n-1){
					v[n].pb(aux);
					aux.clear();
				}
			}
			aux.pb(n);
			v[n].pb(aux);
			aux.clear();		

			cresce = false;
		}else{
			
			aux.clear();	
			FOR(k, 0, n-1)
				aux.pb(v[n-1][i][k]);
			aux.pb(n);
	
			v[n].pb(aux);
			aux.clear();

			for(int j = n-2; j >= 0; j--){
				FOR(k, 0, n-1){
					if(j == k)aux.pb(n);
					aux.pb(v[n-1][i][k]);
				}
				v[n].pb(aux);
				aux.clear();
			}
			cresce = true;
		}
	}
}

int main(){

	cin >> n;

	cresce = true;

	solve(n);

	
	for(int i = fat(n)-1; i >= 0; i--){
		for(auto x : v[n][i])
			cout << x << " ";
		cout << "\n";
	}



return 0;
}





