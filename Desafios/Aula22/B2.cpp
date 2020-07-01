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

typedef struct{

	int x;
	double y;
	int tipo;

}gob;

bool comp(gob a, gob b){

	if(a.x < b.x)
		return true;

	if(a.x == b.x)
		if(abs(a.y - b.y) >= 0.00000001){
			if(a.y > b.y)
				return true;
		}else{
			if(a.tipo > b.tipo)
				return true;
		}

return false;
}


vector<gob> goblins;

int main(){

	int g, x, y, r, m;

	cin >> g;

	FI(g){
		gob aux;

		cin >> x >> y;

		aux.x = x;
		aux.y = y;
		aux.tipo = 1;
	
		goblins.pb(aux);

	}

	cin >> m;

	FI(m){

		cin >> x >> y >> r;

		for(int p = x-r; p <= x+r; p++){
			double y_2 = y + sqrt(r*r - (double)(x-p)*(x-p));
			double y_0 = y - sqrt(r*r - (double)(x-p)*(x-p));

			gob g;
			g.x = p;
			g.y = y_2;
			g.tipo = 2;	

			goblins.pb(g);

			g.x = p;
			g.y = y_0;
			g.tipo = 0;
		
			goblins.pb(g);

		}
	
		sort(goblins.begin(), goblins.end(), comp);
		
		int dentro = 0, resp = 0;
		for(auto gobb : goblins){

			if(gobb.tipo == 0){
				dentro--;
				continue;
			}

			if(gobb.tipo == 3){
				dentro++;
				continue;
			}

			if(gobb.tipo == 1 && dentro == 0){
				resp++;
			}
		}

		cout << resp << "\n";
	}	
}








