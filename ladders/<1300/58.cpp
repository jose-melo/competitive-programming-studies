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

string s;


int main(){

	cin >> s;
	string resp = "hello";
	int cont = 0;

	for(int i = 0; i < s.size(); i++){
		
		if(resp.find(s[i]) != string::npos){
			if(resp[cont] == s[i])
				cont++;
		}
	}
	if(cont <= 4)
		cout << "NO\n";
	else
		cout << "YES\n";

}
