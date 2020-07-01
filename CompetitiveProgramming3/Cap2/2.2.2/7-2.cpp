#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){

	int N, n, k;
	int resp;


	cin >> N;

	while(N--){
		cin >> n >> k;


		int resp = 0;

		for(int i = 0; i < n; i++){
			resp ^= k;
			k >>= 1;
		}
		
		cout << resp << endl;
	
	}
return 0;
}

