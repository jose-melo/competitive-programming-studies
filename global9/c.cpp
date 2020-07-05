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

		vector<int> v;

		int aux;
		FI(n){
			cin >> aux;
			v.pb(aux);
		}

		if(v[0] < v[n-1])
			cout << "YES\n";
		else
			cout << "NO\n";	


	}




}

