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
	vector<int> v[123];

	cin >> n;
	
	int aux;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin >> aux;
			v[i].pb(aux);
		}	
	}

	int sum =0;
	for(int i = 0; i < 3; i++){
		sum = 0;
		for(int j = 0; j < n; j++){
			sum += v[j][i];
		}

		if(sum){
			cout << "NO\n";
			return 0;
		}	
	}
	
	cout << "YES\n";
	
}
