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

int n, m;
int p;


int main(){

	cin >> n >> m;
	
	char ch;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> ch;
			if(ch == '.'){
				if(p == 0)
					cout << "B";
				else
					cout << "W";
			}else{
				cout << ch;
			}
			p ^= 1;
		}
		if(m%2 == 0)
			p ^= 1;
		cout << "\n";
	}



}
