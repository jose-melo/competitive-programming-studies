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

	string resp, s1, s2;

	cin >> s1;
	cin >> s2;

	for(int i = 0; i < s1.size(); i++){

		int val = (int)(s1[i] - '0') ^ (int)(s2[i] - '0');
		
		if(val == 0)
			resp.append("0");
		else
			resp.append("1");

	}
	cout << resp << endl;



}

