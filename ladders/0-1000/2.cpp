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
	
	int n = 5;
	int m[10][10];

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> m[i][j];
		}
	}

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){

			if(m[i][j] == 1){
				cout << abs(i-2)+abs(j-2) << endl;
				return 0;
			}
		}
	}

	return 0;


}
