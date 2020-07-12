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

int n, t;

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
	
		int idx3 = 0, idx1=0, idx2 = n-1, ok = 0;

		for(int i = n-1; i >= 0; i--){
			
			if(i+1 == v[idx1]){
				idx1++;
			}else{
				if(i+1 == v[idx2]){
					idx2--;
				}else{


					for(int j = 0; j < n; j++){
						if(v[j] == i+1){
							idx3 = j;
							break;
						}
					}
					ok = 1;
					break;
				}
			}
		}

		if(ok){
			cout << "YES\n";
			cout << idx1+1 << " " << idx3+1 << " " << idx2+1 << endl;

		}else
			cout << "NO\n";	


	}
	


}

