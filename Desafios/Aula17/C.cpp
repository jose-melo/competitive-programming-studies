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

	ll n, m;
	ll res;
	int a, b;

	cin >> n >> m;

	res = 0;
	
	FI(m){
		cin >> a >> b;
		res += n*a;
		
		if(b >= 0){
			res += ((n * (n-1))/2)*b;
		}else{
			res += b * ((((n-1)/2) + 1LL) * ((n-1)/2));
			if(n % 2 == 0)
				res += b * (n/2);
		}
	}

	printf("%.15lf\n", res*(1.0) / n);
return 0;
}


