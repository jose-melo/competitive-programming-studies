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
vector<int> v;


int main(){

	cin >> t;

	while(t--){

		cin >> n;
		v.clear();
		v.pb(0);
	

		int aux;
		FI(n){
			cin >> aux;
			v.pb(aux);
		}

		sort(v.begin(), v.end());
		for(int i = v.size()-1; i >= 0; i--){
			if(v[i] <= i){
				cout << i+1 << endl;
				break;
			}
		}		
	}



}

