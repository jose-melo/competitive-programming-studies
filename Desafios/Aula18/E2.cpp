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

set<pii> segs;
vector<int> listaDivisores;


int main(){

	int n, m;

	cin >> n >> m;

	int a, b;
	FI(m){
		cin >> a >> b;
		segs.insert(mp(a, b));
	}
	

	for(int i = 1; i*i <= n; i++)
		if(n % i == 0){
			listaDivisores.pb(i);
			if(i*i != n && i != 1)listaDivisores.pb(n/i);
		}

	bool res;
	for(auto x : listaDivisores){
		res = true;		
		for(auto s : segs){
			int ini = s.fi + x;
			int end = s.se + x;
			
		
			if(ini > n)
				ini = (ini % (n+1))+1;

			if(end > n)
				end = (end % (n+1)) + 1;

			if(segs.find(mp(ini, end)) == segs.end() && segs.find(mp(end, ini)) == segs.end())	
				res = false;

			if(!res)
				break;
		
		}
		if(res)
			break;

	}
	
	if(res)
		cout << "Yes\n";
	else
		cout << "No\n";
return 0;
}
