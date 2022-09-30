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


int v1[300], v2[300];

int main(){

	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);

	for(int i = 0; i < s1.size(); i++){
		v1[s1[i]]++;
	}


	for(int i = 0; i < s2.size(); i++){
		v2[s2[i]]++;
	}
	

	for(int i = 0; i < 300; i++){

		if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')){
			if(v2[i] > v1[i]){
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";


}
