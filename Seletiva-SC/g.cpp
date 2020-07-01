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
int v[112345], resp[112345];
set<pii> conji;

int main(){

	int n;

	cin >> n;

	FI(n)
		cin >> v[i+1];

	for (int i = 1; i <= n; i++){
		auto p = conji.lower_bound(mp(v[i], INF));
		vector<pii> au;
		if(p->fi == v[i])p = conji.end();
		auto q = conji.begin();
		if (p != conji.end()){
			cout << "OLA" << endl;	
			while(q != p){

				cout << "i = " << i << " q = " << q->fi << " " << q->se << endl;
				resp[i] = i - (q->second) - 1;

				cout << "resp = " << resp[i] << endl;
				au.pb(mp(q->first, q->second));
				q++;	
			}
			
			for(auto x : au)
				conji.erase(mp(x.fi, x.se));
		}
		conji.insert(mp(v[i], i));
	}

	for(auto it : conji)
		resp[it.se] = n - it.se - 1;
	

	for (int i = 1; i <= n; i++)
		resp[i] = min(v[i], resp[i]);

	for (int i = 1; i <= n; i++)
		cout << resp[i]<< " ";
	cout << endl;
		
	return 0;
}
