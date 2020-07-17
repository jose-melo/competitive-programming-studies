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

		int idx1, idx2;

		for(idx1 = n-1; idx1 > 0; idx1--)
			if(v[idx1-1] < v[idx1])break;


		for(idx2 = idx1; idx2 > 0; idx2--)
			if(v[idx2-1] > v[idx2])break;
		
		cout << idx2 << endl;

	}



}

