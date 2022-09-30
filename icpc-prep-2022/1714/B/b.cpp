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

int memo[212345];

int main(){
	
	int t, n, tmp;
	vector<int> v;

	cin >> t;
	while(t--){
		cin >> n;
		FI(n){
			cin >> tmp;
			v.pb(tmp);
		}

		int res = 0;
		for(int i = n-1; i >= 0; i--){
			if(memo[v[i]]){
				res = i+1;
				break;
			}	
			memo[v[i]] = 1;
		}

		cout << res << endl;
		v.clear();
		for(int i = 0; i <= 200000; i++)memo[i]=0;

	}


}

