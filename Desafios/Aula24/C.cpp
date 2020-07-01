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

int memo[1123][2];
int n;
string s;


int pd(int i, int opt){


	if(i == 0)
		return 0;

	if(i == 1){
		if(s[i-1] - '0' == opt)
			return memo[i][opt] = 0;
		else
			return memo[i][opt] = 1;
	}

	if(memo[i][opt] != -1)
		return memo[i][opt];
	if(opt == 0){
		
		memo[i][opt] = pd(i-1, 1);
		if(s[i-1] == '1')
			memo[i][opt]++;
		
	}else{
	
		memo[i][opt] = pd(i-1, 0);

		if(s[i-1] == '0')
			memo[i][opt]++;
	}
return memo[i][opt];
}



int main(){

	cin >> n >> s;

	FOR(i, 1, n+1)
		memo[i][0] = memo[i][1] = -1;

	int resp = min(pd(n, 1), pd(n, 0));

	cout << resp << "\n";
return 0;
}







