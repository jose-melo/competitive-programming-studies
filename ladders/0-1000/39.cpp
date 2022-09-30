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

	int n;
	ll v[100];
	
	cin >> n;

	if(n == 0){
		cout << "0 0 0" << endl;
		return 0;
	}

	if(n == 1){
		cout << "1 0 0" << endl;
		return 0;
	}

	if(n == 2){
		cout << "1 1 0" << endl;
		return 0;
	}

	if(n == 3){
		cout << "1 1 1" << endl;
		return 0;
	}


	v[0] = 0;
	v[1] = 1;

	for(int i = 2; i < 100; i++){
		v[i] = v[i-1] + v[i-2];

		if(v[i] == n){
			cout << v[i-1] << " " << v[i-3] << " " << v[i-4] << endl;
			return 0;
		}

	} 





}
