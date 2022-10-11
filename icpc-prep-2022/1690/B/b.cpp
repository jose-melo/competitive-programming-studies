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

int main(){

	int t, n, tmp;
	vector<int> v1, v2;
	fastio;
	cin >> t;

	while(t--){
	
		cin >> n;

		FI(n){
			cin >> tmp;
			v1.pb(tmp);
		}

		int max2 = -1;
		FI(n){
			cin >> tmp;
			v2.pb(tmp);
			if(tmp != 0){
				max2 = max(v1[i]-tmp,max2);	
			}
		}
		bool ok = false;
		for(int i = 0; i < v1.size() && max2 != -1; i++){
			int x = v2[i];
			if(x == 0 && v1[i] > max2){
				cout << "NO" << endl;
				ok = true;
				v1.clear();
				v2.clear();
				break;
			}
		}
		
		if(ok)continue;
		
		vector<int> aux;
		for(int i = 0; i < v1.size(); i++){
			if(v2[i] != 0){
				aux.pb(v1[i] - v2[i]);
			}
		}

		for(auto x: aux){
			if(x < 0){
				cout << "NO\n";
				ok = true;
				v1.clear();
				v2.clear();
				aux.clear();
				break;
			}
		}
		if(ok)continue;

		for(int i = 1; i < aux.size(); i++){
			if(aux[i-1] != aux[i]){
				cout << "NO" << endl;
				ok = true;
				v1.clear();
				v2.clear();
				aux.clear();
				break;
			}
		}

		if(!ok){
			cout << "YES\n";
		}
		v1.clear();
		v2.clear();
		aux.clear();
	}


}

