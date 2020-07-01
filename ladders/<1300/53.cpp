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

	int i = 0, n = s.size();
	while(i < s.size()){
		if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] - 'A' + 'a';

		if(s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i'){
			for(int j = i+1; j < s.size(); j++) 
				s[j-1] = s[j];
			s.pop_back();
			
		}else{

			s.pb(s[n-1]);
			for(int j = s.size(); j > i; j--)
				s[j] = s[j-1];
			s[i] = '.';	
			i += 2;
		}	

	}	
	
	cout << s << endl;	



}
