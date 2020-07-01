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


queue<int> fila;

int main(){


	int n, k;
	cin >> n >> k;

	if(k > n){
		cout << "NO\n";
		return 0;
	}

	int aux;
	FOR(i, 0, log2(n)+1){
		if(n & (1<<i)){
			fila.push((1<<i));
		}
	}

	if(k < fila.size()){
		cout << "NO\n";
		return 0;
	}
	while(fila.size() != k){
		int num = fila.front();
		fila.pop();
		if(num % 2 == 0){
			fila.push(num/2);
			fila.push(num/2);
		}else{fila.push(num);}

	}

	int x;
	cout << "YES\n";
	while(!fila.empty()){
		x = fila.front();
		fila.pop();
		cout << x << " ";
	}
	cout << "\n";
return 0;
}

