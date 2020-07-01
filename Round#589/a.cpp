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

int digs[19];

int f(int x){

	
	for(int i = 0; i <= 9; i++)
		digs[i] = 0;

	int dig;
	while(x != 0){
		dig = x % 10;
		if(digs[dig] == 1)
			return 0;
		digs[dig] = 1;
		x /= 10;

	}
	
	return 1;
}

int main(){

	int l, r;

	cin >> l >> r;

	for(int i = l; i <= r; i++){
		if(f(i)){
			cout << i << endl;
			return 0;
		}
	}

	cout << "-1" << endl;

	return 0;
}


