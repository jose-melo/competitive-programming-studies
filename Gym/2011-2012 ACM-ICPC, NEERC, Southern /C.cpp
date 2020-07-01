#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

	ll n;

	cin >> n;

	if(n < 21){
		cout << -1 << "\n";
		return 0;
	}

	if(n == 21){
		cout << -1 << "\n";
		return 0;
	}

	ll mod = n % 14;
	n = n / 14;

	if(mod <= 12 && mod > 1 && n != 1)
		cout << n << "\n";
	else
		cout << -1 << "\n";

return 0;
}