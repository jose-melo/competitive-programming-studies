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

int n;
int v[112];


int main(){

	fastio;

	cin >> n;
	
	FI(n)
		cin >> v[i];
	int segundo = 0;
	ll cont = 0;
	ll res = 1;	
	int ok = 0;
	FI(n){
		if(v[i] == 1){
			
			if(segundo){
				cont++;
				res *= cont;
				cont = 0;
				ok = 1;	
			}else{
				segundo = 1;
			}
		}else{
			if(segundo)cont++;
		}
	}

	if(!ok)
		if(segundo)
			res = 1;
		else
			res = 0;
	cout << res << "\n";
return 0;
}
