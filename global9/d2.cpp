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

		vector<int> v, mark(n+2), resp;
		
		int aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			v.pb(aux);
		}

		bool ok = true;
		for(int i = 1; i < n; i++){
			if(v[i-1] > v[i]){
				ok = false;
			}
		}
		
		int mex;
		
		while(!ok){
			
			
			for(int i = 0; i <= n; i++)
				mark[i] = 0;
		
			for(int i = 0; i < n; i++)
				mark[v[i]] = 1;
		
			for(int i = 0; i <= n; i++){
				if(mark[i] == 0){
					mex = i;
					break;
				}
			}

			if(mex == n){
				for(int i = 0; i < n; i++){
					if(v[i] != i){
						mex = i;
						break;
					}
				}
				resp.pb(mex+1);
				v[mex] = n;
			}else{
				resp.pb(mex+1);
				v[mex] = mex;
			}	

			ok = true;
			for(int i = 1; i < n; i++){
				if(v[i-1] > v[i]){
					ok = false;
				}
			}
		}	
	
	
		cout << resp.size() << endl;
		for(auto x : resp)
			cout << x << " ";
		cout << endl;
		
	}

}

