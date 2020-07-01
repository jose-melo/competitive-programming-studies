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

set <pii> resp;
int v[100100];
int ans[100100];


int main (){
	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++)
		cin >> v[i];

	for(int i = 0 ; i < n ; i++){
		
		if(i == 0){
			resp.insert(mp(v[i], i));
			continue;
		}
		
		vector <pii> aux;
		pii a;

		for(auto it : resp){
			if(it.first < v[i]){
				ans[it.se] = min( i - it.se - 1, v[it.se] + it.se);
			}else{	
				a.fi = it.fi;
				a.se = it.se;	
				break;
			}
		}
		
		resp.erase(resp.begin(), resp.find(a));

		resp.insert(mp(v[i], i));
	}

	for(auto it : resp){	
		ans[it.se] = min(n - it.se - 1, v[it.se]);
	}

	for(int i = 0 ; i < n ; i++)
		cout << ans[i] << " ";
	cout << endl;

}
