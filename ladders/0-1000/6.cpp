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

int m[6][6];

int main(){

	int resp[6][6];

	
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> m[i][j];

	memset(resp, 0, sizeof(resp));	

	int sum;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			sum = m[i][j] + m[i-1][j] + m[i][j+1] + m[i+1][j] + m[i][j-1] + 1;
			
			resp[i][j] = sum%2;
		}
	}

	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++)
			cout << resp[i][j];
	
		cout << endl;
	}

	return 0;
}

