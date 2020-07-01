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
#define pb push_back

int main(){

	string s;

	cin >> s;

	int cont1 = 0, cont2 = 0;
	int e = 1;

	for(int i = 0; i < s.size(); i++){
		if(s[i] != (e + '0'))
			cont1++;
		e ^= 1;

	}

	e = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != (e+'0'))
			cont2++;
		e ^= 1;
	}

	int resp = min(cont1, cont2);

	cout << resp << endl;
return 0;
}

