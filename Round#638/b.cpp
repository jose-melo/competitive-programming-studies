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
vector<int> v;


int main(){

	cin >> T;

	while(T--){
		cin >> n >> k;

		int aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			v.pb(aux);
		}
	
		ll sum = 0, mx,mn;

		for(int i = 0; i < k; i++)
			sum += v[i];

		mn = mx = sum;
		for(int i = k; i < n; i++){
			sum -= v[i-k];
			sum += v[i];
			
			if(sum > mx)
				mx = sum;

			if(sum < mn)
				mn = sum;	

		}




}
