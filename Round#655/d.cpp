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

int n;

int main(){

	cin >> n;
	vector<ll> v;

	ll aux, sum = 0;
	FI(n){
		cin >> aux;
		v.pb(aux);
		sum += aux;
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < (n-1)/2; i++)
		sum -= v[i];
	

	cout << sum << endl;
	



}

