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

int v[212345];
int n;

int main(){

	cin >> n;

	int aux;
	string s;

	cin >> s;

	FI(n){
		aux = s[i] - '0';
		if(aux == 0)
			aux = -1;
		v[i] = aux;
	}

	int soma = 0;
	
	FI(n)
		soma += v[i];
	
	cout << abs(soma) << "\n";
return 0;
}





