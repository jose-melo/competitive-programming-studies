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

int n, k;
vector<int> v;

int main(){

	cin >> n >> k;

	int aux;
	v.pb(-1);
	FI(n){
		cin >> aux;
		v.pb(aux);
	}

	for(int i = k+1; i <= n; i++){
		if(v[i] != v[k]){
			cout << "-1\n";
			return 0;
		}
	}

	for(int i = k-1; i >= 0; i--){
		if(v[i] != v[k]){
			cout << i << endl;
			return 0;
		}
	}

	




}
