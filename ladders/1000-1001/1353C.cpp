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

int t;
ll n, resp;

int main(){

	cin >> t;

	while(t--){
		cin >> n;

		resp = 0;
		ll cont = 1;
		for(ll i = 3; i <= n; i+=2){
			resp += cont*(i*i - (i-2)*(i-2));
			cont++;
		}
		
		cout << resp << endl;	


	}



}

