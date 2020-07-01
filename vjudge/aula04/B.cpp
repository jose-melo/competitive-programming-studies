/*https://codeforces.com/problemset/problem/224/A*/
#include <bits/stdc++.h>
using namespace std;

int main(){

	int x, y, z, a, b, c;

	cin >> x >> y >> z;

	b = sqrt((x*z) /  y);
	a = x / b;
	c = (b*y)/x;

	cout << 4*(a + b + c) << endl;
return 0;
}



