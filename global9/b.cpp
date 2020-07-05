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

int t, n, m;

int main(){

	cin >> t;


	while(t--){

		cin >> n >> m;

		int mat[n+5][m+5];
		int in[n+5][m+5];

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> in[i][j];

		for(int i = 0; i <= n+2; i++)
			for(int j = 0; j <= m+2; j++)
				mat[i][j] = 0;

		for(int i = 0; i <= n+1; i++)
			in[i][0] = in[i][m+1] = -1;

		for(int i = 0; i <= m+1; i++)
			in[0][i] = in[n+1][i] = -1;


		int cont;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cont = 0;
				if(in[i-1][j] != -1)cont++;
				if(in[i+1][j] != -1)cont++;
				if(in[i][j-1] != -1)cont++;
				if(in[i][j+1] != -1)cont++;
				mat[i][j] = cont;
	
			}
		}

		int ok = 1;
		for(int i = 1; i <= n && ok; i++){
			for(int j = 1; j <= m && ok; j++){
				if(in[i][j] > mat[i][j]){
					cout << "NO\n";
					ok = 0;
				}		
			}
		}

		if(ok){
			cout << "YES\n";
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					cout << mat[i][j] << " ";
				}
				cout << endl;
			}
		}

	}



}

