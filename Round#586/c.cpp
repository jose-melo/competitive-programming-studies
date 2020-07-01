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
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int main(){

	string s;
	int resp[512345];

	cin >> s;
	

	int mn = s[0];
	resp[0] = 1;	
	for(int k = 1; k < s.size(); k++){
		if(s[k] <= mn){
			resp[k] = 1;
			mn = s[k];
		}else{
			resp[k] = 0;
		}
	}

	for(int i = 0; i < s.size(); i++){
		if(resp[i]==0)
			cout << "Ann" << endl;
		else
			cout << "Mike" << endl;
	}
return 0;
}
