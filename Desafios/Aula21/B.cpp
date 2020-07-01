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

int memo1[501][11], memo2[502][11], truncou[500][11];
int n, m;
int matriz[512][512];
bool clean;

int main(){

	fastio;

	cin >> n >> m;

	
	
	FOR(i, 1, n+1)
		FOR(j, 1, m+1)
			cin >> matriz[i][j];
	if(m == 1 && 	){
		cout << "TAK\n";
		cout << "1\n";

		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int bit = 0; bit < 10; bit++){
			memo1[i][bit] = -1;
			memo2[i][bit] = -1;
			truncou[i][bit] = 0;
		}
	}

	int bit;


	for(int i = 1; i <= n; i++){	
		for(int bit = 0; bit < 10; bit++){	
			for(int j = 1; j <= m; j++){
				if((matriz[i][j] & (1<<bit)) == 1)
					memo1[i][bit] = j;
				else
					memo2[i][bit] = j;	
			}

			if(memo1[i][bit] == -1 || memo2[i][bit] == -1)
				truncou[i][bit] = 1;
		}
	}
	
	int guarda, idx;
	vector<int> resp;


	clean = false;
	for(int bit = 0; bit < 10; bit++){		
		guarda = -1;
		for(int linha = 1; linha <= n; linha++){
			if(truncou[linha][bit]){	
				guarda = max(memo1[linha][bit], memo2[linha][bit]);
			}else{
				clean = true;
				idx = linha;
			}
		}

		if(clean){
			if(guarda == -1){
				resp.pb(memo2[1][bit]);
				for(int linha = 2; linha <= n; linha++)
					resp.pb(memo1[linha][bit]);
			}else{
				for(int linha = 1; linha <= n; linha++){
					if(linha == idx){
						if(guarda){
							resp.pb(memo2[idx][bit]);
							continue;
						}else{
							resp.pb(memo1[idx][bit]);
							continue;
						}
					}		

					resp.pb(max(memo1[idx][bit], memo2[idx][bit]));						
				}   	
			}
			break;	
		}
	}


	if(resp.empty()){
		cout << "NIE\n";
		return 0;
	}

	cout << "TAK\n";
	for(auto x : resp)
		cout << x << " ";	
	cout << "\n";



}





