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

vector <ll> ans;

int main (){
	ll a, b;

	cin >> a >> b;

	if(a%b != 0)
		return 0;

	ll num = a/b;
	ll raiz = sqrt(num);
	for(int i = 1; i <= raiz ; i++){
		if(num % i == 0){
			ans.pb(b*i);
			if(num / i != i)
				ans.pb(b*(num/i));
		}
	}
	sort(ans.begin(), ans.end());	

	for(auto it : ans)
		cout << it << " ";
	cout << endl;
	
	return 0;
}
