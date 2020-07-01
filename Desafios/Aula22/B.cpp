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


multiset<int> goblins[11234];

int g;

int main(){

	cin >> g;

	int x, y, m, r, cont = 0;
	FI(g){
		cin >> x >> y;
		
		goblins[x].insert(y);		

	}	

	long double dist;
	cin >> m;
	FI(m){
		cin >> x >> y >> r;
		for(int p = x-r; p <= x+r && p <= 10000; p++){
			if(p < 0)continue;	
			
			int raiz = sqrt(r*r - (x-p)*(x-p));
			int y1 = y + raiz;
			int y2 = y - raiz;
			
			set<int>::iterator it = goblins[p].lower_bound(y2);
			while(it != goblins[p].end()){
				if(*it > y1)break;

				it++;
				cont++;

			}
			goblins[p].erase(goblins[p].lower_bound(y2), it);			
		}
	}

	cout << g - cont << "\n";


return 0;
}



