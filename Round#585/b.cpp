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

ll input[212345];
ll mais[212345], menos[212345];
ll cmais, cmenos;
int n;

void pd(){
	
	if(input[0] < 0LL){
		mais[0] = 0;
		menos[0] = 1;
		cmenos++;
	}else{
		mais[0] = 1;
		menos[0] = 0;
		cmais++;
	}


	for(int i = 1; i < n; i++){

		if(input[i] < 0LL){
			mais[i] = menos[i-1];
			menos[i] = mais[i-1]+1;
			cmais += mais[i];
			cmenos += menos[i];
		}else{
			mais[i] = mais[i-1]+1;
			menos[i] = menos[i-1];
			cmais += mais[i];
			cmenos += menos[i];	
		}
	}
}



int main(){

	fastio;

	cin >> n;
	

	FI(n)
		cin >> input[i];

	pd();

	cout << cmenos << " " << cmais << endl;

return 0;
}







