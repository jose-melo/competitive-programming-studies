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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int main(){

	int n;
	vector<pii> v1, v2;

	cin >> n;

	int x, y;
	FI(n){
		cin >> x >> y;
		v1.pb(mp(x, y));
	}		
	
	sort(v1.begin(), v1.end());
	
	int cont = 0;
	for(int i = 1; i < n-1; i++){
		
		if(v1[i-1].fi == v1[i].fi && v1[i+1].fi == v1[i].fi){
			int ok = 0;

	
			for(int j = 0; j < i; j++){
				if(v1[j].se == v1[i].se){
					ok++;
					break;
				}
			}

			for(int j = i+1; j < n; j++){
				if(v1[j].se == v1[i].se){
					ok++;
					break;
				}
			}


			if(ok == 2)
				cont++;

		}

	}

	cout << cont << endl;


}
