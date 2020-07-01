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

	int n, a = 0, m, b = 0;
	vector<int> v;
	
	cin >> n;

	int aux;
	FI(n){
		cin >> aux;
		v.pb(aux);
	}

	cin >> m;

	FI(m){
	
		cin >> aux;

		for(int i = 0; i < n; i++){
			if(v[i] == aux){
				a++;
				break;
			}else{
				a++;
			}
		}
		for(int i = n-1; i >= 0; i--){
			if(v[i] == aux){
				b++;
				break;
			}else{
				b++;
			}
		}
	}

	cout << a << " " << b << endl;


}
