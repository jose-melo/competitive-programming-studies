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
int v[1123];


void f(int p){

	if(p == 1){
		return; 
	}
	
	int aux = v[p-1];
	v[p-1] = v[p];
	v[p] = aux;


	f(p-1);
	return;
}

void f2(int p){

	if(p == 1){
		return; 
	}
	
	f2(p-1);
	int aux = v[p-1];
	v[p-1] = v[p];
	v[p] = aux;


	return;
}
int main(){
	

	cin >> n;

	for(int i = 1; i <= n; i++){
		v[i] = i;
	}

	f(n);

	for(int i = 1; i <= n; i++)
		cout << v[i] << " ";
	cout << endl;

	


}
