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
vector<int> input;
vector<int> sq (112345);

void geraBlocos(){

	int tam = sqrt(n) + 1;

	for(int i = 0; i < n; i++)
		sq[i] = INF;


	for(int i = 0; i < n; i++)
		sq[i/tam] = min(sq[i/tam], input[i]);
}

int query(int l, int r){


	int i = l;
	int tam = sqrt(n) + 1;	
	int resp = INF;
	
	while(i <= r){

		if(i % tam == 0 && i + tam - 1 <= r){
			resp = min(resp, sq[i/tam]);
			i += tam;	
		}else{
			resp = min(resp, input[i]);
			i++;

		}
	}	

return resp;
}

int main(){

	fastio;
		
	cin >> n;

	int aux, q;
	FI(n){
		cin >> aux;
		input.pb(aux);
	}
	
	geraBlocos();

	cin >> q;

	int a, b;
	FI(q){
		cin >> a >> b;
		
		cout << query(a, b) << "\n";
	
	}


}



