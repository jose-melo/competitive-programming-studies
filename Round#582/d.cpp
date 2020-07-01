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


map<int, int> m;
vector<int> cont;
int main(){

	int k, n;

	cin >> n >> k;
	
	vector<int> v, input;

	int aux;
	FI(n){
		cin >> aux;
		input.pb(aux);
	}

	for(int i = 0; i < n; i++){
		aux = input[i];
		while(aux > 0){
			v.pb(aux);
			aux /= 2;
		}
	
	}



	int resp = INF;	
	for(int i = 0; i < v.size(); i++){

		cont.clear();
		for(int j = 0; j < n; j++){
			aux = input[j];
			int cont_aux = 0;
			while(aux > v[i]){
				aux /= 2;
				cont_aux++;
			}
			if(aux == v[i])
				cont.pb(cont_aux);
		}
		if(cont.size() >= k){
			sort(cont.begin(), cont.end());
			int sum = 0;
			for(int p = 0; p < k; p++)
				sum += cont[p];	
			resp = min(resp, sum);
		}

	}

	cout << resp << "\n";
return 0;
}




