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
vector<pair<int, pii>> v;


int main(){

	cin >> n;
	
	int a, b;
	int mx = -1;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.pb(mp(a, mp(b, i+1)));
		
		if(b > mx)
			mx = b;

	}

	sort(v.begin(), v.end());

	int k = 1;
	while(k < v.size() && v[k].fi == v[0].fi){
		k++;
	}

	k--;

	if(k >= 0 && v[k].se.fi == mx)
		cout << v[k].se.se << endl;
	else
		cout << "-1\n";


}
