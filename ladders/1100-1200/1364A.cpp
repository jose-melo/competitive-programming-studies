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

int t, n, x;

int main(){
	

	cin >> t;

	while(t--){

		cin >> n >> x;
		vector<int> v;

		ll sum = 0;
		int aux;
		FI(n){
			cin >> aux;
			v.pb(aux);
			sum += aux;
		}

		if(sum % x){
			cout << n << endl;
			continue;
		}		

		int idx1, idx2;
		for(idx1 = 0; idx1 < n; idx1++)
			if(v[idx1] % x)break;
		
		for(idx2 = n-1; idx2 >= 0; idx2--)
			if(v[idx2]%x)break;

		if(idx1 == n || idx2 < 0){
			cout << "-1\n";
			continue;
		}


		cout << n-min(idx1+1, n-idx2) << endl;
	
	}



}

