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

int t;
int ehprimo[112345];
vector<int> primos;
ll n;

void crivo(){

	for(int i = 4; i <= 112345; i += 2)
		ehprimo[i] = 1;

	for(int i = 3; i <= 112345; i += 2){
		if(ehprimo[i] == 0){
			for(int j = i+i; j <= 112345; j += i)
				ehprimo[j] = 1;
		}
	}

	for(int i = 2; i <= 112345; i++)
		if(ehprimo[i] == 0)
			primos.pb(i);

}



int main(){


	crivo();

	cin >> t;

	while(t--){

		cin >> n;	

		ll a = n, b = n;
		bool ok = false;
		for(auto x : primos){
			if(n%x == 0){
				a = n/x;
				b = n - a;
				break;
			}
		}
		
		if(max(a, b) > n-1){
			cout << 1 << " " << n-1 << endl;
			continue;	
		}
		cout << a << " " <<  b << endl;

						
	}


}

