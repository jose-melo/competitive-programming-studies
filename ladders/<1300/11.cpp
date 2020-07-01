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
	
	int n, m;
	int v[100];
	vector<int> p;

	cin >> n >> m;

	memset(v, 0, sizeof(v));
	for(int i = 4; i < 80; i+=2)
		v[i] = 1;

	for(int i = 3; i < 80; i += 2){
		if(v[i] == 1)continue;
		for(int j = i+i; j < 80; j += i)
			v[j] = 1;
	}

	for(int i = 2; i < 80; i++)
		if(v[i] == 0)
			p.pb(i);


	for(int i = 0; i < p.size(); i++){
		if(p[i] == n){
			if(p[i+1] == m){
				cout << "YES" << endl;
				return 0;
			}else{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

}
