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
#define pb push_back


vector<int> gems;
int resp;
vector<int> val, c;

int main(){

	fastio;

	int n;
	cin >> n;

	int aux;
	for(int i = 0; i < n; i++){
		cin >> aux;
		val.pb(aux);
	}

	for(int i = 0; i < n; i++){
		cin >> aux;
		c.pb(aux);
	}


	int resp = 0;
	for(int i = 0; i < n; i++)
		if(val[i] - c[i] > 0)
			resp += (val[i] - c[i]);
	

	cout << resp << endl;
		
	
return 0;
}

