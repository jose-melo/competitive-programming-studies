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

int t, n, k;

int main(){

	cin >> t;

	while(t--){

		cin >> n >> k;

	
		if(n%2 != k%2){
			cout << "NO\n";
			continue;
		}

		if(n < k*k){
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
	
	}



}

