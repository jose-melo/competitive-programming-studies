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


int n, m;
vector<int> v;


int main(){

	cin >> n >> m;

	int aux;
	FI(m){
		cin >> aux;
		v.pb(aux);
	} 
	sort(v.begin(), v.end());
	
	
	int mn = 1123;
	for(int i = 0; i < m-n+1; i++){
		if(v[i+n-1] - v[i] < mn)
			mn = v[i+n-1] - v[i];

	}

	cout << mn << endl;

}
