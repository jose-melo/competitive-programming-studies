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

int x, y, h, w, a, b;
string s, op;
/*
void analisa(){

	string a1 = s.split(0, 1);
	string a2 = s.split(2, 1);
	string a3 = s.split(4, 1);
	
	cout << a1 << " " << a2 << " " << a3 << endl;

	if(a1 == '+')
		op = 1;
	if(a1 == '?')
		op = 2;

	cout << op << " " << x << " " << y << endl;
return;
}*/


int main(){

	fastio;

	int n;

	cin >> n;

	a = -1;
	b = -1;

	FI(n){
	
		cin >> op >> x >> y;	
	
//		cout << op << " " << x << " " << y << endl;

		if(x < y){
			int aux = y;
			y = x;
			x = aux;
		}
		
		if(op[0] == '+'){	
			a = max(a, x);
			b = max(b, y);
		}
	
		if(op[0] == '?'){
			if(a <= x && b <= y)		
				cout << "YES\n";
			else
				cout << "NO\n";
		}

	}
	


}


