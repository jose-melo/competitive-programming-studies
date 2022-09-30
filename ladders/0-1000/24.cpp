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

	string s1, s2, s3;

	cin >> s1 >> s2 >> s3;

	int v1[30], v2[30];

	memset(v1, 0, sizeof(v1));
	memset(v2, 0, sizeof(v2));

	for(auto x: s1)
		v1[x-'A'] += 1;

	for(auto x: s2)
		v1[x-'A'] += 1;

	for(auto x : s3)
		v2[x - 'A'] += 1;


	bool ok = true;
	for(int i = 0; i < 30; i++){
		if(v1[i] != v2[i]){
			ok = false;
			break;
		}
	}

	if(ok)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;

}
