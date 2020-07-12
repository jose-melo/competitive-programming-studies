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
ll n, x;

int main(){


	cin >> t;

	while(t--){

		cin >> n >> x;

		vector<ll> v;
		int aux;
		FI(n){
			cin >> aux;
			v.pb(aux);
		}
			
		sort(v.begin(), v.end());

		int cont = 0;
		ll mul = 1;
		for(int i = n-1; i >= 0; i--){
			if(v[i]*mul >= x){
				cont++;
				mul = 1;
			}else{
				mul++;
			}
		}

		cout << cont << endl;

		



	}


}

