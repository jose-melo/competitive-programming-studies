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

		int idx1 = 0, idx2, mx = -1;

		while(idx1 < n){
		
			idx2 = idx1+1;
			while(idx2 < n && v[idx2-1] <= v[idx2])idx2++;
			
			while(idx2 < n && v[idx2-1] >= v[idx2])idx2++;

			if(idx2 - idx1 > mx)
				mx = idx2 - idx1;
			
			if(idx2 != n)
				idx1 = idx2-1;
			else
				idx1 = idx2;
		}

		cout << n - mx << endl;


	
	}



}

