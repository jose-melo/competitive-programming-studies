#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)


int main(){

	int a;

	cin >> a;

	for(int bit = 0; bit < log2(a); bit++){
		if(a & (1<<bit)){
			cout << "NO!" << endl;
			return 0;
		}
	}

	cout << "YES!" << endl;

	
return 0;
}

