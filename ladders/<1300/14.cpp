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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int n;
vector<int> v;

int main(){

	cin >> n;

	int aux;
	for(int i = 0; i < n; i++){
		cin >> aux;
		v.pb(aux);
	}


	int cont = 0;
	int mn = INF, mx = -1;	

	for(auto x : v){
		if(x < mn)
			mn = x;
		if(x > mx)
			mx = x;
	}


	for(int i = n-1; i >= 0; i--){
		if(v[i] == mn){
			for(int j = i; j < n-1; j++){
				aux = v[j+1];				
				v[j+1] = v[j];
				v[j] = aux;
				cont++;
			}
			break;
		}
	}

	for(int i = 0; i < n; i++){
		if(v[i] == mx){
			for(int j = i; j > 0; j--){
				aux = v[j-1];
				v[j-1] = v[j];
				v[j] = aux;
				cont++;
			} 
			break;
		}
	}


	cout << cont << endl;

}

