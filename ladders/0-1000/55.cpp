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


void solve(int k, int p){

	if(k == 0){
		for(int i = 0; i < p; i++)
			cout << " ";
		cout << "0";
		cout << endl;
		return;
	}


	for(int i = 0; i < p; i++)
		cout << " ";
	
	cout << "0";
	for(int i = 1; i <= k; i++)
		cout <<  " " << i;

	for(int i = k-1; i >= 0; i--)
		cout << " " << i;

	cout << endl;
	
	
}


int main(){

	int n;
	
	cin >> n;


	for(int i = 0; i <= n; i++)
		solve(i, 2*(n-i));
	for(int i = n-1; i >=0; i--)
		solve(i, 2*(n-i));




}
