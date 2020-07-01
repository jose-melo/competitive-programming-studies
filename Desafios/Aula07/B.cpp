#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n, k;

vector<ll> v;
ll somaAtual;

int main(){
	
	int cont = 0;

	cin >> n >> k;

	ll a;
	for(int i = 0; i < n; i++){
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	somaAtual = 0;
	for(int i = 0; i < v.size() && cont < k; i++){
		if(v[i] - somaAtual != 0){
			cout << v[i] - somaAtual << "\n"; 
			cont++;
		}
		somaAtual += v[i] - somaAtual; 
	}

	while(cont < k){
		cout << "0\n";
		cont++;	
	}

return 0;
}






