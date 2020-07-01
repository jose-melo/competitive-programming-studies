#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	long long int res = 0;

	cin >> n;
	
	for(int i = n-1; i > 0; i--)
		res += i*(n-i);

	res += n;

	cout << res << endl;

return 0;
}


