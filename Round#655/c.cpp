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
	
		int idx1 = 0;
		while(idx1 < n && v[idx1] == idx1+1)idx1++;

		int idx2 = n-1;
		while(idx2 >= 0 && v[idx2] == idx2+1)idx2--;
	

		if(idx2 < idx1){
			cout << "0\n";
			continue;
		}
	
		int cont = 0;
		for(int i = idx1; i <= idx2; i++){
			if(v[i] != i+1)cont++;
		}

		if(cont == 0){
			cout << "0\n";
			continue;
		}

		if(cont == idx2-idx1+1){
			cout << "1\n";
			continue;
		}

		cout << "2\n";

	}
	


}

