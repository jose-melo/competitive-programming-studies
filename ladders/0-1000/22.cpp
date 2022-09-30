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

	vector<string> v;
	int n;

	cin >> n;

	string s;
	FI(n){
		cin >> s;
		v.pb(s);
	}

	for(auto x : v){

		if(x.size() > 10)
			cout << x[0] << x.size() - 2 << x[x.size()-1] << endl;
		else
			cout << x << endl;
	
	}
	


}
