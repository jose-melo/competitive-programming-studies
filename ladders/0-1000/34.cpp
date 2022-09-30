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

	int n;
	vector<int> v;
	cin >> n;
	int aux;
	for(int i = 0; i < n; i++){
		cin >> aux;
		v.pb(aux);
	}
	int mn = 1001, a, b;
	for(int i = 0; i < n; i++){
		if(abs(v[(i+1)%n] - v[i]) < mn){
			mn = abs(v[(i+1)%n] - v[i]);
			a = ((i+1)%n) + 1;
			b = i + 1;
		}
	}


	cout << a << " " << b << endl;
	



}
