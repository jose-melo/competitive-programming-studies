#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define MAX 32623

int t;
ll n, k;
vector<ll> primos;
int ehprimo[MAX];

void crivo(){

	memset(ehprimo, 0, sizeof(ehprimo));

	for(int i = 4; i < MAX; i+=2){
		ehprimo[i] = 1;
	}

	for(int i = 3; i < MAX; i++){
		if(ehprimo[i] == 0){
			for(int j = i+i; j < MAX; j += i)
				ehprimo[j] = 1;
		}
	}

	for(int i = 2; i < MAX; i++)
		if(ehprimo[i] == 0)
			primos.pb(i);
	
}




int main(){

	crivo();

	cin >> t;

	while(t--){
	
		cin >> n >> k;

		vector<ll> divisores;
		

		ll aux = n;

		while(n%2 == 0){
			n/=2;
			divisores.pb(2);
		}

		for(int i = 3; i*i < n; i += 2){
			while(n%i == 0){	
				n/=i;
				divisores.pb(i);
			}
		}

		if(n > 2)divisores.pb(n);
		/*
		for(auto x : divisores)
			cout << x << " ";
		cout << endl;*/


		ll resp = 1, ax = 1, ant = 1;
		int idx = divisores.size()-1;
		while(divisores[idx] > k)idx--;
		while(idx >= 0 && ax <= k){
			ant = ax;
			ax *= divisores[idx];
			idx--;
		}

		if(idx < 0 && ax <= k)ant = ax;

		cout << aux/ant << endl;
		


	}

}

