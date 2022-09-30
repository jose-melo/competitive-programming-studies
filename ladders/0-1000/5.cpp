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

bool ok(int n){
	
	int digs[11];

	for(int i = 0; i <= 9; i++)
		digs[i] = 0;

	while(n > 0){
		if(digs[n%10] != 0)
			return false;
		
		digs[n%10] = 1;
		n /= 10;
	}
	return true;
}

int main(){

	int n;

	cin >> n;

	for(int i = n+1; i <= 10000; i++){
		if(ok(i)){
			cout << i << endl;
			return 0;
		}

	}



}
