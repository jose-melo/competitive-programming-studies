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

	string s;

	cin >> s;

	int i = 0;
	while(i < s.size()){
		
		if(i < s.size()-2 && s[i] == '1' && s[i+1] == '4' && s[i+2] == '4'){
			i += 3;
		}else{
			if(i < s.size()-1 && s[i] == '1' && s[i+1] == '4'){
				i += 2;
			}else{
				if(s[i] == '1'){
					i++;
				}else{
					cout << "NO\n";
					return 0;
				}
			}

		}
	}

	cout << "YES\n";

}
