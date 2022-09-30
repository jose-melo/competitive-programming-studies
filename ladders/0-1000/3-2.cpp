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

	int n, t;
	string s;

	cin >> n >> t;

	cin >> s;

	
	int j = n-1;
	for(int i = n-1; i >= 0; i--){
		if(s[i] != 'B')
			continue;

		int idx = min(j, i+t);
		s[idx] = 'B';
		
		if(idx != i)
			s[i] = 'G';
		j = max(0,idx-2);
	}


	cout << s << endl;


}
