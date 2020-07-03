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
ll n, val1, k, resp;


int main(){

	cin >> t;

	while(t--){
		
		cin >> n >> k;

		val1 = 1 + k + k*k + k*k*k;

		resp = n / val1;

		cout << resp << " " << k*resp << " " << k*k*resp << " " << k*k*k*resp << endl;

	}



}

