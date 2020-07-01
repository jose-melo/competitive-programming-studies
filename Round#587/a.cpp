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

	int a, b, c, d;

	cin >> a >> b >> c >> d;

	int soma = a+b+c+d;

	

	if(a+b == c+d || a + c == b+d || a + d == b+c || a+c+d == b || a+b+d == c || a+b+c == d || b+c+d == a){
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
	return 0;
}


