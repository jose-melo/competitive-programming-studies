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

string s1, s2;

int main(){


	getline(cin, s1);
	
	int ok = 0;
	for(int i = 0; i < s1.size(); i++){
		if(ok < 1){
			if(ok == 0 && s1[i] == '1'){
				s2.push_back('1');
			}else{
				ok = 1;
			}
		}else{
			s2.push_back(s1[i]);
		}
	}

	if(ok == 0){
		s2.pop_back();
	}


	cout << s2 << endl;


}
