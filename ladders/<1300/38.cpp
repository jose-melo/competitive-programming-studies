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
	int v[112345];
	
	cin >> n;

	FI(n)
		cin >> v[i];

	int mn = 1e9 + 1; 
	int rep = 0, resp;
	for(int i =0; i < n; i++){
		if(v[i] <= mn){
			resp = i;
			if(v[i] == mn)
				rep = 1;
			else
				rep = 0;
			mn = v[i];
		}
	}

	if(rep){
		cout << "Still Rozdil\n";
		return 0;
	}

	cout << resp + 1<< endl;



}
