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

	int k;
	vector<int> v;
	cin >> k;

	int aux;
	for(int i = 0; i < 12; i++){
		cin >> aux;
		v.pb(aux);
	}
	
	sort(v.begin(), v.end(), greater<int>());


	int sum = 0, cont = 0;
	for(int i = 0; i < 12; i++){
		if(sum >= k){
			cout << cont << endl;
			return 0;
		}
		cont++;
		sum += v[i];
	}

	if(sum >= k){
		cout << cont << endl;
		return 0;
	}

	cout << "-1\n" << endl;
}
