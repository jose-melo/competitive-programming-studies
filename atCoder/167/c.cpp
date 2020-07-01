#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 1e8
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define mp make_pair


int target;
int n, m, k;
int v[15][15];
int algo[15];

int checa(int bitmask){

	int custo = 0;

	for(int i = 0; i <= m; i++)
		algo[i] = 0;

	for(int bit = 0; bit < n; bit++){
		if( (bitmask & (1<<bit)) != 0){
			for(int i = 1; i <= m; i++)
				algo[i] += v[bit][i];
		
			custo += v[bit][0];
		}
	}

	for(int i = 1; i <= m; i++)
		if(algo[i] < k)
			return INF;
	return custo;
}




int main(){

	
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
		for(int j = 0; j <= m; j++)
			cin >> v[i][j];


	int resp = INF;
	for(int bitmask = 0; bitmask < (1<<n); bitmask++){
		int val = checa(bitmask);
		if(val < resp)
			resp = val;

		
	}

	if(resp == INF){
		cout << "-1\n";
		return 0;
	}

	cout << resp << endl;

return 0;		
}
