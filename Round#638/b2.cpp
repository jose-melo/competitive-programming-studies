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

int n, k;
int v[112];
int freq[112];


int main(){

	int T;
	cin >> T;

	while(T--){
		cin >> n >> k;
		
		memset(freq, 0, sizeof(freq));
	
		for(int i = 0; i < n; i++){
			cin >> v[i];
			freq[v[i]] = 1;
		}
	
		int cont = 0;
		for(int i = 1; i <= 100; i++)
			cont += freq[i];

		if(cont > k){
			cout << "-1\n";
			continue;
		}

		vector<int> resp;
		for(int i = 0; i < k; i++)
			resp.pb(v[i]);	
	
		int i = k, j = 0;
		while(i < n){
			if(v[j] == v[i])
				i++;
			resp.pb(v[j]);
			j = (j+1) % k;
		}
	
		cout << resp.size() << endl;
		for(auto x : resp)
			cout << x << " ";
		cout << endl;
	}

}
