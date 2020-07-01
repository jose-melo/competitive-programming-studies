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

	ll a, b, c;

	cin >> a >> b >> c;
	bool ok = false;
	int resp = 1;
	
	for(resp = 1; resp <= b; resp++){
		a *= 10;
		if(a / b == c){
			ok = true;
			break;
		}		

		a = a % b;

	}
	
	
	if(!ok){
		cout << "-1\n";
		return 0;
	}

	cout << resp << "\n";
return 0;
}

