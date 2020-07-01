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

#define MOD 1000000007

ll T, n;



int main(){

	cin >> T;

	while(T--){

		cin >> n;

		if(n == 1 || n == 2){
			cout << "0\n";
			continue;
		}

		if(n==3||n==4){
			cout << "4\n";
			continue;
		}
		
		ll a = 3, b = 2;

		ll resp;

		for(int i = 5; i < n; i++){
			a = (a%MOD + b%MOD) % MOD;
			b = ((2%MOD)*(a%MOD)) % MOD;
		}
		a = a % MOD;
		resp = ((4%MOD)*(a%MOD)) % MOD;

		cout << resp << endl;

	}



}
