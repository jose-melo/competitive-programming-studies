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

	int resp[4];

	resp[0] = 3;
	resp[1] = 2;
	resp[2] = 3;
	resp[3] = 2;

	fastio;

	int q, n;
	
	cin >> q;

	while(q--){

		cin >> n;

		if(n < 16){
			
			if(n == 4 || n == 6 || n == 9){
				cout << "1\n";
				continue;
			}
			
			if(n == 8 || n == 10){
				cout << "2\n";
				continue;
			}

			if(n >= 12){
				cout << resp[n - 12] << "\n";
				continue;
			}

			cout << "-1\n";
			continue;

		}			
	
		n -= 16;		

		cout << (n / 4) + resp[n%4] + 1 << "\n"; 
	
	}
return 0;
}



