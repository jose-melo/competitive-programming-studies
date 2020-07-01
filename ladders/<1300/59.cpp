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

int n, m;
vector<int> v1, v2;


int main(){

	cin >> n >> m;
	int aux;
	
	FI(m){
		cin >> aux;
		v1.pb(aux);
		v2.pb(aux);
	}
	
	int a = 0, b = 0,idx = 0, mn = 1123, mx = -1;
	for(int i = 0; i < n; i++){

		mx = -1;
		for(int j = 0; j < m; j++){
			if(v1[j] > mx){
				mx = v1[j];
				idx = j;
			}
		}
		a += mx;
		v1[idx]--;
	}	
	
	for(int i = 0; i < n; i++){
		
		mn = 1123;
		for(int j = 0; j < m; j++){
			if(v2[j] < mn && v2[j] > 0){
				mn = v2[j];
				idx = j;
			}
		}
		b += mn;
		v2[idx]--;
	}	

	cout << a << " " << b << endl;


}
