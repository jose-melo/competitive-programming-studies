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

int main(){

	int T, n;

	cin >> T;

	while(T--){

		cin >> n;

		vector<int> v;
		int aux, min = INF, cont = 0;
		FI(n){
			cin >> aux;
			v.pb(aux);
		}
		
		for(int i = v.size()-1; i >= 0; i--){
			if (v[i] <= min)
				min = v[i];
			else
				cont++;
		}
		
		cout << cont << "\n";
	}








}



