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
vector<int> v;

int main(){

	cin >> n;
	
	ll aux;
	FI(n){
		cin >> aux;
		v.pb(aux);
	}

	ll total = 0;
	int impar = false;
	int contZero = 0;
	for(int i = 0; i < n; i++){
		if(v[i] < 0)impar = !impar;
		if(v[i] == 0){
			total += 1;
			contZero++;
			continue;
		}
		
		total += abs(v[i]) - 1;
	}

	

	if(contZero == 0 && impar)
		total += 2;

	cout << total << endl;
return 0;
}



