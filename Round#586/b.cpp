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
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int mdc(int a, int b){
	if(b == 0)return a;

	return mdc(b, a%b);
}

int main(){

	int n;

	cin >> n;

	vector<int> v;
	int m[1123][1123];
		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> m[i][j];
		}

	}

	int i = 0, d, k1, k2, x, a1, a2, a3;
	d = mdc(m[i][i+1], m[i][i+2]);
	k1 = m[i][i+1]/d;
	k2 = m[i][i+2]/d;
	x = m[i+1][i+2]/(k1*k2);
	x = sqrt(x);
	a1 = d/x;
	a2 = k1*x;
	a3 = k2*x;
	
	v.pb(a1);
	v.pb(a2);
	v.pb(a3);
	
	i = 1;
	for(int j = 3; j < n; j++){
		v.pb(m[i][j]/a2);	
	}	

	for(auto k : v)	
		cout << k << " ";
	cout << endl;
return 0;

}


