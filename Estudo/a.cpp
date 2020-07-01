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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int main(){


	int t, n, aux, cont1, cont0;

	bool ok;
	vector<int> v;
	set<int> s;


	cin >> t;

	while(t--){
	
		v.clear();

		cin >> n; 
		
		FI(n){
			cin >> aux;
			v.pb(aux);
			s.insert(aux);
		}

		ok = false;
		for(int bit = 0; bit < 11; bit++){
	
			cont1 = cont0 = 0;

			for(auto x : v){
				if((x & (1<<bit)) != 0)	
					cont1++;
				else
					cont0++;
			}

			if(cont1 == cont0){
				
				ok = true;
				for(auto x : v){
					if(s.find(x^(1<<bit)) == s.end())
						ok = false;
				}

				if(ok){
					aux = (1<<bit);
					cout << aux << endl;
					break;
				}
			}		
		}


		if(!ok)
			cout << "-1" << endl;

	}

return 0;
}

