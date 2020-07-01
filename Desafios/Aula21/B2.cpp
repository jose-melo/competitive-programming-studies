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
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int n, m, respXor;
int matriz[600][600];

int main(){

	fastio;

	cin >> n >> m;

	
	FOR(i, 1, n+1)
		FOR(j, 1, m+1)
			cin >> matriz[i][j];
		

	for(int linha = 1; linha <= n; linha++){
		respXor = respXor ^ matriz[linha][1];
	}
	
	if(respXor != 0){
		cout << "TAK\n";
		for(int i = 1; i <= n; i++)
			cout << "1 " ;	
		cout << "\n";
		return 0;
	}

	for(int linha = 1; linha <= n; linha++){

		for(int col = 2; col <= m; col++){
			if(matriz[linha][col] != matriz[linha][1]){
				cout << "TAK\n";	
				for(int i = 1; i <= n; i++){
					if(i == linha)
						cout << col << " ";
					else
						cout << "1 ";				
				}
				cout << "\n";
				
				return 0;
			}
		}
	}
	

	cout << "NIE\n";
return 0;
}





