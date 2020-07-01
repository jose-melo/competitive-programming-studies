#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int T;
ll a, b, n;


int main(){

	cin >> T;

	while(T--){
		cin >> a >> b >> n;

		ll cont1 = 0, cont2 = 0, cont3 = 0;	
		ll e = a, d = b;
	
	
		ll c = min(a, b);
		a = max(a, b);
		b = c;

		int p = 1;
		while(max(a, b) <= n){
			cont1++;
			if(p)
				b += a;
			else
				a += b;

			p ^= 1;
		}
		
		a = e;
		b = d;

		ll k1 = (n-a + b-1)/ b;
		ll k2 = (n-b + a-1)/a;

		ll resp = min(cont1, k1);
		resp = min(resp, k2);

		cout << cont1 << endl;

	}



}
