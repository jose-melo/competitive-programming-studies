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

int t, n;

int main(){
	
	cin >> t;

	while(t--){

		cin >> n;

		vector<int> a(n+1), b(n+1);

		FI(n)
			cin >> a[i];

		FI(n)
			cin >> b[i];

		int idx1 = n+1, idx_1 = n+1;
		for(int i = 0; i < n; i++){
			if(idx1 == n+1 && a[i] == 1)
				idx1 = i;
			if(idx_1 == n+1 && a[i] == -1)
				idx_1 = i;
		}

		int ok = 1;
		for(int i = n-1; i >= 0; i--){
			if(b[i] > a[i]){
				if(idx1 >= i){
					cout << "NO\n";	
					ok = 0;
					break;
				}
			}
			if(b[i] < a[i]){
				if(idx_1 >= i){
					cout << "NO\n";
					ok = 0;
					break;
				}
			}
		}

		if(ok)
			cout << "YES\n";



	}




}

