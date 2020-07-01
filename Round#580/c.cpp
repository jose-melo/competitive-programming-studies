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

int n;
vector<int> resp;

int main(){

	cin >> n;

	if( ((2*1LL*n)*((2*1LL*n)+1)/2) % 2 == 0){
		cout << "NO\n";
		return 0;	
	}
	
	int p = 1, q = 2*n;
	int i = 0;
	while(i < n-1){
		resp.pb(p);
		resp.pb(q);
		p += 2;
		q -= 2;
		i += 2;
	}
	resp.pb(p);


	int soma = true;
	for(int i = 0; i < n; i++){
		if (soma){
			resp.pb(resp[i] + 1);			
		}else{
			resp.pb(resp[i] - 1);
		}
		soma = !soma;
	}

	cout << "YES\n";
	for(auto x : resp)
		cout << x << " ";
	cout << "\n";

return 0;
}





