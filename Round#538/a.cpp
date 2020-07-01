/*https://codeforces.com/contest/1114/problem/A*/
#include <bits/stdc++.h>
using namespace std;

int x, y, z, a, b, c;


int main(){


	cin >> x >> y >> z >> a >> b >> c;
	int total = a + b + c;

	if(a - x >= 0){
		a = a - x;
		b += a;
		if(b >= y){
			b -= y;
			c += b;
			if(c >= z){
				cout << "YES" << endl;
				return 0;
			}
		}
	}

cout << "NO" << endl;
return 0;
}