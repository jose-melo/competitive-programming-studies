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


int main(){

	int n, aux;
	cin >> n;

	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		cin >> aux;

		if(aux == 5)
			a++;
		else
			b++;
	}


	if(a<9 && b >= 1){
		cout << "0\n";
		return 0;
	}

	if(b < 1){
		cout << "-1\n";
		return 0;

	}


	a = a - (a%9);
	for(int i = 0; i < a; i++)
		cout << "5";

	for(int i = 0; i < b; i++)
		cout << "0";

	cout << endl;
	


}
