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

int t, n, k;
string s;

int main(){

	cin >> t;

	while(t--){

		cin >> n >> k;
		cin >> s;

		int i=0, cont = 0;
		while(i < n){
			int ok = 1;
			for(int j = i-k; j <= i+k; j++){
				if(j >= n || j < 0)continue;
				if(s[j] == '1'){
					ok = 0;
					break;
				}
			}

			if(i >= n || i < 0)ok = 0;

			if(ok){
				cont++;
				s[i] = '1';
				
			}
			i++;

		}

		cout << cont << endl;


	}




}

