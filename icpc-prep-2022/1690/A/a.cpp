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

int main(){

	int t, n;

	cin >> t;

	while(t--){
	
		cin >> n;
		n -= 6;
		int tmp = n % 3;

		cout << 2 + n/3 + (tmp == 2 ? 1 : 0) << " " << 3 + n/3 + (tmp >= 1 ? 1 : 0) << " " << 1 + n/3 << endl;
			
	}



}

