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


int n;
vector<pair<int, int>> v, resp;

int main(){


	cin >> n;

	int aux;
	for(int i = 1; i <= n; i++){
		cin >> aux;
		v.pb(mp(aux, i));
	}

	sort(v.begin(), v.end());

	v.pb(mp(-1, -1));

	int k = 0, dif, ok;
	while(k < v.size()){

		ok = 1;
		if(v[k+1].fi == v[k].fi){
			dif = v[k+1].se - v[k].se;	
			while(v[k+1].fi == v[k].fi){
				if(v[k+1].se - v[k].se != dif)
					ok = 0;
				k++;
			}	
		}else{
			dif = 0;
		}
		if(ok)
			resp.pb(mp(v[k].fi, dif));
		k++;
	}

	sort(resp.begin(), resp.end());


	cout << resp.size()-1 << endl;
	for(auto x : resp){
		if(x.fi != -1)
			cout << x.fi << " " << x.se << endl;
	}


}
