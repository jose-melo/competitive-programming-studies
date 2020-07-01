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

int T, n, k;
vector<ll> v, w;


int main(){

	cin >> T;

	while(T--){
		cin >> n >> k;

		int aux;
		v.clear();
		w.clear();
		for(int i = 0;  i < n; i++){
			cin >> aux;
			v.pb(aux);
		}
	
		for(int i = 0; i < k; i++){
			cin >> aux;
			w.pb(aux);
		}
	
		sort(v.begin(), v.end());
		sort(w.begin(), w.end());
		
		reverse(v.begin(), v.end());
/*
		for(auto x : v)
			cout << x << " ";
		cout << endl;

		for(auto x : w)
			cout << x << " " ;
		cout << endl;
*/	
		ll sum = 0;
		
		for(int i = 0; i < k; i++){
			sum += v[i];
			w[i]--;
			if(w[i] == 0){
				sum += v[i];
			}
		}

		reverse(w.begin(), w.end());

		int j = 0, i = n-1;
		while(i >= k){
			sum += v[i];
			i--;
			w[j]--;
			while(w[j] > 0){
				i--;
				w[j]--;
			}
			j = (j+1)%k;	
		}
		cout << sum << endl;	

	}



}
