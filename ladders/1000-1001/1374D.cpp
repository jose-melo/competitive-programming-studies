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

unordered_map<int, int> m;
int t, n, k;

int main(){

	cin >> t;

	while(t--){
		cin >> n >> k;

		vector<int> v;

		int aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			v.pb((k - (aux%k)) % k);
		}
		
		sort(v.begin(), v.end());

		ll resp = 0;
		
		int i = 0, j, cont;
		while(i < n){
			if(v[i] == 0){
				i++;
				continue;
			}
			j = i;
		    cont = 0;
			while(j < n && v[j] == v[i]){
				cont++;
				j++;
			}
			resp += v[i] + (cont - 1)*k + 1;
			i = j;
		}

		cout << resp << endl;


	}



}

