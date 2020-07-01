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

#define mx 1300000

int p[112345];
int ehprimos[mx];

void crivo(){

	for(int i = 4; i <= mx; i+=2)
		ehprimos[i] = 1;

	for(int i = 3; i <= mx; i+=2){
		if(ehprimos[i] == 0){
			for(int j = 2*i; j <= mx; j += i){
				ehprimos[j] = 1;
			}
		}
	}
	

	int cont = 0;
	for(int i = 2; i <= mx; i++){
		if(ehprimos[i] == 0){
			p[cont++] = i;	
		}
	}
}


int main(){

	int n;

	cin >> n;
	
	crivo();

	for(int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;


}
