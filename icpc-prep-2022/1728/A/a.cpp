#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int main(){

	int  t, n;
	vector<pii> v;

	cin >> t;

	while(t--){
		cin >> n;
		int tmp;
		FI(n){
			cin >> tmp;	
			v.pb(mp(tmp, i+1));	
		}
		
		sort(v.begin(), v.end());
		cout << v[v.size()-1].se << endl;
		v.clear();
	}
}

