#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int t, n, m;

int main(){

	cin >> t;
	
	while(t--){

		char dif = 'W';

		cin >> n >> m;
	
		if(m%2 == 0)
			dif = 'B';

		if(m%2 == 1 && n%2 == 0)
			dif = 'B';

		int p = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i == 0 && j == 1){
					cout << dif;
				}else{
					if(p)
						cout << 'W';
					else
						cout << 'B';
				}
				p ^= 1;
			}
			cout << endl;		
		}
	


	}



}

