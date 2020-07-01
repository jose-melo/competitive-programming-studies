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

int main(){

	fastio;
	int T, cont = 1;

	cin >> T;

	while(T--){
		int n, m;
		cin >> n >> m;
		
		string s1, s2;
		cin >> s1 >> s2;
		int dist = s2[0] - s1[0];	
		string s3;
		cin >> s3;
		cout << "Case #" << cont << ": ";
		cont++;
		dist *= -1;
		if (dist < 0) 
			dist = 26 + dist;
		for (int i = 0; i < s3.size(); i++){
			char c = (s3[i] - 'A' + dist);
			c %= 26;
			c = c + 'A';
			cout << c;
		}
		cout << endl;
	}
	return 0;
}
