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

int n, a, b;

int main(){

	int x, y = 0;
	bool ok = false;

	cin >> n >> a >> b;

	while(n - y*b >= 0){
		if(ceil(((n - y*b)*1.0) / a) == floor(((n - y*b)*1.0) / a)){
			x = ((n - y*b)) / a;
			ok = true;
			break;
		}
		y++;
	}

	if(!ok){
		cout << "NO\n";
		return 0;
	}


	cout << "YES\n";
	cout << x << " " << y << "\n";
return 0;
}



