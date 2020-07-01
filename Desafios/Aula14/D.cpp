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

vector<pair<pii, int>> v1;
vector<pair<pii, int>> v2;
map <int, int> control; 

int foi[112345];


int main(){

	fastio;

	int n;

	cin >> n;
	
	int l, r;
	FI(n){
		cin >> l >> r;
		v1.pb(mp(mp(l, r), i));
		v2.pb(mp(mp(r, l), i));
		
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	ll cont = n;
	vector<pair<pii, int>>::iterator it2 = v2.begin();
	vector<pair<pii, int>>::iterator it = v1.begin();
	while(it != v1.end()){
		pair<pii, int> a = *it, b = *it2;
		cont += max(a.fi.fi, b.fi.fi);
		it++;
		it2++;
	}

	cout << cont << "\n";
return 0;
}



