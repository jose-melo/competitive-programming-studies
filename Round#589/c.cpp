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

#define MOD 1000000007

set<ll> primos;
ll x, n;


void fat(ll n){  
    while (n % 2 == 0){  
        primos.insert(2); 
        n = n/2;  
    }   	
  	for (int i = 3; i <= sqrt(n); i+=2) {  
        while (n % i == 0){  
            primos.insert(i);  
            n = n/i;  
        }  
    }  
    if (n > 2)  
        primos.insert(n);  
}  



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


	cin >> x >> n;

	primos.clear();

	fat(x);	


	ll temp;
	ll resp = 1;
	ll exp = 1;
	ll mul;	

	for (auto x : primos){
		temp = n;
		exp = 1;	
		
		while(temp >= 1){
			mul = temp / x;
			if(mul == 0)break;

			resp = ((resp%MOD) * (fastxp(x, mul)%MOD))%MOD;
			temp /= x;
		}

	}


	cout << resp%MOD << endl;
return 0;	
}


