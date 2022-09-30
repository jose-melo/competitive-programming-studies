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

	int t, s;
	vector<int> res;

	cin >> t;

	while(t--){
		cin >> s;
		int dig = 9;

		while(s-dig > 0){
			s-=dig;
			res.pb(dig);
			dig-=1;
		}
		if(s > 0)res.pb(s);
		
		reverse(res.begin(), res.end());

		for(auto x : res){
			cout << x;
		}
		cout << endl;
		res.clear();
	}
}

