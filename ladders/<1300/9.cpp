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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int main(){

	ll n;


	cin >> n;

	int cont = 0;
	while(n > 0){
		if(n % 10 == 4 || n % 10 == 7)
			cont++;
		n /= 10;
	}

	if(cont == 0){
		cout << "NO" << endl;
		return 0;

	}

	while(cont > 0){
		if(cont%10 == 4 || cont%10 == 7)
			cont /= 10;
		else{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n" << endl;
	
return 0;
}
