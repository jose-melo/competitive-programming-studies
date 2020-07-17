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
ll x, y, z;

int main(){

	cin >> t;

	while(t--){
	
		cin >> x >> y >> z;

		if(x == y && x >= z){
			cout << "YES\n";
			cout << z << " " << z << " " << x << endl;
			continue;
		}

		if(y == z && y >= x){
			cout << "YES\n";
			cout << x << " " << x << " " << y << endl;
			continue;
		}

		if(x == z && x >= y){
			cout << "YES\n";
			cout << y << " " << y << " " << z << endl;
			continue;
		}

		cout << "NO\n";
	}



}

