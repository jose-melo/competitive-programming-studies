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
	int v[10];


	cin >> n;

	int sum = 0;
	for(int i = 0; i < 7; i++){
		cin >> v[i];
		sum += v[i];
	}


	
	sum = n % sum;


	if(sum == 0){
		for(int i = 6; i >= 0; i--){
			if(v[i] != 0){
				cout << i+1 << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < 7; i++){
		sum -= v[i];
		if(sum <= 0){
			cout << i+1 << endl;
			return 0;
		}
	}




}
