#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back


int main(){

	ll a, b, c, k;

	cin >> a >> b >> c >> k;


	if(k < a){
		cout << k << endl;
		return 0;
	}

	k -= a;

	k -= b;

	if(k < 0){
		cout << a << endl;
		return 0;
	}
	

	cout << a - k << endl;

return 0;

}
