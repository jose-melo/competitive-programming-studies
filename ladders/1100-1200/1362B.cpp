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
int mark[11230];

int main(){

	cin >> t;

	while(t--){

		cin >> n;
		vector<int> v;
		int aux;

		memset(mark, 0, sizeof(mark));		
	
		FI(n){
			cin >> aux;
			v.pb(aux);
			mark[aux] = 1;
		}
	
		int resp, bit, ok = 0;
		for(bit = 1; bit <= 1024 && !ok; bit++){
			ok = 1;
			for(int i = 0; i < n; i++){
				if(mark[v[i]^bit] == 0)
					ok = 0;
			}
			if(ok)
				resp = bit;
		}
		
		if(!ok)
			cout << "-1\n";
		else
			cout << resp << endl;

		

	}



}

