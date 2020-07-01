#include <bits/stdc++.h>
using namespace std;


int main(){

	int n, k, l, c, d, p, nl, np;

	cin >> n >> k >> l >> c >> d >> p >> nl >> np;

	int num_drink = (k*l) / nl;
	int num_slices = c*d;
	int num_salt = p / np;

	int num = min(num_drink, min(num_salt, num_slices));
	int res = num / n;
	cout << res << endl;
return 0;
}