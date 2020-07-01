/*https://codeforces.com/problemset/problem/630/C*/
#include <bits/stdc++.h>
using namespace std;

int n;
long long int res;

int main(){

	cin >> n;

	res = 1;
	for(int i = 0; i < n-1; i++)	
		res = (res << 1) + 1;

	res = res << 1;

	cout << res << endl;
return 0;
}







