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

int t, n, aux;
vector<int> v;
unordered_map<int, int> freq;


int main(){

	cin >> t;

	while(t--){

		cin >> n;
		v.clear();
		freq.clear();
		FI(n){
			cin >> aux;
			v.pb(aux);
		}

		for(int i = 0; i < n; i++)
			freq[v[i]]++;		
	
		int cont = 0, mx = -1;

		for(auto x : freq){
			if(x.se != 0){
				cont++;
				if(x.se > mx)
					mx = x.se;
			}
		}

		if(mx > cont){
			cout << cont << endl;
			continue;
		}	

		if(mx < cont){
			cout << mx << endl;
			continue;
		}

		cout << mx-1 << endl;


	}


}

