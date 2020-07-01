#include <bits/stdc++.h>
using namespace std;


int n, k;

int main(){

	cin >> n >> k;


	double red, green, blue;

	red = 2*n;
	green = 5*n;
	blue = 8*n;

	int res = ceil(blue/k)+ceil(green/k)+ceil(red/k);

	cout << res << "\n";
return 0;
}