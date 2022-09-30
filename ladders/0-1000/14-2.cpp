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
vector<int> v1, v2;

int main(){

	cin >> n;

	int aux;
	FI(n){
		cin >> aux;
		v2.pb(aux);
		v1.pb(aux);
	}
	
	sort(v1.begin(), v1.end());


	int cont = 0;
	for(int i = 0; i < n; i++){
		if(v2[i] == v1[n-1]){
			cont += i;
			break;
		}	
	}


	for(int j = n-1; j >= 0; j--){
		if(v2[j] == v1[0]){
	
			if(j < cont)
				cont--;
			cont += n - j-1;
			break;
		}
	}

	cout << cont << endl;


}
