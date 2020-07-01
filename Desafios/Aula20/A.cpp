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

int main(){

	int n;

	cin >> n;

	if(n == 4){
		cout << "4\n";
		cout << "3 1 4 2\n";
		return 0;
	}

	if(n == 3){
		cout << "2\n";
		cout << "1 3\n";
		return 0;
	}

	if(n == 2 || n == 1){
		cout << "1\n";
		cout << "1\n";
		return 0;
	}

	cout << n << "\n";
	for(int i = 1; i <= n; i += 2)
		cout << i << " ";

	for(int i = 2; i <= n; i += 2)
		cout << i << " ";

	cout << "\n";
return 0;
}




