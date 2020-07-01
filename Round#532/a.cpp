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


int main(){

	int n, k;
	int v[110], mark[110];

	cin >> n >> k;

	FI(n)
		cin >> v[i+1];

	int contE, contS, mx = -1;
	for(int i = 1; i <= k; i++){
		
		contE = contS = 0;
		for(int j = 1; j <= n; j++)mark[j] = 0;

		for(int b = i; b <= n; b += k)
			mark[b] = 1;

		for(int j = 1; j <= n; j++){		
			if(mark[j] == 1)continue;
			if(v[j] == 1)
				contE++;
			else
				contS++;
		}
		
		if(abs(contE - contS) > mx)
			mx = abs(contE - contS);
	}

	cout << mx << "\n";
return 0;
}



