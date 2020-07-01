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

int n, k;
string s;
int resp[27];

int main(){

	cin >> n >> k;

	cin >> s;

	int i = 0, cont;
	char ch;
	while(i < n){
		cont = 1;
		ch = s[i];
		while(s[i] == s[i+1] && cont != k){
			i++;
			cont++;
		}
			
		if(cont == k)
			resp[ch - 'a']++;

		i++;
	}

	int res = -1;

	FI(27)
		res = max(res, resp[i]);

	cout << res << "\n";
return 0;
}



