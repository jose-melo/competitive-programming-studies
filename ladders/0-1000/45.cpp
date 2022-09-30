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

	int n, m;
	int a[60], b[60];

	cin >> n;


	for(int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;

	for(int i = 0; i < m; i++)
		cin >> b[i];

	int cont = 0, mx = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(b[j] % a[i] == 0){

				if(b[j]/a[i] > mx){
					mx = b[j]/a[i];
					cont = 1;
				}else{
					if(b[j]/a[i] == mx){
					cont++;
					}
				}
			}
		}
	}

	cout << cont << endl;


}
