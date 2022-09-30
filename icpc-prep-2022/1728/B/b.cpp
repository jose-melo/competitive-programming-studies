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

		if(n == 4){
			cout << "2 1 3 4" << endl;
			continue;
		}

		for(int i = 4; i <= n-2; i++){
			cout << i << " ";
		}
		cout << "1 3 2 " << n-1 << " " << n << endl; 
	}
}

