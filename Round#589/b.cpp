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
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

#define MOD 1000000007

int matriz[1123][1123];
int deuC[1123], deuR[1123];
int C[1123], R[1123];
int cont, h, w;

ll fastxp(ll base, ll exp){

	if(exp == 0)
		return 1LL;


	ll R = fastxp(base, exp/2) % MOD;
	R = (R * R) % MOD;
	
	if (exp % 2 == 0)
		return R;
	else
		return ((base%MOD)*(R%MOD))%MOD;


}


int main(){

	cin >> h >> w;

	for(int i = 1; i <= h; i++)	
		cin >> R[i];

	for(int i = 1; i <= w; i++)
		cin >> C[i];

	int pintaCol, pintaRow, cont = 0;	
	for(int i = 1; i <= h; i++){
		for(int j = 1;  j <= w; j++){
			pintaCol = 0;
			pintaRow = 0;

			if(i <= C[j])
				pintaCol = 1;
			
			if(j <= R[i])
				pintaRow = 1;
			

			if(i == C[j] + 1){
				deuC[j] = 1;
				pintaCol = 2;
			}

			if(j == R[i] + 1){
				deuR[i] = 1;
				pintaRow = 2;
			}	

			if(pintaCol == 0 && pintaRow == 0 && deuC[j] == 1 && deuR[i] == 1){
				cont++;
				continue;
			}

			if(pintaCol*pintaRow == 2){
				cout << "0" << endl;
				return 0;
			}
		}
	}

	ll resp = fastxp(2, cont);

	cout << resp << endl;

	return 0;
}







