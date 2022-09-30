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

	string s, resp;

	cin >> s;

	int i = 0, c = 0;
	while(i < s.size()){
		if(i < s.size() - 2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
			i += 3;
			if(c)
				resp.pb(' ');
			c = 0;
		}else{
			resp.pb(s[i]);
			i++;
			c = 1;
		}
	}

	cout << resp << endl;



}
