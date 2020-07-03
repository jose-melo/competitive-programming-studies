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
		vector<ll> a(n+1), b(n+1), chk(n+1);
		
		int aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			a[i] = aux;
		}

		for(int i = 0; i < n; i++){
			cin >> aux;
			b[i] = aux;
		}


		chk[0] = 0;
		for(int i = 0; i < n-1; i++){
			if(a[i] == 1){
				if(chk[i] == -1)
					chk[i+1] = 2;
				if(chk[i] == 1)
					chk[i+1] = 1;
				if(chk[i] == 0)
					chk[i+1] = 1;
			}
			if(a[i] == -1){
				if(chk[i] == -1)
					chk[i+1] = -1;
				if(chk[i] == 1)
					chk[i+1] = 2;
				if(chk[i] == 0)
					chk[i+1] = -1;
			}
			if(a[i] == 0){
				chk[i+1] = chk[i];
			}

		}


		int ok = 1;
		for(int i = n-1; i >= 0; i--){
			if(chk[i] == 2)continue;
			if(b[i] < a[i] && (chk[i] == 1 || chk[i] == 0)){
				cout << "NO\n";
				ok = 0;
				break;
			}	

			if(b[i] > a[i] && (chk[i] == -1 || chk[i] == 0)){
				cout << "NO\n";
				ok = 0;
				break;
			}
		}

		if(ok){
			cout << "YES\n";
		}	
	}

}

