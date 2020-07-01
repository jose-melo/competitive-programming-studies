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

	int T;
	bool v[13];
	cin >> T;

	while(T--){
		int n;
		cin >> n;
		for (int i = 0; i < 13; i++) 
			v[i] = false;
		for (int i = 0; i < n-1; i++){
			int aux;
			cin >> aux;
			v[aux] = true;
		}
		for (int i = 1; i <= n; i++){
			if (!v[i]){
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}
