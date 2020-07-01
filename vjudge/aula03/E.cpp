/*https://codeforces.com/problemset/problem/1108/B*/
#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int num[150];

int main(){

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	y = num[n-1];

	for(int i = n-2; i >= 0; i--){
		if(num[i] == num[i+1] || (y % num[i]) != 0){
			x = num[i];
			break;
		}
	}

	cout << x << " " <<  y << endl;
return 0;
}


