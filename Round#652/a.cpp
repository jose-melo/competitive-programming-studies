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

ll T, n;

int main(){

	cin >> T;

	while(T--){
		cin >> n;

//		ll sum = (n-2)*45;

		
//		cout << "n " << n << "  "<< sum << endl;
		if(n % 4 == 0){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}



}
