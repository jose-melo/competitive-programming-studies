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
ll x;
vector<int> v;
int main(){

	cin >> t;

	while(t--){
		cin >> n >> x;

		v.clear();
		int aux;
		FI(n){
			cin >> aux;
			v.pb(aux);
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		
		ll val = x,sum = v[0];
		int idx = 0;
		while(sum >= val && idx < n){
			idx++;
			sum += v[idx];
			val = x*(idx+1);
		}
	
		cout << idx << endl;

	}



}

