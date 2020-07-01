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
int cont, idx1, idx2;

int main(){


	getline(cin, s1);
	getline(cin , s2);

	if(s1.size() != s2.size()){
		cout << "NO\n";
		return 0;
	}

	for(int i = 0; i < s1.size(); i++){
		if(s1[i] != s2[i]){
			cont++;
			if(cont == 1)
				idx1 = i;
			else
				idx2 = i;
		}
	}

	if(cont != 2){
		cout << "NO\n";
		return 0;
	}
	
	if(s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]){
		cout << "YES\n";
		return 0;
	}

	cout << "NO\n";


}
