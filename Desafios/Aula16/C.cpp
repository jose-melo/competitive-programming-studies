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

int memo[312345][30];
int update[312345];
vector<int> listAdj[312345];
string s;
int grau[312345];
queue<int> fila;
int cont;

void topSort(){

	 cont = 0;	
	
	while(!fila.empty()){

		int noh = fila.front();
		fila.pop();

		for(auto x : listAdj[noh]){
			FOR(i, 0, 27)
				if(i != s[x-1] - 'a'){
					if(memo[x][i] < memo[noh][i])
						memo[x][i] = memo[noh][i]; 		
				}else{
					if(memo[x][i] < memo[noh][i] + 1)
						memo[x][i] = memo[noh][i] + 1;
				}

			grau[x]--;
		
			if(grau[x] == 0)
				fila.push(x);
			
		}	

		cont++;	
	}

return;
}

int main(){
	
	fastio;

	int n, m, a, b;

	cin >> n >> m;
	cin >> s;

	FI(m){
		cin >> a >> b;
		listAdj[a].pb(b);
		grau[b]++;
	}

	for(int i = 1; i <= n; i++)
		if(grau[i] == 0){
			fila.push(i);			
			memo[i][s[i-1] - 'a'] = 1;
		}

	topSort();

	if(cont != n){
		cout << "-1\n";
		return 0;
	}

	int res = -1;

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 27; j++)
			res = max(res, memo[i][j]);
	
/*	FOR(i, 1, n+1){
		cout << "node = " << i << endl;
		FOR(j, 0, 26)
			if(memo[i][j] != 0)printf("%c = %d\n", j + 'a', memo[i][j]);		
	}
*/
	cout << res << "\n";	
return 0;
}




