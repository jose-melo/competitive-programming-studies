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

vector<pii> grupos[112345];
int n, m, diff;

int main(){

	fastio;

	cin >> n >> m;

	int a, b;
	FI(m){
		cin >> a >> b;
		if(a < b){
			int aux = b;
			b = a;
			a = aux;
		}else if(a > b && ((a-b) > n-(a-b))){
			int aux = b;
			b = a;
			a = aux;
			grupos[n - (b-a)].pb(mp(a, b));
		}	

		grupos[min(a-b, n - (a-b))].pb(mp(a,b));
	}
	bool primeiro = true;
	bool res = true;
	
	for(int i = 1; i <= n; i++){
		cout << "grupos[" << i << "] = \n";
		for(auto x : grupos[i])
			cout << "(" << x.fi << " " << x.se << ")  ";
		cout << "\n";
		
	}



	for(int i = 1; i <= n && res; i++){
		if(grupos[i].empty())continue;
		if(grupos[i].size() == 1){
			res = false;
			break;
		}
	
		for(int j = 0; j < grupos[i].size()-1 && res; j++){			
			if(primeiro){
				diff = abs(grupos[i][j+1].fi - grupos[i][j].fi);
				primeiro = false;
				cout << "diff = ";debug(diff);
			}
	
			int dif1 = min(abs(grupos[i][j+1].fi	- grupos[i][j].fi), n - abs(grupos[i][j+1].fi	- grupos[i][j].fi));
			int dif2 = min(abs(grupos[i][j+1].se	- grupos[i][j].se), n - abs(grupos[i][j+1].se	- grupos[i][j].se));

			cout << "dif1 = " << dif1 << " dif2 = " << dif2 << "\n";

			if(dif1 != diff || dif2 != diff)
				res = false;
		}
	}

	if(res)
		cout << "Yes\n";
	else
		cout << "No\n";

return 0;
}


