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

	int t, a, b, c, d;
	string s;
	

	cin >> t >> a >> b >> c >> d;

	cin >> s;
	
	int cont = 0;
	for(int i = 0; i < s.size(); i++){

		if(a == c && b == d){
			cout << cont << endl;
			return 0;	
		}


		if(s[i] == 'E' && a < c){
			a++;
		}
		
		if(s[i] == 'W' && a > c){
			a--;
		}
	
		if(s[i] == 'N' && b < d){
			b++;
		}	

		if(s[i] == 'S' && b > d){
			b--;
		}

		cont++;

	}

	if(a == c && b == d){
		cout << cont << endl;
		return 0;
	}
	
	cout << "-1\n";


}
