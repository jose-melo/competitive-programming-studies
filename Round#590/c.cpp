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


int q, n;
int memo[212345][2];
string s0, s1;


void pd(int k){

	if(k == 0){
		
		if(s0[0] == '1' || s0[0] == '2')
			memo[0][0] = 1;
		else
			memo[0][0] = 0;		

		if(s0[0] > '2' && s1[0] > '2')
			memo[0][1] = 1;
		else
			memo[0][1] = 0;

		return;
	}

	pd(k-1);

	if(s0[k-1] == '1' || s0[k-1] == '2')
		if(memo[k-1][0] == 1)
			memo[k][0] = 1;
		else
			memo[k][0] = 0;		
	
	if(s0[k-1] > '2' && s1[k-1] > '2')
		if(memo[k-1][1] == 1)
			memo[k][1] = 1;
		else
			memo[k][1] = 0;

return;
}


int main(){


	cin >> q;

	while(q--){

		cin >> n;

		for(int i = 0; i <= n; i++)
			memo[i][0] = memo[i][1] = -1;

		getline(cin, s0);
		getline(cin, s1);
		
		cout << s0 << s1 << endl;	
		
		pd(n-1);

		if(memo[n-1][1] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

return 0;
}


