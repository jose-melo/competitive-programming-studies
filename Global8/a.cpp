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
ll k1, k2, a, b, n, k3, k4;


int main(){

	cin >> T;

	while(T--){
		cin >> a >> b >> n;

		k1 = (n-a + b-1)/b;
		k2 = (n-b + a-1)/a;
		k3 = (n-a + a-1)/a;
		k4 = (n-b + b-1)/b;
		
		cout << k1 << " " << k2 << " " << k3 << " " << k4 << endl;

		if(b*k1 + a == n)
			k1++;

		if(a*k2 + b == n)
			k2++;

		cout << min(k1, k2) << endl;
	}	




}
