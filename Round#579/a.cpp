#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int main(){

	int q, n;

	cin >> q;

	while(q--){

		vector<int> v;
		cin >> n;
	
		int aux;
		FI(n){
			cin >> aux;
			v.pb(aux);
		}

		int idx;		
		for(int i = 0; i < n; i++)
			if(v[i] == 1){
				idx = i;
				break;	
			}
		n++;

		bool ok = true;
		if (v[(idx + 1) % (n-1)] == (v[idx] + 1) % n){
			idx = (idx + 1) % (n-1);
			for(int i = 0; i < n-3; i++){
				if(v[(idx + 1) % (n-1)] !=  (v[idx] + 1) % n){
					ok = false;
					break;
				}
				idx = (idx + 1)%(n-1);
			}
		}else if(v[idx] == (v[(idx + 1) % (n-1)] + 1) % n){
			idx = (idx + 1) % (n-1);
			for(int i = 1; i < n-1; i++){
				if(v[idx] != (v[(idx + 1) % (n-1)] + 1) % n){
					ok = false;
					break;
				}
				idx = (idx + 1)%(n-1);
			}	
		}else{
			ok = false;
		}
		
		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";	


	}


}



