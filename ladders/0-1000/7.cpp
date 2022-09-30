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

	int cont1 = 0, cont2 = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z')
			cont1++;
		else cont2++;
	}

	if(cont1 >= cont2){
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i]-'A' + 'a';
		}
	}else{
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= 'a' && s[i] <= 'z'){
				s[i] = s[i] - 'a' + 'A';
			}
		}
	}

	cout << s << endl;

}

