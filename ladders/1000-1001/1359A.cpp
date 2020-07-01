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

int t, n, m, k;

int main(){

	cin >> t;

	while(t--){

		cin >> n >> m >> k;

		int mx = min(m, n/k);
		
		if(m <= n/k){
			cout << m << endl;
		}else{
			m -= mx;
			cout <<mx - (m + (k-2))/(k-1) << endl;
		}

		

	}	
	


}

