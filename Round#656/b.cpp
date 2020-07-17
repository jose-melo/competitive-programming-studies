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
int n;

int main(){

	cin >> t;

	while(t--){
		
		cin >> n;
		vector<int> v;
		int mark[n+10];
		memset(mark, 0, sizeof(mark));

		int aux;
		FI(2*n){
			cin >> aux;
			v.pb(aux);
		}

		vector<int> resp;
		for(int i = 0; i < 2*n; i++){
			if(mark[v[i]] == 0){
				resp.pb(v[i]);
				mark[v[i]] = 1;
			}
		}
		
		for(auto x : resp)
			cout << x << " ";
		cout << endl;
	
	
	}


}

