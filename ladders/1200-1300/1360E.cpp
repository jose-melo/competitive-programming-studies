#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int t, n;

int main(){

	cin >> t;

	while(t--){
	
		cin >> n;

		int mat[n+10][n+10];
		string s[n+1];

		for(int i = 0; i <= n; i++){
			getline(cin, s[i]);
		}

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				mat[i][j] = (s[i+1][j] - '0');

		for(int i = 0; i <= n; i++)
			mat[n][i] = mat[i][n] = 1;

		bool ok = true;
		for(int i = 0; i < n && ok; i++){
			for(int j = 0; j < n && ok; j++){
				if(mat[i][j] == 1){
					if(mat[i+1][j] != 1 && mat[i][j+1] != 1)
						ok = false;
				}
			}
		}

		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	


}

