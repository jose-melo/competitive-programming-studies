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

vector<ll> input;
set<ll> v;

int main(){

	fastio;

	int n;

	cin >> n;

	ll x, somaTotal = 0;
	ll aux;
	FI(n){
		cin >> aux;
		input.pb(aux);
		somaTotal += input[i];
	}
	
	if(somaTotal % 2){
		cout << "NO\n";
		return 0;
	}

	x = somaTotal / 2;

	int p = 0;



	ll somaAtual = 0;
	while(somaAtual < x){
		somaAtual += input[p];
		v.insert(input[p]);
		p++;
	}
	if(somaAtual == x){
		cout << "YES\n";
		return 0;
	}

	int l, r, mid;
	ll val;

	for(int i = p; i < n; i++){
		
		val = somaAtual - x;
		if(v.find(val) != v.end()){

			cout << "YES\n";
			return 0;
		}
		somaAtual += input[i];
		v.insert(input[i]);
	}	
		
	val = somaAtual - x;
	if(v.find(val) != v.end()){
		cout << "YES\n";
		return 0;
	}
	
	p = 0;
	v.clear();
	reverse(input.begin(), input.end());

	somaAtual = 0;
	while(somaAtual < x){
		somaAtual += input[p];
		v.insert(input[p]);
		p++;
	}

	for(int i = p; i < n; i++){
		
		val = somaAtual - x;		

		if(v.find(val) != v.end()){
			cout << "YES\n";
			return 0;
		}
		somaAtual += input[i];
		v.insert(input[i]);
	}

	val = somaAtual - x;	
	if(v.find(val) != v.end()){
		cout << "YES\n";
		return 0;
	}


	cout << "NO\n";
return 0;
}




