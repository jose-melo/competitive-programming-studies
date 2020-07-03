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

int t;
string s, resp;

int main(){

	cin >> t;

	while(t--){

		int ch, ok = 0;
		cin >> s;

		resp.clear();
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '0')
				ok++;
		}

		if(ok == 0 || ok ==s.size()){
			cout << s << endl;
			continue;
		}


		resp.pb(s[0]);
		ch = s[0] - '0';
		ch ^= 1;
		for(int i = 1; i < s.size(); i++){
			if(s[i] == ch + '0'){
				resp.pb(s[i]);
				ch ^= 1;
			}else{
				resp.pb(ch + '0');
				resp.pb(s[i]);
			}
		}
			
		cout << resp << endl;
	}


}

