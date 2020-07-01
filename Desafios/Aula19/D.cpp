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

map<int, int> freq;
int memo[1123456], input[112345], pode[1123456];
int n, A;

int main(){

	fastio;

	cin >> n >> A;
	
	FOR(i, 1, n+1)
		cin >> input[i];	

	FOR(i, 1, 1000001){
		memo[i] = 0;	
		pode[i] = 1;
	}	

	pode[A] = 0;
	
	FOR(i, 1, n+1){
		if(input[i] == A){
			memo[A]++;
			continue;	
		}		

		if(memo[input[i]] < memo[A])
			pode[input[i]] = 0;
		
		memo[input[i]]++;
	}
	
	FOR(i, 1, 1000001){
		if(pode[i] && memo[i] >= memo[A]){
			cout << i << "\n";
			return 0;
		}
	}

	cout << "-1\n";
	
return 0;
}





