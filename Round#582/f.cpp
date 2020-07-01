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
#define tesxgfa cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int main(){


	int n;

	cin >> n;

	string s[12];
	
	s[0].append(n, 'a');
	s[0].append(n, 'b');
	s[0].append(n, 'c');
	
	FI(n)s[1].append("abc");		

	s[2].append(n, 'a');
	s[2].append(n, 'c');
	s[2].append(n, 'b');

	FI(n)s[3].append("acb");

	s[4].append(n, 'b');
	s[4].append(n, 'a');
	s[4].append(n, 'c');

	FI(n)s[5].append("bac");

	s[6].append(n, 'b');
	s[6].append(n, 'c');
	s[6].append(n, 'a');

	FI(n)s[7].append("bca");
	
	s[8].append(n, 'c');
	s[8].append(n, 'a');
	s[8].append(n, 'b');
	
	
	FI(n)s[9].append("cab");

	s[10].append(n, 'c');
	s[10].append(n, 'b');
	s[10].append(n, 'a');

	FI(n)
		s[11].append("cab");

	string r, t;

	cin >> r >> t;
	bool achei;
	for(int i = 0; i < 12; i++){
		achei = true;
		
		for(int j = 0; j < s[i].size()-1; j++)
			if((r[0] == s[i][j] && r[1] == s[i][j+1]) || (t[0] == s[i][j] && t[1] == s[i][j+1]))
				achei = false;

		if(achei){
			cout << "YES\n";
			cout << s[i] << "\n";
			return 0;
		}
	}

	cout << "NO\n";
return 0;

}



