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

int gcd(int a, int b){
	if(a%b == 0)
		return b;

	return gcd(b, a%b);
}


int main(){
	
	int n, aux;

	vector<int> v, l, r;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> aux;
		v.pb(aux);
	}

	aux = v[0];
	l.pb(0);
	l.pb(aux);
	for(int i = 1; i < n; i++){
		l.pb(gcd(aux, v[i]));
		aux = gcd(aux, v[i]);
	}

	aux = v[n-1];
	r.pb(0);
	r.pb(aux);
	for(int i = n-2; i >= 0; i--){
		r.pb(gcd(aux, v[i]));
		aux = gcd(aux, v[i]);
	}
	r.pb(0);
	reverse(r.begin(), r.end());

	
	l[0] = r[1];
	r[n+1] = l[n];
	
	int mx = -1;
	for(int i = 2; i < n; i++){	
		if(gcd(l[i-1], r[i+1]) > mx)
			mx = gcd(l[i-1], r[i+1]);
	}
	
	mx = max(mx, r[2]);
	mx = max(mx, l[n-1]);
	mx = max(mx, l[0]);

	cout <<  mx << endl;

return 0;
}




