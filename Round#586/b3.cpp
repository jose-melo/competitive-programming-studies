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

	int n;
	int m[1123][1123];
	vector<int> resp;

	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> m[i][j];


	int a1 = sqrt((m[0][1]*1LL*m[0][2]*1LL) / m[1][2]*1LL);
	resp.pb(a1);
	for(int i = 1; i < n; i++)
		resp.pb(m[0][i]/a1);

	for(auto x : resp)
		cout << x << " ";
	cout << endl;

	return 0;

}


